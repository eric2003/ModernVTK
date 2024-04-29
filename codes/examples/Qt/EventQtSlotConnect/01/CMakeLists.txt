
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

if(POLICY CMP0020)
  cmake_policy(SET CMP0020 NEW)
  cmake_policy(SET CMP0071 NEW)
endif()

PROJECT(EventQtSlotConnect)

set(qt_components Core Gui Widgets)
list(APPEND qt_components OpenGLWidgets)

list(SORT qt_components)
find_package(Qt6 REQUIRED COMPONENTS ${qt_components})

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersSources
  GUISupportQt
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  GUISupportQt
  RenderingQt
)

if(NOT VTK_FOUND)
  message(FATAL_ERROR "EventQtSlotConnect: Unable to find the VTK build folder.")
endif()

if(NOT(TARGET VTK::GUISupportQt))
  message(FATAL_ERROR "EventQtSlotConnect: VTK not built with Qt support.")
endif()

foreach(_qt_comp IN LISTS qt_components)
  list(APPEND qt_modules "Qt${VTK_QT_VERSION}::${_qt_comp}")
endforeach()

message (STATUS "VTK_VERSION: ${VTK_VERSION}, Qt Version: ${Qt${VTK_QT_VERSION}Widgets_VERSION}")

# Instruct CMake to run moc and uic automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB UI_FILES *.ui)
file(GLOB QT_WRAP *.h)
file(GLOB CXX_FILES *.cxx)

# For VTK versions greater than or equal to 8.90.0:
#  CMAKE_AUTOUIC is ON so we handle uic automatically for Qt targets.
#  CMAKE_AUTOMOC is ON so we handle moc automatically for Qt targets.

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
# CMAKE_AUTOMOC in ON so the MOC headers will be automatically wrapped.
add_executable(EventQtSlotConnect MACOSX_BUNDLE
  ${CXX_FILES} ${UISrcs} ${QT_WRAP}
)
if (Qt${VTK_QT_VERSION}Widgets_VERSION VERSION_LESS "5.11.0")
  qt5_use_modules(EventQtSlotConnect ${qt_components})
else()
  target_link_libraries(EventQtSlotConnect ${qt_modules})
endif()
target_link_libraries(EventQtSlotConnect ${VTK_LIBRARIES})
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS EventQtSlotConnect
  MODULES ${VTK_LIBRARIES}
)
