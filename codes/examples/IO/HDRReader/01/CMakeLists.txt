
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(HDRReader)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  IOImage
  InteractionImage
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "HDRReader: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(HDRReader MACOSX_BUNDLE HDRReader.cxx )
  target_link_libraries(HDRReader PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS HDRReader
  MODULES ${VTK_LIBRARIES}
)
