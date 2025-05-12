cmake_minimum_required ( VERSION 3.25 )

project ( testprj )

set ( PRJ_SRC_LIST )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )

message ( STATUS "CMake root directory: ${CMAKE_ROOT}" )

find_package ( VTK )

if ( VTK_FOUND )
	message ( STATUS " VTK_FOUND =  ${VTK_FOUND}" )
	message ( STATUS " VTK_MAJOR_VERSION = ${VTK_MAJOR_VERSION}" )
	message ( STATUS " VTK_MINOR_VERSION = ${VTK_MINOR_VERSION}" )
	message ( STATUS " VTK_BUILD_VERSION = ${VTK_BUILD_VERSION}" )
	message ( STATUS " VTK_LIBRARY_DIRS  = ${VTK_LIBRARY_DIRS}" )
	message ( STATUS " VTK_LIBRARIES  = ${VTK_LIBRARIES}" )
endif()

list ( APPEND PRJ_LIBRARIES ${VTK_LIBRARIES} )

if ( MSVC )
    set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )
endif()

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_23 )

add_executable( ${PROJECT_NAME} )

target_sources( ${PROJECT_NAME}
    PRIVATE
        main.cpp
		vtkTest.h vtkTest.cpp
		vtkTestAlgorithmFilter.h vtkTestAlgorithmFilter.cpp		
)

target_include_directories ( ${PROJECT_NAME}
	PRIVATE 
        ${PRJ_INCLUDE_DIRS}
)

target_link_libraries ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)

target_compile_features ( ${PROJECT_NAME} 
    PRIVATE 
    ${PRJ_COMPILE_FEATURES}
)

# vtk_module_autoinit is needed
vtk_module_autoinit(
    TARGETS ${PROJECT_NAME}
    MODULES ${VTK_LIBRARIES}
)



