
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(FroggieSurface)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonMath
  CommonTransforms
  FiltersCore
  FiltersGeneral
  IOImage
  ImagingCore
  ImagingGeneral
  ImagingMorphological
  InteractionStyle
  InteractionWidgets
  RenderingAnnotation
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  cli11
  jsoncpp
  IOExport
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "FroggieSurface: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(FroggieSurface MACOSX_BUNDLE FroggieSurface.cxx )
  target_link_libraries(FroggieSurface PRIVATE ${VTK_LIBRARIES}
)

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
    ${PRJ_COMPILE_FEATURES}
)

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS FroggieSurface
  MODULES ${VTK_LIBRARIES}
)
