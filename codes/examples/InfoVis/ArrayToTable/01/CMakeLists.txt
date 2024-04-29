
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ArrayToTable)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  InfovisCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ArrayToTable: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ArrayToTable MACOSX_BUNDLE ArrayToTable.cxx )
  target_link_libraries(ArrayToTable PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ArrayToTable
  MODULES ${VTK_LIBRARIES}
)
