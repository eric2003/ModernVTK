
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(MinIntensityRendering)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  IOLegacy
  ImagingCore
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  RenderingVolume
  RenderingVolumeOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "MinIntensityRendering: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(MinIntensityRendering MACOSX_BUNDLE MinIntensityRendering.cxx )
  target_link_libraries(MinIntensityRendering PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS MinIntensityRendering
  MODULES ${VTK_LIBRARIES}
)
