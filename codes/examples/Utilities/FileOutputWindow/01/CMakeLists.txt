
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(FileOutputWindow)

find_package(VTK COMPONENTS 
  CommonCore
  IOXML
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "FileOutputWindow: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(FileOutputWindow MACOSX_BUNDLE FileOutputWindow.cxx )
  target_link_libraries(FileOutputWindow PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS FileOutputWindow
  MODULES ${VTK_LIBRARIES}
)
