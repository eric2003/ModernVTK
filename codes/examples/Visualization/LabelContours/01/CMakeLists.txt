
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(LabelContours)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  FiltersCore
  FiltersSources
  IOXML
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingLabel
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "LabelContours: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(LabelContours MACOSX_BUNDLE LabelContours.cxx )
  target_link_libraries(LabelContours PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS LabelContours
  MODULES ${VTK_LIBRARIES}
)
