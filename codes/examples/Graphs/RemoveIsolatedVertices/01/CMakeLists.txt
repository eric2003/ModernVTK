
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(RemoveIsolatedVertices)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  InfovisCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "RemoveIsolatedVertices: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(RemoveIsolatedVertices MACOSX_BUNDLE RemoveIsolatedVertices.cxx )
  target_link_libraries(RemoveIsolatedVertices PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS RemoveIsolatedVertices
  MODULES ${VTK_LIBRARIES}
)
