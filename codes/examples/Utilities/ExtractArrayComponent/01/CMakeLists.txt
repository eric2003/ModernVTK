
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ExtractArrayComponent)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ExtractArrayComponent: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ExtractArrayComponent MACOSX_BUNDLE ExtractArrayComponent.cxx )
  target_link_libraries(ExtractArrayComponent PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ExtractArrayComponent
  MODULES ${VTK_LIBRARIES}
)
