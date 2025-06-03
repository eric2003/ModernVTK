
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(VectorDot)

set ( VTK_DIR "c:/dev/VTK_debug/lib/cmake/vtk-9.4/" )
#set ( VTK_DIR "c:/dev/VTK/lib/cmake/vtk-9.4/" )

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersCore
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "VectorDot: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(VectorDot MACOSX_BUNDLE VectorDot.cxx )
  target_link_libraries(VectorDot PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS VectorDot
  MODULES ${VTK_LIBRARIES}
)
