
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(XMLStructuredGridWriter)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  IOXML
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "XMLStructuredGridWriter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(XMLStructuredGridWriter MACOSX_BUNDLE XMLStructuredGridWriter.cxx )
  target_link_libraries(XMLStructuredGridWriter PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS XMLStructuredGridWriter
  MODULES ${VTK_LIBRARIES}
)
