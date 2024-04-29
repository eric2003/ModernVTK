
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ReadPDB)

find_package(VTK COMPONENTS 
  CommonColor
  FiltersCore
  FiltersSources
  IOChemistry
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingLOD
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ReadPDB: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ReadPDB MACOSX_BUNDLE ReadPDB.cxx )
  target_link_libraries(ReadPDB PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ReadPDB
  MODULES ${VTK_LIBRARIES}
)
