
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ImageDataToQImage)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ImageDataToQImage: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ImageDataToQImage MACOSX_BUNDLE ImageDataToQImage.cxx )
  target_link_libraries(ImageDataToQImage PRIVATE ${VTK_LIBRARIES}
)

target_link_libraries(ImageDataToQImage PRIVATE Qt6::Core)
target_link_libraries(ImageDataToQImage PRIVATE Qt6::Gui)
target_link_libraries(ImageDataToQImage PRIVATE Qt6::Widgets)

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ImageDataToQImage
  MODULES ${VTK_LIBRARIES}
)
