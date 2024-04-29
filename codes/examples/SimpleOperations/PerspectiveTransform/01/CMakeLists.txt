
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(PerspectiveTransform)

find_package(VTK COMPONENTS 
  CommonCore
  CommonMath
  CommonTransforms
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "PerspectiveTransform: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(PerspectiveTransform MACOSX_BUNDLE PerspectiveTransform.cxx )
  target_link_libraries(PerspectiveTransform PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS PerspectiveTransform
  MODULES ${VTK_LIBRARIES}
)
