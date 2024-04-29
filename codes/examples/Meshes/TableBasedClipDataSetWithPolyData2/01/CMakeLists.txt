
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(TableBasedClipDataSetWithPolyData2)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  CommonExecutionModel
  FiltersGeneral
  ImagingCore
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "TableBasedClipDataSetWithPolyData2: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(TableBasedClipDataSetWithPolyData2 MACOSX_BUNDLE TableBasedClipDataSetWithPolyData2.cxx )
  target_link_libraries(TableBasedClipDataSetWithPolyData2 PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS TableBasedClipDataSetWithPolyData2
  MODULES ${VTK_LIBRARIES}
)
