
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(2DArray)

find_package(VTK COMPONENTS 
  CommonCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "2DArray: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(2DArray MACOSX_BUNDLE 2DArray.cxx )
  target_link_libraries(2DArray PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS 2DArray
  MODULES ${VTK_LIBRARIES}
)
