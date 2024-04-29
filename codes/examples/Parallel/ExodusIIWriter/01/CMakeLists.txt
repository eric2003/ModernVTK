
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ExodusIIWriter)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersGeneral
  IOExodus
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ExodusIIWriter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(ExodusIIWriter MACOSX_BUNDLE ExodusIIWriter.cxx )
  target_link_libraries(ExodusIIWriter PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ExodusIIWriter
  MODULES ${VTK_LIBRARIES}
)
