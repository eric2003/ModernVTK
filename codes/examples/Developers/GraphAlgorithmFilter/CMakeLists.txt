
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(GraphAlgorithmFilter)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "GraphAlgorithmFilter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")

add_executable(GraphAlgorithmFilter MACOSX_BUNDLE
 GraphAlgorithmFilter.cxx
 vtkTestGraphAlgorithmFilter.cxx
)

target_link_libraries(GraphAlgorithmFilter PRIVATE ${VTK_LIBRARIES}
)

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS GraphAlgorithmFilter
  MODULES ${VTK_LIBRARIES}
)
