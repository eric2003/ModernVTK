
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(OggTheora)

find_package(VTK COMPONENTS 
  CommonCore
  IOOggTheora
  ImagingSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "OggTheora: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(OggTheora MACOSX_BUNDLE OggTheora.cxx )
  target_link_libraries(OggTheora PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS OggTheora
  MODULES ${VTK_LIBRARIES}
)
