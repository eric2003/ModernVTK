cmake_minimum_required(VERSION 3.10)
project(vtkcolor)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加源文件
add_executable(vtkcolor
    main.cpp
    vtkNamedColors.cxx
    vtkObject.cxx
    vtkObjectBase.cxx
    vtkAbstractArray.cxx
    vtkTypeFloat32Array.cxx
    vtkTypeFloat64Array.cxx
    vtkTypeInt8Array.cxx
    vtkTypeInt16Array.cxx
    vtkTypeInt32Array.cxx
    vtkTypeInt64Array.cxx
    vtkTypeUInt8Array.cxx
    vtkTypeUInt16Array.cxx
    vtkTypeUInt32Array.cxx
    vtkTypeUInt64Array.cxx
    vtkUnsignedCharArray.cxx
    vtkUnsignedShortArray.cxx
    vtkUnsignedIntArray.cxx
    vtkUnsignedLongArray.cxx
    vtkUnsignedLongLongArray.cxx
    #vtkUnicodeString.cxx
    vtkStringArray.cxx
	vtkDebugLeaksManager.cxx
)

# 添加头文件路径
target_include_directories(vtkcolor PRIVATE
    #${CMAKE_SOURCE_DIR}/vtk/include
	c:/dev/VTK/include/vtk-9.4/
)

# 定义静态构建宏（如果不使用 DLL）
target_compile_definitions(vtkcolor PRIVATE VTK_COMMONCORE_STATIC VTK_COMMONCOLOR_STATIC)