
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(PseudoVolumeRendering)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  FiltersCore
  FiltersExtraction
  IOParallel
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "PseudoVolumeRendering: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(PseudoVolumeRendering MACOSX_BUNDLE PseudoVolumeRendering.cxx )
  target_link_libraries(PseudoVolumeRendering PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS PseudoVolumeRendering
  MODULES ${VTK_LIBRARIES}
)
