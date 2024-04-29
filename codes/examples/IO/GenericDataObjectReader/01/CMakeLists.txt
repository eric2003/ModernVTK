
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(GenericDataObjectReader)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  IOLegacy
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "GenericDataObjectReader: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(GenericDataObjectReader MACOSX_BUNDLE GenericDataObjectReader.cxx )
  target_link_libraries(GenericDataObjectReader PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS GenericDataObjectReader
  MODULES ${VTK_LIBRARIES}
)
