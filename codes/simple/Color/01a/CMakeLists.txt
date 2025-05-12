cmake_minimum_required ( VERSION 4.0.2 )

project ( testprj )

set ( PRJ_SRC_LIST )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )
set ( PRJ_COMPILE_DEF )
set ( PRJ_COMPILE_FEATURES )

message ( STATUS "CMake root directory: ${CMAKE_ROOT}" )

#find_package ( VTK )
#
#if ( VTK_FOUND )
#	message ( STATUS " VTK_FOUND =  ${VTK_FOUND}" )
#	message ( STATUS " VTK_MAJOR_VERSION = ${VTK_MAJOR_VERSION}" )
#	message ( STATUS " VTK_MINOR_VERSION = ${VTK_MINOR_VERSION}" )
#	message ( STATUS " VTK_BUILD_VERSION = ${VTK_BUILD_VERSION}" )
#	message ( STATUS " VTK_LIBRARY_DIRS  = ${VTK_LIBRARY_DIRS}" )
#	message ( STATUS " VTK_LIBRARIES  = ${VTK_LIBRARIES}" )
#endif()

list ( APPEND PRJ_LIBRARIES ${VTK_LIBRARIES} )

list ( APPEND PRJ_INCLUDE_DIRS "c:/dev/VTK/include/vtk-9.4/" )
list ( APPEND PRJ_INCLUDE_DIRS "c:/dev/VTK/include/vtk-9.4/vtksys/" )

list ( APPEND PRJ_COMPILE_DEF VTKCOMMONCORE_STATIC_DEFINE )
list ( APPEND PRJ_COMPILE_DEF KWSYS_NAMESPACE=vtksys )
list ( APPEND PRJ_COMPILE_DEF KWSYS_ENCODING_DEFAULT_CODEPAGE=CP_UTF8 )

if ( MSVC )
    set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )
endif()

list ( APPEND PRJ_COMPILE_FEATURES cxx_std_23 )

add_executable( ${PROJECT_NAME} )

target_sources( ${PROJECT_NAME}
    PRIVATE
        main.cpp
		vtkNamedColors.cxx
		vtkObject.cxx
		vtkStringArray.cxx
		vtkAbstractArray.cxx
		vtkInformationKey.cxx
		vtkInformationDoubleKey.cxx
		vtkInformationDoubleVectorKey.cxx
		vtkInformationVariantVectorKey.cxx
		vtkInformationInformationVectorKey.cxx
		vtkObjectBase.cxx
		vtkVariant.cxx
		SystemTools.cxx
		vtkSmartPointerBase.cxx
		vtkIndent.cxx
		vtkDebugLeaksManager.cxx
		vtkObjectFactory.cxx
		vtkOStreamWrapper.cxx
		RegularExpression.cxx
		Directory.cxx
		Status.cxx
		EncodingCXX.cxx
		vtkOStrStreamWrapper.cxx
		vtkOutputWindow.cxx
		vtkTimeStamp.cxx
		vtkCommand.cxx
		vtkGarbageCollectorManager.cxx
		vtkIdList.cxx
		vtkArrayIterator.cxx
		vtkBitArray.cxx
		vtkCharArray.cxx
		vtkDoubleArray.cxx
		vtkFloatArray.cxx
		vtkIdTypeArray.cxx
		vtkInformation.cxx
		vtkCommonInformationKeyManager.cxx
		vtkInformationIntegerKey.cxx
		vtkInformationVector.cxx
		vtkStdString.cxx
		vtkIntArray.cxx
		vtkLongArray.cxx
		vtkLongLongArray.cxx
		vtkInformationIntegerPointerKey.cxx
		vtkValueFromString.cxx
		vtkMinimalStandardRandomSequence.cxx
		vtkInformationKeyLookup.cxx
		vtkShortArray.cxx
		vtkSignedCharArray.cxx
		vtkGarbageCollector.cxx
		vtkDebugLeaks.cxx
#		vtkTypeFloat64Array.cxx
#		vtkTypeInt16Array.cxx
#		vtkTypeInt32Array.cxx
#		vtkTypeInt64Array.cxx
#		vtkTypeInt8Array.cxx
#		vtkUnsignedShortArray.cxx
#		vtkTypeUInt16Array.cxx
#		vtkUnsignedIntArray.cxx
#		vtkTypeUInt32Array.cxx
#		vtkUnsignedLongLongArray.cxx
#		vtkTypeUInt64Array.cxx
#		vtkUnsignedCharArray.cxx
#		vtkTypeUInt8Array.cxx
#		vtkUnsignedLongArray.cxx
#		vtkVariantArray.cxx
#		
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

target_compile_definitions ( ${PROJECT_NAME}
    PRIVATE
       ${PRJ_COMPILE_DEF} 
)

## vtk_module_autoinit is needed
#vtk_module_autoinit(
#    TARGETS ${PROJECT_NAME}
#    MODULES ${VTK_LIBRARIES}
#)



