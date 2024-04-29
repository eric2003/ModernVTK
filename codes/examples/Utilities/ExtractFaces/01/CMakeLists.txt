
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ExtractFaces)

find_package(VTK COMPONENTS 
  CommonDataModel
  IOXML
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ExtractFaces: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ExtractFaces MACOSX_BUNDLE ExtractFaces.cxx )
  target_link_libraries(ExtractFaces PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ExtractFaces
  MODULES ${VTK_LIBRARIES}
)
