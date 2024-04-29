
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ReadLegacyUnstructuredGrid)

find_package(VTK COMPONENTS 
  ChartsCore
  CommonColor
  CommonCore
  CommonDataModel
  FiltersCore
  FiltersGeneral
  FiltersSources
  IOLegacy
  InteractionStyle
  RenderingContext2D
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingLabel
  RenderingOpenGL2
  ViewsContext2D
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ReadLegacyUnstructuredGrid: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ReadLegacyUnstructuredGrid MACOSX_BUNDLE ReadLegacyUnstructuredGrid.cxx )
  target_link_libraries(ReadLegacyUnstructuredGrid PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ReadLegacyUnstructuredGrid
  MODULES ${VTK_LIBRARIES}
)
