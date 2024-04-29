
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(MassProperties)

find_package(VTK COMPONENTS 
  CommonCore
  FiltersCore
  FiltersModeling
  FiltersSources
  IOGeometry
  IOLegacy
  IOPLY
  IOXML
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "MassProperties: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(MassProperties MACOSX_BUNDLE MassProperties.cxx )
  target_link_libraries(MassProperties PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS MassProperties
  MODULES ${VTK_LIBRARIES}
)
