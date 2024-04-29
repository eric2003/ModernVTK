
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(TimerLog)

find_package(VTK COMPONENTS 
  CommonCore
  CommonSystem
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "TimerLog: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(TimerLog MACOSX_BUNDLE TimerLog.cxx )
  target_link_libraries(TimerLog PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS TimerLog
  MODULES ${VTK_LIBRARIES}
)
