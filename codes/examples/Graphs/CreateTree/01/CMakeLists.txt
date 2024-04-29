
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(CreateTree)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  ViewsCore
  ViewsInfovis
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "CreateTree: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(CreateTree MACOSX_BUNDLE CreateTree.cxx )
  target_link_libraries(CreateTree PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS CreateTree
  MODULES ${VTK_LIBRARIES}
)
