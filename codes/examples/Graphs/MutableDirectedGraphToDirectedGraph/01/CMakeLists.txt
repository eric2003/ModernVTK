
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(MutableDirectedGraphToDirectedGraph)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "MutableDirectedGraphToDirectedGraph: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(MutableDirectedGraphToDirectedGraph MACOSX_BUNDLE MutableDirectedGraphToDirectedGraph.cxx )
  target_link_libraries(MutableDirectedGraphToDirectedGraph PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS MutableDirectedGraphToDirectedGraph
  MODULES ${VTK_LIBRARIES}
)
