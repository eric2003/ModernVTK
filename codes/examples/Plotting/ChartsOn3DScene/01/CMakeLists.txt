
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ChartsOn3DScene)

find_package(VTK COMPONENTS 
  ChartsCore
  CommonColor
  CommonCore
  CommonDataModel
  FiltersSources
  InteractionStyle
  RenderingContext2D
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ChartsOn3DScene: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ChartsOn3DScene MACOSX_BUNDLE ChartsOn3DScene.cxx )
  target_link_libraries(ChartsOn3DScene PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ChartsOn3DScene
  MODULES ${VTK_LIBRARIES}
)
