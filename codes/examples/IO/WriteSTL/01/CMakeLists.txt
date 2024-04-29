
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(WriteSTL)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersSources
  IOGeometry
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "WriteSTL: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(WriteSTL MACOSX_BUNDLE WriteSTL.cxx )
  target_link_libraries(WriteSTL PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS WriteSTL
  MODULES ${VTK_LIBRARIES}
)
