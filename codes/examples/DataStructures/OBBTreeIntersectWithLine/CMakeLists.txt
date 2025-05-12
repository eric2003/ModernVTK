
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(OBBTreeIntersectWithLine)

find_package(VTK COMPONENTS 
  CommonCore
  FiltersGeneral
  FiltersSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "OBBTreeIntersectWithLine: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(OBBTreeIntersectWithLine MACOSX_BUNDLE OBBTreeIntersectWithLine.cxx )
  target_link_libraries(OBBTreeIntersectWithLine PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS OBBTreeIntersectWithLine
  MODULES ${VTK_LIBRARIES}
)
