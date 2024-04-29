
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(PNGWriter)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  IOImage
  ImagingCore
  ImagingSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "PNGWriter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(PNGWriter MACOSX_BUNDLE PNGWriter.cxx )
  target_link_libraries(PNGWriter PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS PNGWriter
  MODULES ${VTK_LIBRARIES}
)
