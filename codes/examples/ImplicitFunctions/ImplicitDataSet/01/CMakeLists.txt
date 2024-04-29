
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ImplicitDataSet)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  ImagingCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ImplicitDataSet: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ImplicitDataSet MACOSX_BUNDLE ImplicitDataSet.cxx )
  target_link_libraries(ImplicitDataSet PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ImplicitDataSet
  MODULES ${VTK_LIBRARIES}
)
