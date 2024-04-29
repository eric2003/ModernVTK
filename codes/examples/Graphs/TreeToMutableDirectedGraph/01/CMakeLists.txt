
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(TreeToMutableDirectedGraph)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "TreeToMutableDirectedGraph: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(TreeToMutableDirectedGraph MACOSX_BUNDLE TreeToMutableDirectedGraph.cxx )
  target_link_libraries(TreeToMutableDirectedGraph PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS TreeToMutableDirectedGraph
  MODULES ${VTK_LIBRARIES}
)
