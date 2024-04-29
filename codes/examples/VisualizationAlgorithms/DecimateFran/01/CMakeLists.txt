
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(DecimateFran)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersCore
  IOImage
  IOLegacy
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "DecimateFran: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(DecimateFran MACOSX_BUNDLE DecimateFran.cxx )
  target_link_libraries(DecimateFran PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS DecimateFran
  MODULES ${VTK_LIBRARIES}
)
