
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ImageReader2Factory)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  IOImage
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ImageReader2Factory: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ImageReader2Factory MACOSX_BUNDLE ImageReader2Factory.cxx )
  target_link_libraries(ImageReader2Factory PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ImageReader2Factory
  MODULES ${VTK_LIBRARIES}
)
