
cmake_minimum_required(VERSION 3.28)

PROJECT(BarChartQt)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

find_package(VTK COMPONENTS 
  ChartsCore
  CommonColor
  CommonCore
  CommonDataModel
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  ViewsContext2D
  GUISupportQt
  RenderingQt
)

if(NOT VTK_FOUND)
  message(FATAL_ERROR "BarChartQt: Unable to find the VTK build folder.")
endif()

if(NOT(TARGET VTK::GUISupportQt))
  message(FATAL_ERROR "BarChartQt: VTK not built with Qt support.")
endif()

if(NOT DEFINED VTK_QT_VERSION)
  set(VTK_QT_VERSION 5)
endif()

