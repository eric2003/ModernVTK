
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ColorLookupTable)

find_package(VTK COMPONENTS 
  CommonCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ColorLookupTable: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ColorLookupTable MACOSX_BUNDLE ColorLookupTable.cxx )
  target_link_libraries(ColorLookupTable PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ColorLookupTable
  MODULES ${VTK_LIBRARIES}
)
