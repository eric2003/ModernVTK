
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(MatlabEngineFilter)

find_package(VTK COMPONENTS 
  CommonCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "MatlabEngineFilter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(MatlabEngineFilter MACOSX_BUNDLE MatlabEngineFilter.cxx )
  target_link_libraries(MatlabEngineFilter PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS MatlabEngineFilter
  MODULES ${VTK_LIBRARIES}
)
