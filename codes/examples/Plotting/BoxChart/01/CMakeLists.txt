
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(BoxChart)

find_package(VTK COMPONENTS 
  ChartsCore
  CommonCore
  CommonDataModel
  FiltersStatistics
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  ViewsContext2D
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "BoxChart: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(BoxChart MACOSX_BUNDLE BoxChart.cxx )
  target_link_libraries(BoxChart PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS BoxChart
  MODULES ${VTK_LIBRARIES}
)
