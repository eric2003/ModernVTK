
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(FilterProgress)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "FilterProgress: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")

add_executable(FilterProgress MACOSX_BUNDLE
 FilterProgress.cxx
 A.cxx
)

target_link_libraries(FilterProgress PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS FilterProgress
  MODULES ${VTK_LIBRARIES}
)
