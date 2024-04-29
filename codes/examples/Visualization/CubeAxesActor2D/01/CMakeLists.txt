
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(CubeAxesActor2D)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersCore
  FiltersModeling
  FiltersSources
  InteractionStyle
  RenderingAnnotation
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingLOD
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "CubeAxesActor2D: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(CubeAxesActor2D MACOSX_BUNDLE CubeAxesActor2D.cxx )
  target_link_libraries(CubeAxesActor2D PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS CubeAxesActor2D
  MODULES ${VTK_LIBRARIES}
)
