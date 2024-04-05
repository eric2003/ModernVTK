
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(KDTreeAccessPoints)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersGeneral
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "KDTreeAccessPoints: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(KDTreeAccessPoints MACOSX_BUNDLE KDTreeAccessPoints.cxx )
  target_link_libraries(KDTreeAccessPoints PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS KDTreeAccessPoints
  MODULES ${VTK_LIBRARIES}
)
