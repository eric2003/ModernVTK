
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(GenerateModelsFromLabels)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersCore
  FiltersGeneral
  FiltersGeometry
  IOImage
  IOXML
  ImagingStatistics
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "GenerateModelsFromLabels: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(GenerateModelsFromLabels MACOSX_BUNDLE GenerateModelsFromLabels.cxx )
  target_link_libraries(GenerateModelsFromLabels PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS GenerateModelsFromLabels
  MODULES ${VTK_LIBRARIES}
)
