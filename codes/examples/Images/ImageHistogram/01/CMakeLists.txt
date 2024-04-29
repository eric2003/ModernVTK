
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ImageHistogram)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  IOImage
  ImagingStatistics
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ImageHistogram: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ImageHistogram MACOSX_BUNDLE ImageHistogram.cxx )
  target_link_libraries(ImageHistogram PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ImageHistogram
  MODULES ${VTK_LIBRARIES}
)
