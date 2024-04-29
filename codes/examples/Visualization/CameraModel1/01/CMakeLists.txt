
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(CameraModel1)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  CommonTransforms
  FiltersCore
  FiltersGeneral
  FiltersHybrid
  FiltersModeling
  FiltersSources
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingLOD
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "CameraModel1: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(CameraModel1 MACOSX_BUNDLE CameraModel1.cxx )
  target_link_libraries(CameraModel1 PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS CameraModel1
  MODULES ${VTK_LIBRARIES}
)
