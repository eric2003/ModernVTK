
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(CardinalSpline)

find_package(VTK COMPONENTS 
  CommonComputationalGeometry
  CommonCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "CardinalSpline: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(CardinalSpline MACOSX_BUNDLE CardinalSpline.cxx )
  target_link_libraries(CardinalSpline PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS CardinalSpline
  MODULES ${VTK_LIBRARIES}
)
