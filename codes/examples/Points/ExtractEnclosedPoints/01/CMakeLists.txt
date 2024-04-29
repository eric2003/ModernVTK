
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ExtractEnclosedPoints)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersPoints
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
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ExtractEnclosedPoints: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ExtractEnclosedPoints MACOSX_BUNDLE ExtractEnclosedPoints.cxx )
  target_link_libraries(ExtractEnclosedPoints PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ExtractEnclosedPoints
  MODULES ${VTK_LIBRARIES}
)
