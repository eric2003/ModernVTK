
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(LabelVerticesAndEdges)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  InfovisLayout
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  ViewsInfovis
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "LabelVerticesAndEdges: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(LabelVerticesAndEdges MACOSX_BUNDLE LabelVerticesAndEdges.cxx )
  target_link_libraries(LabelVerticesAndEdges PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS LabelVerticesAndEdges
  MODULES ${VTK_LIBRARIES}
)
