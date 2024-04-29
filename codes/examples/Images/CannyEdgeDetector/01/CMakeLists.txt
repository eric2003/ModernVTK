
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(CannyEdgeDetector)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonExecutionModel
  FiltersCore
  FiltersGeneral
  FiltersGeometry
  IOImage
  ImagingColor
  ImagingCore
  ImagingGeneral
  ImagingMath
  ImagingMorphological
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "CannyEdgeDetector: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(CannyEdgeDetector MACOSX_BUNDLE CannyEdgeDetector.cxx )
  target_link_libraries(CannyEdgeDetector PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS CannyEdgeDetector
  MODULES ${VTK_LIBRARIES}
)
