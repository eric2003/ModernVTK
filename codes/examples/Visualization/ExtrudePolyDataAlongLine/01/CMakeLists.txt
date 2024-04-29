
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ExtrudePolyDataAlongLine)

find_package(VTK COMPONENTS 
  CommonComputationalGeometry
  CommonCore
  CommonDataModel
  CommonMath
  CommonTransforms
  FiltersCore
  FiltersGeneral
  FiltersModeling
  FiltersSources
  IOGeometry
  IOLegacy
  IOPLY
  IOXML
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  SplineDrivenImageSlicer
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ExtrudePolyDataAlongLine: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ExtrudePolyDataAlongLine MACOSX_BUNDLE ExtrudePolyDataAlongLine.cxx )
  target_link_libraries(ExtrudePolyDataAlongLine PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ExtrudePolyDataAlongLine
  MODULES ${VTK_LIBRARIES}
)
