 function (vtk_module_export_find_packages)
  cmake_parse_arguments(PARSE_ARGV 0 _vtk_export
    ""
    "CMAKE_DESTINATION;FILE_NAME;COMPONENT"
    "MODULES")
  message("haha vtk_module_export_find_packages----------")

  if (_vtk_export_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR
      "Unparsed arguments for vtk_module_export_find_packages: "
      "${_vtk_export_UNPARSED_ARGUMENTS}")
  endif ()

  if (NOT DEFINED _vtk_export_CMAKE_DESTINATION)
    message(FATAL_ERROR
      "The `CMAKE_DESTINATION` is required.")
  endif ()

  if (NOT DEFINED _vtk_export_FILE_NAME)
    message(FATAL_ERROR
      "The `FILE_NAME` is required.")
  endif ()

  if (NOT DEFINED _vtk_export_COMPONENT)
    set(_vtk_export_COMPONENT "development")
  endif ()

  set(_vtk_export_prelude
"set(_vtk_module_find_package_quiet)
if (\${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
  set(_vtk_module_find_package_quiet QUIET)
endif ()

set(_vtk_module_find_package_components_checked)
set(_vtk_module_find_package_components_to_check
  \${\${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS})
set(_vtk_module_find_package_components)
set(_vtk_module_find_package_components_required)
while (_vtk_module_find_package_components_to_check)
  list(GET _vtk_module_find_package_components_to_check 0 _vtk_module_component)
  list(REMOVE_AT _vtk_module_find_package_components_to_check 0)
  if (_vtk_module_component IN_LIST _vtk_module_find_package_components_checked)
    continue ()
  endif ()
  list(APPEND _vtk_module_find_package_components_checked
    \"\${_vtk_module_component}\")

  list(APPEND _vtk_module_find_package_components
    \"\${_vtk_module_component}\")
  if (\${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED_\${_vtk_module_component})
    list(APPEND _vtk_module_find_package_components_required
      \"\${_vtk_module_component}\")
  endif ()

  if (TARGET \"\${CMAKE_FIND_PACKAGE_NAME}::\${_vtk_module_component}\")
    set(_vtk_module_find_package_component_target \"\${CMAKE_FIND_PACKAGE_NAME}::\${_vtk_module_component}\")
  elseif (TARGET \"\${_vtk_module_component}\")
    set(_vtk_module_find_package_component_target \"\${_vtk_module_component}\")
  else ()
    # No such target for the component; skip.
    continue ()
  endif ()
  get_property(_vtk_module_find_package_depends
    TARGET    \"\${_vtk_module_find_package_component_target}\"
    PROPERTY  \"INTERFACE_vtk_module_depends\")
  string(REPLACE \"\${CMAKE_FIND_PACKAGE_NAME}::\" \"\" _vtk_module_find_package_depends \"\${_vtk_module_find_package_depends}\")
  list(APPEND _vtk_module_find_package_components_to_check
    \${_vtk_module_find_package_depends})
  get_property(_vtk_module_find_package_depends
    TARGET    \"\${_vtk_module_find_package_component_target}\"
    PROPERTY  \"INTERFACE_vtk_module_private_depends\")
  string(REPLACE \"\${CMAKE_FIND_PACKAGE_NAME}::\" \"\" _vtk_module_find_package_depends \"\${_vtk_module_find_package_depends}\")
  list(APPEND _vtk_module_find_package_components_to_check
    \${_vtk_module_find_package_depends})
  get_property(_vtk_module_find_package_depends
    TARGET    \"\${_vtk_module_find_package_component_target}\"
    PROPERTY  \"INTERFACE_vtk_module_optional_depends\")
  foreach (_vtk_module_find_package_depend IN LISTS _vtk_module_find_package_depends)
    if (TARGET \"\${_vtk_module_find_package_depend}\")
      string(REPLACE \"\${CMAKE_FIND_PACKAGE_NAME}::\" \"\" _vtk_module_find_package_depend \"\${_vtk_module_find_package_depend}\")
      list(APPEND _vtk_module_find_package_components_to_check
        \"\${_vtk_module_find_package_depend}\")
    endif ()
  endforeach ()
  get_property(_vtk_module_find_package_depends
    TARGET    \"\${_vtk_module_find_package_component_target}\"
    PROPERTY  \"INTERFACE_vtk_module_forward_link\")
  string(REPLACE \"\${CMAKE_FIND_PACKAGE_NAME}::\" \"\" _vtk_module_find_package_depends \"\${_vtk_module_find_package_depends}\")
  list(APPEND _vtk_module_find_package_components_to_check
    \${_vtk_module_find_package_depends})

  get_property(_vtk_module_find_package_kit
    TARGET    \"\${_vtk_module_find_package_component_target}\"
    PROPERTY  \"INTERFACE_vtk_module_kit\")
  if (_vtk_module_find_package_kit)
    get_property(_vtk_module_find_package_kit_modules
      TARGET    \"\${_vtk_module_find_package_kit}\"
      PROPERTY  \"INTERFACE_vtk_kit_kit_modules\")
    string(REPLACE \"\${CMAKE_FIND_PACKAGE_NAME}::\" \"\" _vtk_module_find_package_kit_modules \"\${_vtk_module_find_package_kit_modules}\")
    list(APPEND _vtk_module_find_package_components_to_check
      \${_vtk_module_find_package_kit_modules})
  endif ()
endwhile ()
unset(_vtk_module_find_package_component_target)
unset(_vtk_module_find_package_components_to_check)
unset(_vtk_module_find_package_components_checked)
unset(_vtk_module_component)
unset(_vtk_module_find_package_depend)
unset(_vtk_module_find_package_depends)
unset(_vtk_module_find_package_kit)
unset(_vtk_module_find_package_kit_modules)

if (_vtk_module_find_package_components)
  list(REMOVE_DUPLICATES _vtk_module_find_package_components)
endif ()
if (_vtk_module_find_package_components_required)
  list(REMOVE_DUPLICATES _vtk_module_find_package_components_required)
endif ()\n\n")

  set(_vtk_export_build_content)
  set(_vtk_export_install_content)
  foreach (_vtk_export_module IN LISTS _vtk_export_MODULES)
    get_property(_vtk_export_target_name GLOBAL
      PROPERTY "_vtk_module_${_vtk_export_module}_target_name")
    # Use the export name of the target if it has one set.
    get_property(_vtk_export_target_has_export_name
      TARGET    "${_vtk_export_target_name}"
      PROPERTY  EXPORT_NAME SET)
    if (_vtk_export_target_has_export_name)
      get_property(_vtk_export_target_name
        TARGET    "${_vtk_export_target_name}"
        PROPERTY  EXPORT_NAME)
    endif ()
    set(_vtk_export_base "_vtk_module_find_package_${_vtk_export_module}")
    get_property(_vtk_export_packages GLOBAL
      PROPERTY "${_vtk_export_base}")
    if (NOT _vtk_export_packages)
      continue ()
    endif ()

    set(_vtk_export_module_prelude
"set(_vtk_module_find_package_enabled OFF)
set(_vtk_module_find_package_is_required OFF)
set(_vtk_module_find_package_fail_if_not_found OFF)
if (_vtk_module_find_package_components)
  if (\"${_vtk_export_target_name}\" IN_LIST _vtk_module_find_package_components)
    set(_vtk_module_find_package_enabled ON)
    if (\"${_vtk_export_target_name}\" IN_LIST _vtk_module_find_package_components_required)
      set(_vtk_module_find_package_is_required \"\${\${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}\")
      set(_vtk_module_find_package_fail_if_not_found ON)
    endif ()
  endif ()
else ()
  set(_vtk_module_find_package_enabled ON)
  set(_vtk_module_find_package_is_required \"\${\${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED}\")
  set(_vtk_module_find_package_fail_if_not_found ON)
endif ()

if (_vtk_module_find_package_enabled)
  set(_vtk_module_find_package_required)
  if (_vtk_module_find_package_is_required)
    set(_vtk_module_find_package_required REQUIRED)
  endif ()\n\n")

    list(REMOVE_DUPLICATES _vtk_export_packages)
    set(_vtk_export_module_build_content)
    set(_vtk_export_module_install_content)
    foreach (_vtk_export_package IN LISTS _vtk_export_packages)
      set(_vtk_export_base_package "${_vtk_export_base}_${_vtk_export_package}")
      get_property(_vtk_export_private GLOBAL
        PROPERTY "${_vtk_export_base_package}_private")
      get_property(_vtk_export_version GLOBAL
        PROPERTY "${_vtk_export_base_package}_version")
      get_property(_vtk_export_config GLOBAL
        PROPERTY "${_vtk_export_base_package}_config")
      get_property(_vtk_export_exact GLOBAL
        PROPERTY "${_vtk_export_base_package}_exact")
      get_property(_vtk_export_components GLOBAL
        PROPERTY "${_vtk_export_base_package}_components")
      get_property(_vtk_export_optional_components GLOBAL
        PROPERTY "${_vtk_export_base_package}_optional_components")
      get_property(_vtk_export_optional_components_found GLOBAL
        PROPERTY "${_vtk_export_base_package}_optional_components_found")

      # Assume that any found optional components end up being required.
      if (${_vtk_export_base_package}_optional_components_found)
        list(REMOVE_ITEM _vtk_export_optional_components
          ${_vtk_export_optional_components_found})
        list(APPEND _vtk_export_components
          ${_vtk_export_optional_components_found})
      endif ()

      set(_vtk_export_config_arg)
      if (_vtk_export_config)
        set(_vtk_export_config_arg CONFIG)
      endif ()

      set(_vtk_export_exact_arg)
      if (_vtk_export_exact)
        set(_vtk_export_exact_arg EXACT)
      endif ()

      set(_vtk_export_module_content
"  find_package(${_vtk_export_package}
    ${_vtk_export_version}
    ${_vtk_export_exact_arg}
    ${_vtk_export_config_arg}
    \${_vtk_module_find_package_quiet}
    \${_vtk_module_find_package_required}
    COMPONENTS          ${_vtk_export_components}
    OPTIONAL_COMPONENTS ${_vtk_export_optional_components})
  if (NOT ${_vtk_export_package}_FOUND AND _vtk_module_find_package_fail_if_not_found)
    if (NOT \${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
      message(STATUS
        \"Could not find the \${CMAKE_FIND_PACKAGE_NAME} package due to a \"
        \"missing dependency: ${_vtk_export_package}\")
    endif ()
    set(\"\${CMAKE_FIND_PACKAGE_NAME}_${_vtk_export_target_name}_FOUND\" 0)
    list(APPEND \"\${CMAKE_FIND_PACKAGE_NAME}_${_vtk_export_target_name}_NOT_FOUND_MESSAGE\"
      \"Failed to find the ${_vtk_export_package} package.\")
  endif ()\n")

      string(APPEND _vtk_export_module_build_content "${_vtk_export_module_content}")
      # Private usages should be guarded by `$<BUILD_INTERFACE>` and can be
      # skipped for the install tree regardless of the build mode.
      if (NOT _vtk_export_private)
        string(APPEND _vtk_export_module_install_content "${_vtk_export_module_content}")
      endif ()
    endforeach ()

    set(_vtk_export_module_trailer
"endif ()

unset(_vtk_module_find_package_fail_if_not_found)
unset(_vtk_module_find_package_enabled)
unset(_vtk_module_find_package_required)\n\n")

    if (_vtk_export_module_build_content)
      string(APPEND _vtk_export_build_content
        "${_vtk_export_module_prelude}${_vtk_export_module_build_content}${_vtk_export_module_trailer}")
    endif ()
    if (_vtk_export_module_install_content)
      string(APPEND _vtk_export_install_content
        "${_vtk_export_module_prelude}${_vtk_export_module_install_content}${_vtk_export_module_trailer}")
    endif ()
  endforeach ()

  set(_vtk_export_trailer
    "unset(_vtk_module_find_package_components)
unset(_vtk_module_find_package_components_required)
unset(_vtk_module_find_package_quiet)\n")


   message("_vtk_export_CMAKE_DESTINATION=${_vtk_export_CMAKE_DESTINATION}")
   message("_vtk_export_FILE_NAME=${_vtk_export_FILE_NAME}")
   message("CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")
   message("_vtk_export_build_file=${_vtk_export_build_file}")
   message("_vtk_export_install_content=${_vtk_export_install_content}")

  set(_vtk_export_build_file
    "${CMAKE_BINARY_DIR}/${_vtk_export_CMAKE_DESTINATION}/${_vtk_export_FILE_NAME}")
  set(_vtk_export_install_file
    "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${_vtk_export_FILE_NAME}.install")
  if (_vtk_export_build_content)
    file(WRITE "${_vtk_export_build_file}"
      "${_vtk_export_prelude}${_vtk_export_build_content}${_vtk_export_trailer}")
  else ()
    file(WRITE "${_vtk_export_build_file}" "")
  endif ()
  if (_vtk_export_install_content)
    file(WRITE "${_vtk_export_install_file}"
      "${_vtk_export_prelude}${_vtk_export_install_content}${_vtk_export_trailer}")
  else ()
    file(WRITE "${_vtk_export_install_file}" "")
  endif ()

  install(
    FILES       "${_vtk_export_install_file}"
    DESTINATION "${_vtk_export_CMAKE_DESTINATION}"
    RENAME      "${_vtk_export_FILE_NAME}"
    COMPONENT   "${_vtk_export_COMPONENT}")
  message("_vtk_export_install_file=${_vtk_export_install_file}")
  message("_vtk_export_CMAKE_DESTINATION=${_vtk_export_CMAKE_DESTINATION}")
  message("_vtk_export_FILE_NAME=${_vtk_export_FILE_NAME}")
  message("_vtk_export_COMPONENT=${_vtk_export_COMPONENT}")
  message("_vtk_export_prelude=${_vtk_export_prelude}")
  message("_vtk_export_module_trailer=${_vtk_export_module_trailer}")
  message("_vtk_export_module_prelude=${_vtk_export_module_prelude}")
  
  
endfunction ()