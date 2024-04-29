
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ImageDataToPointSet)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersGeneral
  IOXML
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ImageDataToPointSet: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ImageDataToPointSet MACOSX_BUNDLE ImageDataToPointSet.cxx )
  target_link_libraries(ImageDataToPointSet PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ImageDataToPointSet
  MODULES ${VTK_LIBRARIES}
)
