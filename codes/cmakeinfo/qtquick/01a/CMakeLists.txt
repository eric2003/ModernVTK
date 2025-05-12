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
  if (_vtk_find_package_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR
      "Unparsed arguments for vtk_module_find_package: "
      "${_vtk_find_package_UNPARSED_ARGUMENTS}")
  endif ()

  if (NOT DEFINED _vtk_find_package_PACKAGE)
    message(FATAL_ERROR
      "The `PACKAGE` argument is required.")
  endif ()

  if (DEFINED _vtk_find_package_FORWARD_VERSION_REQ)
    if (_vtk_find_package_PRIVATE)
      message(FATAL_ERROR
        "The `FORWARD_VERSION_REQ` argument is incompatible with the "
        "`PRIVATE` flag.")
    endif ()

    if (NOT _vtk_find_package_FORWARD_VERSION_REQ STREQUAL "MAJOR" AND
        NOT _vtk_find_package_FORWARD_VERSION_REQ STREQUAL "MINOR" AND
        NOT _vtk_find_package_FORWARD_VERSION_REQ STREQUAL "PATCH" AND
        NOT _vtk_find_package_FORWARD_VERSION_REQ STREQUAL "EXACT")
      message(FATAL_ERROR
        "The `FORWARD_VERSION_REQ` argument must be one of `MAJOR`, `MINOR`, "
        "`PATCH`, or `EXACT`.")
    endif ()
  endif ()  
  
  if (NOT DEFINED _vtk_find_package_VERSION_VAR)
    set(_vtk_find_package_VERSION_VAR
      "${_vtk_find_package_PACKAGE}_VERSION")
  endif ()
  
  message( STATUS "_vtk_find_package_VERSION_VAR=${_vtk_find_package_VERSION_VAR}" )
  
  set(_vtk_find_package_config)
  if (_vtk_find_package_CONFIG_MODE)
    set(_vtk_find_package_config "CONFIG")
  endif ()  
  
  message( STATUS "_vtk_find_package_PACKAGE=${_vtk_find_package_PACKAGE}" )
  message( STATUS "_vtk_find_package_VERSION=${_vtk_find_package_VERSION}" )
  message( STATUS "_vtk_find_package_config=${_vtk_find_package_config}" )
  message( STATUS "_vtk_find_package_COMPONENTS=${_vtk_find_package_COMPONENTS}" )
  message( STATUS "_vtk_find_package_OPTIONAL_COMPONENTS=${_vtk_find_package_OPTIONAL_COMPONENTS}" )
  
  find_package("${_vtk_find_package_PACKAGE}"
    ${_vtk_find_package_VERSION}
    ${_vtk_find_package_config}
    COMPONENTS          ${_vtk_find_package_COMPONENTS}
    OPTIONAL_COMPONENTS ${_vtk_find_package_OPTIONAL_COMPONENTS}
  )
  
  message( STATUS "_vtk_find_package_PACKAGE=${_vtk_find_package_PACKAGE}" )
  message( STATUS "${_vtk_find_package_PACKAGE}_FOUND=${${_vtk_find_package_PACKAGE}_FOUND}" )
  
  if (NOT ${_vtk_find_package_PACKAGE}_FOUND)
    message(FATAL_ERROR
      "Could not find the ${_vtk_find_package_PACKAGE} external dependency.")
    return ()
  endif ()  
  
  set(_vtk_find_package_optional_components_found)
  foreach (_vtk_find_package_optional_component IN LISTS _vtk_find_package_OPTIONAL_COMPONENTS)
    message( STATUS "_vtk_find_package_optional_component=${_vtk_find_package_optional_component}" )
    if (${_vtk_find_package_PACKAGE}_${_vtk_find_package_optional_component}_FOUND)
      list(APPEND _vtk_find_package_optional_components_found
        "${_vtk_find_package_optional_component}")
    endif ()
  endforeach ()  
  
  message( STATUS "_vtk_find_package_optional_components_found=${_vtk_find_package_optional_components_found}" )
  
endmacro ()

project(testprj)

#set(CMAKE_FIND_DEBUG_MODE TRUE)

list ( APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Cmake" )

set(classes
  QQuickVTKInteractiveWidget
  QQuickVTKInteractorAdapter
  QQuickVTKRenderItem
  QQuickVTKRenderWindow
  QQuickVTKItem
  )

include(vtkQt)
set(qt_components
  #Gui
  #OpenGL
  Quick
  #Qml
  )

include(MyMod)

set( vtk_qt_major_version 6 )

message( STATUS "vtk_qt_major_version=${vtk_qt_major_version}" )
message( STATUS "Qt6_VERSION=${Qt6_VERSION}" )  

vtk_module_find_package(
  PACKAGE     "Qt${vtk_qt_major_version}"
  VERSION     5.9
  COMPONENTS  ${qt_components}
  FORWARD_VERSION_REQ MINOR
  VERSION_VAR         "Qt${vtk_qt_major_version}_VERSION"
)

message( STATUS "Qt6_VERSION NOW=${Qt6_VERSION}" )  

set(vtk_cmake_destination
  "/cmake/vtk")
  
message( STATUS "vtk_cmake_destination=${vtk_cmake_destination}" )
message( STATUS "vtk_modules=${vtk_modules}" )
	
vtk_module_export_find_packages(
  CMAKE_DESTINATION "${vtk_cmake_destination}"
  FILE_NAME         "VTK-vtk-module-find-packages.cmake"
  MODULES           ${vtk_modules})
