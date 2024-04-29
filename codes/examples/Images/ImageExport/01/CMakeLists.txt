
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ImageExport)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  IOImage
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ImageExport: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ImageExport MACOSX_BUNDLE ImageExport.cxx )
  target_link_libraries(ImageExport PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ImageExport
  MODULES ${VTK_LIBRARIES}
)
