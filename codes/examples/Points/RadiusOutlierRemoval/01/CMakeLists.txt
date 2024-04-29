
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(RadiusOutlierRemoval)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersCore
  FiltersPoints
  FiltersSources
  IOGeometry
  IOLegacy
  IOPLY
  IOXML
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "RadiusOutlierRemoval: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(RadiusOutlierRemoval MACOSX_BUNDLE RadiusOutlierRemoval.cxx )
  target_link_libraries(RadiusOutlierRemoval PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS RadiusOutlierRemoval
  MODULES ${VTK_LIBRARIES}
)
