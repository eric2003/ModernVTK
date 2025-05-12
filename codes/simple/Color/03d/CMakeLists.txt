cmake_minimum_required ( VERSION 4.0.2 )

project(testprj)

#set(VTK_DIR "c:/dev/VTK/lib/cmake/vtk-9.4/")
set(VTK_DIR "c:/dev/VTK-RELESAE-STATIC/lib/cmake/vtk-9.4/")

find_package(VTK COMPONENTS CommonColor CommonCore REQUIRED)

set(PRJ_COMPILE_FEATURES cxx_std_23)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${VTK_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE VTK::CommonColor VTK::CommonCore)
target_compile_features(${PROJECT_NAME} PRIVATE ${PRJ_COMPILE_FEATURES})

# vtk_module_autoinit is needed for dynamic libraries
vtk_module_autoinit(
    TARGETS ${PROJECT_NAME}
    MODULES VTK::CommonColor VTK::CommonCore
)

if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()