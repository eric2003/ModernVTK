
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(MPEG2)

find_package(VTK COMPONENTS 
  CommonCore
  ImagingSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "MPEG2: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(MPEG2 MACOSX_BUNDLE MPEG2.cxx )
  target_link_libraries(MPEG2 PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS MPEG2
  MODULES ${VTK_LIBRARIES}
)
