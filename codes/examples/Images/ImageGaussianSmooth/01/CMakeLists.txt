
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ImageGaussianSmooth)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  ImagingGeneral
  ImagingSources
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ImageGaussianSmooth: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ImageGaussianSmooth MACOSX_BUNDLE ImageGaussianSmooth.cxx )
  target_link_libraries(ImageGaussianSmooth PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ImageGaussianSmooth
  MODULES ${VTK_LIBRARIES}
)
