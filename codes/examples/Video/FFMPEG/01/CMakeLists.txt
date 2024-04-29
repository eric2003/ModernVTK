
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(FFMPEG)

find_package(VTK COMPONENTS 
  CommonCore
  IOFFMPEG
  ImagingSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "FFMPEG: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(FFMPEG MACOSX_BUNDLE FFMPEG.cxx )
  target_link_libraries(FFMPEG PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS FFMPEG
  MODULES ${VTK_LIBRARIES}
)
