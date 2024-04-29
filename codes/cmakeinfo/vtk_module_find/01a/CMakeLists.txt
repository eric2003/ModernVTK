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
  set ( my_pack_name _vtk_find_package )
  message( STATUS "my_pack_name=${my_pack_name}" )
  message( STATUS "${my_pack_name}_PRIVATE=${${my_pack_name}_PRIVATE}" )
  message( STATUS "${my_pack_name}_CONFIG_MODE=${${my_pack_name}_CONFIG_MODE}" )
  message( STATUS "${my_pack_name}_PACKAGE=${${my_pack_name}_PACKAGE}" )
  message( STATUS "${my_pack_name}_VERSION=${${my_pack_name}_VERSION}" )
  message( STATUS "${my_pack_name}_FORWARD_VERSION_REQ=${${my_pack_name}_FORWARD_VERSION_REQ}" )
  message( STATUS "${my_pack_name}_VERSION_VAR=${${my_pack_name}_VERSION_VAR}" )
  message( STATUS "${my_pack_name}_COMPONENTS=${${my_pack_name}_COMPONENTS}" )
  message( STATUS "${my_pack_name}_OPTIONAL_COMPONENTS=${${my_pack_name}_OPTIONAL_COMPONENTS}" )
  message( STATUS "${my_pack_name}_UNPARSED_ARGUMENTS=${${my_pack_name}_UNPARSED_ARGUMENTS}" )
  message( STATUS "${my_pack_name}_KEYWORDS_MISSING_VALUES=${${my_pack_name}_KEYWORDS_MISSING_VALUES}" )
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
    swresample
)
