
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(KDTreeFindPointsWithinRadius)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "KDTreeFindPointsWithinRadius: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(KDTreeFindPointsWithinRadius MACOSX_BUNDLE KDTreeFindPointsWithinRadius.cxx )
  target_link_libraries(KDTreeFindPointsWithinRadius PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS KDTreeFindPointsWithinRadius
  MODULES ${VTK_LIBRARIES}
)
