
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(QImageToImageSource)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

find_package(VTK COMPONENTS 
  CommonCore
  RenderingQt
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "QImageToImageSource: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(QImageToImageSource MACOSX_BUNDLE QImageToImageSource.cxx )
  target_link_libraries(QImageToImageSource PRIVATE ${VTK_LIBRARIES}
)

target_link_libraries(QImageToImageSource PRIVATE Qt6::Core)
target_link_libraries(QImageToImageSource PRIVATE Qt6::Gui)
target_link_libraries(QImageToImageSource PRIVATE Qt6::Widgets)

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS QImageToImageSource
  MODULES ${VTK_LIBRARIES}
)
