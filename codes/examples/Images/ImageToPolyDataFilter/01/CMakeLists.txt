
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ImageToPolyDataFilter)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersCore
  FiltersHybrid
  IOImage
  ImagingColor
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ImageToPolyDataFilter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ImageToPolyDataFilter MACOSX_BUNDLE ImageToPolyDataFilter.cxx )
  target_link_libraries(ImageToPolyDataFilter PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ImageToPolyDataFilter
  MODULES ${VTK_LIBRARIES}
)
