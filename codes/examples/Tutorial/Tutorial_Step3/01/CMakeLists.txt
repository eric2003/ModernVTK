
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Tutorial_Step3)

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
  message(FATAL_ERROR "Tutorial_Step3: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(Tutorial_Step3 MACOSX_BUNDLE Tutorial_Step3.cxx )
  target_link_libraries(Tutorial_Step3 PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS Tutorial_Step3
  MODULES ${VTK_LIBRARIES}
)
