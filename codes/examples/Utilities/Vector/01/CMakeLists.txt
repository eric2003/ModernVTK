
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Vector)

find_package(VTK COMPONENTS 
  CommonDataModel
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "Vector: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(Vector MACOSX_BUNDLE Vector.cxx )
  target_link_libraries(Vector PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS Vector
  MODULES ${VTK_LIBRARIES}
)
