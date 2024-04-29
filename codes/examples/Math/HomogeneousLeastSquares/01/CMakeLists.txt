
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(HomogeneousLeastSquares)

find_package(VTK COMPONENTS 
  CommonCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "HomogeneousLeastSquares: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(HomogeneousLeastSquares MACOSX_BUNDLE HomogeneousLeastSquares.cxx )
  target_link_libraries(HomogeneousLeastSquares PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS HomogeneousLeastSquares
  MODULES ${VTK_LIBRARIES}
)
