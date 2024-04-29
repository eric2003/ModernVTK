
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(LUTUtilities)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "LUTUtilities: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(LUTUtilities MACOSX_BUNDLE LUTUtilities.cxx )
  target_link_libraries(LUTUtilities PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS LUTUtilities
  MODULES ${VTK_LIBRARIES}
)
