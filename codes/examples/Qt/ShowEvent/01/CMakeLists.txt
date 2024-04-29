
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ShowEvent)

set(qt_components Core Gui Widgets Sql)
list(APPEND qt_components OpenGLWidgets)

list(SORT qt_components)
find_package(Qt6 REQUIRED COMPONENTS ${qt_components})

find_package(VTK COMPONENTS 
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ShowEvent: Unable to find the VTK build folder.")
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

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
#add_executable(ShowEvent MACOSX_BUNDLE ShowEvent.cxx )
add_executable(ShowEvent MACOSX_BUNDLE 
  ${CXX_FILES} ${UISrcs} ${QT_WRAP}
)
  target_link_libraries(ShowEvent PRIVATE ${VTK_LIBRARIES}
)

target_link_libraries(ShowEvent PRIVATE ${qt_modules})
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ShowEvent
  MODULES ${VTK_LIBRARIES}
)
