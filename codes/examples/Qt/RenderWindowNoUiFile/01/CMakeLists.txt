
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(RenderWindowNoUiFile)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGL)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)

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
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "RenderWindowNoUiFile: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(RenderWindowNoUiFile MACOSX_BUNDLE RenderWindowNoUiFile.cxx )
  target_link_libraries(RenderWindowNoUiFile PRIVATE ${VTK_LIBRARIES}
)

target_link_libraries(RenderWindowNoUiFile PRIVATE Qt6::Core)
target_link_libraries(RenderWindowNoUiFile PRIVATE Qt6::Gui)
target_link_libraries(RenderWindowNoUiFile PRIVATE Qt6::Widgets)
target_link_libraries(RenderWindowNoUiFile PRIVATE Qt6::OpenGL)
target_link_libraries(RenderWindowNoUiFile PRIVATE Qt6::OpenGLWidgets)

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS RenderWindowNoUiFile
  MODULES ${VTK_LIBRARIES}
)
