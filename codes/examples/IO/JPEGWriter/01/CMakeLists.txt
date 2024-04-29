
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(JPEGWriter)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  IOImage
  ImagingSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "JPEGWriter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(JPEGWriter MACOSX_BUNDLE JPEGWriter.cxx )
  target_link_libraries(JPEGWriter PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS JPEGWriter
  MODULES ${VTK_LIBRARIES}
)
