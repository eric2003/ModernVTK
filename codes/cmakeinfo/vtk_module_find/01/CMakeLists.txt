cmake_minimum_required(VERSION 3.28)

macro (vtk_module_find_package)
  # Note: when adding arguments here, add them to the `unset` block at the end
  # of the function.
  cmake_parse_arguments(_vtk_find_package
    "PRIVATE;CONFIG_MODE"
    "PACKAGE;VERSION;FORWARD_VERSION_REQ;VERSION_VAR"
    "COMPONENTS;OPTIONAL_COMPONENTS"
    ${ARGN})
  message( STATUS "ARGN=${ARGN}" )
endmacro ()

project(testprj)

vtk_module_find_package(
  PACKAGE FFMPEG
  VERSION 2.3.3
  FORWARD_VERSION_REQ MINOR
  COMPONENTS
    avformat
    avcodec
    avutil
    swscale
  OPTIONAL_COMPONENTS
    swresample)
