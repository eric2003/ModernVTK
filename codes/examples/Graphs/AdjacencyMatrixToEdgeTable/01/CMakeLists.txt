
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(AdjacencyMatrixToEdgeTable)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  InfovisCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "AdjacencyMatrixToEdgeTable: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(AdjacencyMatrixToEdgeTable MACOSX_BUNDLE AdjacencyMatrixToEdgeTable.cxx )
  target_link_libraries(AdjacencyMatrixToEdgeTable PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS AdjacencyMatrixToEdgeTable
  MODULES ${VTK_LIBRARIES}
)
