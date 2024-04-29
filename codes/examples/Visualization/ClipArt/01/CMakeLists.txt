
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ClipArt)

find_package(VTK COMPONENTS 
  CommonCore
  CommonExecutionModel
  FiltersCore
  FiltersGeometry
  FiltersModeling
  FiltersTexture
  IOImage
  ImagingColor
  ImagingCore
  ImagingGeneral
  ImagingMorphological
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ClipArt: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ClipArt MACOSX_BUNDLE ClipArt.cxx )
  target_link_libraries(ClipArt PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ClipArt
  MODULES ${VTK_LIBRARIES}
)
