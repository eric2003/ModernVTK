
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(CurvatureBandsWithGlyphs)

find_package(VTK COMPONENTS 
  CommonColor
  CommonComputationalGeometry
  CommonCore
  CommonDataModel
  CommonTransforms
  FiltersCore
  FiltersGeneral
  FiltersModeling
  FiltersSources
  InteractionStyle
  InteractionWidgets
  RenderingAnnotation
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "CurvatureBandsWithGlyphs: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(CurvatureBandsWithGlyphs MACOSX_BUNDLE CurvatureBandsWithGlyphs.cxx )
  target_link_libraries(CurvatureBandsWithGlyphs PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS CurvatureBandsWithGlyphs
  MODULES ${VTK_LIBRARIES}
)
