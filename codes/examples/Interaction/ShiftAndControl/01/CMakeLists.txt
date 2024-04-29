
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ShiftAndControl)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersSources
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ShiftAndControl: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ShiftAndControl MACOSX_BUNDLE ShiftAndControl.cxx )
  target_link_libraries(ShiftAndControl PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ShiftAndControl
  MODULES ${VTK_LIBRARIES}
)
