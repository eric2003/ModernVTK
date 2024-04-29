
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(GenericClip)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonDataModel
  FiltersCore
  FiltersGeneric
  FiltersSources
  ImagingHybrid
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  TestingGenericBridge
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "GenericClip: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(GenericClip MACOSX_BUNDLE GenericClip.cxx )
  target_link_libraries(GenericClip PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS GenericClip
  MODULES ${VTK_LIBRARIES}
)
