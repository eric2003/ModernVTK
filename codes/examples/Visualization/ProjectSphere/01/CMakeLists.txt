
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ProjectSphere)

find_package(VTK COMPONENTS 
  CommonColor
  CommonComputationalGeometry
  CommonCore
  CommonDataModel
  FiltersCore
  FiltersGeometry
  FiltersSources
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ProjectSphere: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ProjectSphere MACOSX_BUNDLE ProjectSphere.cxx )
  target_link_libraries(ProjectSphere PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ProjectSphere
  MODULES ${VTK_LIBRARIES}
)
