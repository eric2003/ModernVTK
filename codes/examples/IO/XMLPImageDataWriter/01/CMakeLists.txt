
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(XMLPImageDataWriter)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  IOParallelXML
  ImagingSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "XMLPImageDataWriter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(XMLPImageDataWriter MACOSX_BUNDLE XMLPImageDataWriter.cxx )
  target_link_libraries(XMLPImageDataWriter PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS XMLPImageDataWriter
  MODULES ${VTK_LIBRARIES}
)
