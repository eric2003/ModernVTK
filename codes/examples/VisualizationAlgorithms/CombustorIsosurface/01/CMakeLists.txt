
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(CombustorIsosurface)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  FiltersCore
  IOParallel
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "CombustorIsosurface: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(CombustorIsosurface MACOSX_BUNDLE CombustorIsosurface.cxx )
  target_link_libraries(CombustorIsosurface PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS CombustorIsosurface
  MODULES ${VTK_LIBRARIES}
)
