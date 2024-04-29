
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(UnknownLengthArray)

find_package(VTK COMPONENTS 
  CommonCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "UnknownLengthArray: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(UnknownLengthArray MACOSX_BUNDLE UnknownLengthArray.cxx )
  target_link_libraries(UnknownLengthArray PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS UnknownLengthArray
  MODULES ${VTK_LIBRARIES}
)
