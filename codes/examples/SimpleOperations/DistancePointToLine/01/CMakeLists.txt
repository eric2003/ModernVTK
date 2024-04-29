
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(DistancePointToLine)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "DistancePointToLine: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(DistancePointToLine MACOSX_BUNDLE DistancePointToLine.cxx )
  target_link_libraries(DistancePointToLine PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS DistancePointToLine
  MODULES ${VTK_LIBRARIES}
)
