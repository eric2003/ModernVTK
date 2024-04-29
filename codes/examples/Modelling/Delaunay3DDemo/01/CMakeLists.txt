
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Delaunay3DDemo)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  FiltersCore
  FiltersSources
  IOGeometry
  IOLegacy
  IOPLY
  IOXML
  InteractionStyle
  InteractionWidgets
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "Delaunay3DDemo: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(Delaunay3DDemo MACOSX_BUNDLE Delaunay3DDemo.cxx )
  target_link_libraries(Delaunay3DDemo PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS Delaunay3DDemo
  MODULES ${VTK_LIBRARIES}
)
