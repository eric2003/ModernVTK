
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ProgressReport)

find_package(VTK COMPONENTS 
  CommonCore
  CommonDataModel
  FiltersSources
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "ProgressReport: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")

add_executable(ProgressReport MACOSX_BUNDLE
 ProgressReport.cxx
 vtkTestProgressReportFilter.cxx
)

target_link_libraries(ProgressReport PRIVATE ${VTK_LIBRARIES}
)


# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS ProgressReport
  MODULES ${VTK_LIBRARIES}
)
