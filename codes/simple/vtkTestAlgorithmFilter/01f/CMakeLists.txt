
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(AlgorithmFilter)

find_package(VTK COMPONENTS 
CommonComputationalGeometry
FiltersCore
CommonExecutionModel
CommonDataModel
CommonSystem
CommonMisc
exprtk
CommonTransforms
CommonMath
CommonCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "AlgorithmFilter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
#add_executable(AlgorithmFilter MACOSX_BUNDLE AlgorithmFilter.cxx )
add_executable(AlgorithmFilter MACOSX_BUNDLE
        AlgorithmFilter.cxx
		vtkTest.h vtkTest.cxx
		vtkTestAlgorithmFilter.h vtkTestAlgorithmFilter.cxx	
)

target_link_libraries(AlgorithmFilter PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS AlgorithmFilter
  MODULES ${VTK_LIBRARIES}
)
