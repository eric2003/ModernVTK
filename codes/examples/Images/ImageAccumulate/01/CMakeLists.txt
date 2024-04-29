
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ImageAccumulate)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  ImagingStatistics
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ImageAccumulate: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ImageAccumulate MACOSX_BUNDLE ImageAccumulate.cxx )
  target_link_libraries(ImageAccumulate PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ImageAccumulate
  MODULES ${VTK_LIBRARIES}
)
