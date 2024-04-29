
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ImageOpenClose3D)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  IOImage
  ImagingMorphological
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ImageOpenClose3D: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ImageOpenClose3D MACOSX_BUNDLE ImageOpenClose3D.cxx )
  target_link_libraries(ImageOpenClose3D PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ImageOpenClose3D
  MODULES ${VTK_LIBRARIES}
)
