
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(SimplePointsWriter)

find_package(VTK COMPONENTS 
  CommonCore
  FiltersSources
  IOLegacy
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "SimplePointsWriter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(SimplePointsWriter MACOSX_BUNDLE SimplePointsWriter.cxx )
  target_link_libraries(SimplePointsWriter PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS SimplePointsWriter
  MODULES ${VTK_LIBRARIES}
)
