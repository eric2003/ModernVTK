
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(FroggieView)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  CommonMath
  CommonTransforms
  FiltersCore
  FiltersGeneral
  IOLegacy
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
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "FroggieView: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(FroggieView MACOSX_BUNDLE FroggieView.cxx )
  target_link_libraries(FroggieView PRIVATE ${VTK_LIBRARIES}
)
list ( APPEND PRJ_COMPILE_FEATURES cxx_std_20 )

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
    ${PRJ_COMPILE_FEATURES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS FroggieView
  MODULES ${VTK_LIBRARIES}
)
