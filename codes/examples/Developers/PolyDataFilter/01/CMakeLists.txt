
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(PolyDataFilter)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  CommonExecutionModel
  FiltersSources
  InfovisCore  
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "PolyDataFilter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")

add_executable(PolyDataFilter MACOSX_BUNDLE
 PolyDataFilter.cxx
 vtkTestPolyDataFilter.cxx
)

target_link_libraries(PolyDataFilter PRIVATE ${VTK_LIBRARIES}
)

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS PolyDataFilter
  MODULES ${VTK_LIBRARIES}
)
