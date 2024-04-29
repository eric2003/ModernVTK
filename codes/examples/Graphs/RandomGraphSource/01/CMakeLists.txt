
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(RandomGraphSource)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  InfovisCore
  InfovisLayout
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  ViewsInfovis
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "RandomGraphSource: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(RandomGraphSource MACOSX_BUNDLE RandomGraphSource.cxx )
  target_link_libraries(RandomGraphSource PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS RandomGraphSource
  MODULES ${VTK_LIBRARIES}
)
