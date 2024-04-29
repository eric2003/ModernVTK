
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(FindAllArrayNames)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersSources
  IOXML
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "FindAllArrayNames: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(FindAllArrayNames MACOSX_BUNDLE FindAllArrayNames.cxx )
  target_link_libraries(FindAllArrayNames PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS FindAllArrayNames
  MODULES ${VTK_LIBRARIES}
)
