#include <vtkFloatArray.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkVectorDot.h>
#include <iostream>

// For compatibility with new VTK generic data arrays.
#ifdef vtkGenericDataArray_h
#define InsertNextTupleValue InsertNextTypedTuple
#endif

int main(int, char*[])
{
    // 生成点数据
    vtkNew<vtkPoints> points;
    points->InsertNextPoint(0, 0, 0);
    points->InsertNextPoint(1, 0, 0);
    points->InsertNextPoint(2, 0, 0);

    vtkNew<vtkPolyData> polydata;
    polydata->SetPoints(points);

    // 添加法向量
    vtkNew<vtkFloatArray> normals;
    normals->SetNumberOfComponents(3);
    normals->SetName("Normals");

    float n0[3] = {1, 0, 0};
    float n1[3] = {1, 0, 0};
    float n2[3] = {1, 0, 0};
    normals->InsertNextTupleValue(n0);
    normals->InsertNextTupleValue(n1);
    normals->InsertNextTupleValue(n2);

    polydata->GetPointData()->SetNormals(normals);

    // 添加向量
    vtkNew<vtkFloatArray> vectors;
    vectors->SetNumberOfComponents(3);
    vectors->SetName("Vectors");

    float v0[3] = {1, 0, 0};
    float v1[3] = {0.707f, 0.707f, 0};
    float v2[3] = {0, 1, 0};
    vectors->InsertNextTupleValue(v0);
    vectors->InsertNextTupleValue(v1);
    vectors->InsertNextTupleValue(v2);

    polydata->GetPointData()->SetVectors(vectors);

    // 调试：打印法向量和向量
    for (vtkIdType i = 0; i < normals->GetNumberOfTuples(); i++) {
        double* n = normals->GetTuple(i); // 使用 double*
        double* v = vectors->GetTuple(i); // 使用 double*
        std::cout << "法向量 " << i << ": (" << n[0] << ", " << n[1] << ", " << n[2] << ")" << std::endl;
        std::cout << "向量 " << i << ": (" << v[0] << ", " << v[1] << ", " << v[2] << ")" << std::endl;
    }

    // 计算点积
    vtkNew<vtkVectorDot> vectorDot;
    vectorDot->SetInputData(polydata);
    vectorDot->SetScalarRange(0.0, 1.0); // 设置标量范围以避免映射
    vectorDot->Update();

    // 获取结果
    auto scalars = dynamic_cast<vtkFloatArray*>(
        vectorDot->GetOutput()->GetPointData()->GetScalars());

    if (!scalars) {
        std::cerr << "错误：无法获取标量数据！" << std::endl;
        return EXIT_FAILURE;
    }

    // 输出结果
    for (vtkIdType i = 0; i < scalars->GetNumberOfTuples(); i++) {
        std::cout << "点积值 " << i << " : " << scalars->GetValue(i) << std::endl;
    }

    return EXIT_SUCCESS;
}