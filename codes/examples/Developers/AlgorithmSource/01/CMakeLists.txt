
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(AlgorithmSource)

find_package(VTK COMPONENTS 
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "AlgorithmSource: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")

add_executable(AlgorithmSource MACOSX_BUNDLE
 AlgorithmSource.cxx
 vtkTestAlgorithmSource.cxx
 vtkTest1.cxx
)

target_link_libraries(AlgorithmSource PRIVATE ${VTK_LIBRARIES}
)

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS AlgorithmSource
  MODULES ${VTK_LIBRARIES}
)
