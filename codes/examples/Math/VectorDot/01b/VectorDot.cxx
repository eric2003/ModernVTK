#include <vtkFloatArray.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkVectorDot.h>
#include <vtkVersion.h>
#include <iostream>

// For compatibility with new VTK generic data arrays.
#ifdef vtkGenericDataArray_h
#define InsertNextTupleValue InsertNextTypedTuple
#endif

int main(int, char*[])
{
    // 打印 VTK 版本
    std::cout << "VTK 版本: " << vtkVersion::GetVTKVersion() << std::endl;

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

    // 验证输入数据
    if (!polydata->GetPointData()->GetNormals()) {
        std::cerr << "错误：法向量未正确设置！" << std::endl;
        return EXIT_FAILURE;
    }
    if (!polydata->GetPointData()->GetVectors()) {
        std::cerr << "错误：向量未正确设置！" << std::endl;
        return EXIT_FAILURE;
    }

    // 调试：打印法向量和向量
    for (vtkIdType i = 0; i < normals->GetNumberOfTuples(); i++) {
        double* n = normals->GetTuple(i);
        double* v = vectors->GetTuple(i);
        std::cout << "法向量 " << i << ": (" << n[0] << ", " << n[1] << ", " << n[2] << ")" << std::endl;
        std::cout << "向量 " << i << ": (" << v[0] << ", " << v[1] << ", " << v[2] << ")" << std::endl;
        // 手动计算点积
        double dot = n[0] * v[0] + n[1] * v[1] + n[2] * v[2];
        std::cout << "手动计算点积 " << i << ": " << dot << std::endl;
    }

    // 计算点积
    vtkNew<vtkVectorDot> vectorDot;
    vectorDot->SetInputData(polydata);
    // vectorDot->SetScalarRange(0.0, 1.0); // 可选：暂时禁用标量范围
    vectorDot->Update();

    // 获取结果
    auto output = vectorDot->GetOutput();
    if (!output) {
        std::cerr << "错误：vtkVectorDot 输出为空！" << std::endl;
        return EXIT_FAILURE;
    }
    auto scalars = dynamic_cast<vtkFloatArray*>(output->GetPointData()->GetScalars());
    if (!scalars) {
        std::cerr << "错误：无法获取标量数据！" << std::endl;
        return EXIT_FAILURE;
    }

    // 输出标量数组信息
    std::cout << "标量数组名称: " << scalars->GetName() << std::endl;
    std::cout << "标量数组大小: " << scalars->GetNumberOfTuples() << std::endl;

    // 输出结果
    for (vtkIdType i = 0; i < scalars->GetNumberOfTuples(); i++) {
        double value = scalars->GetValue(i);
        std::cout << "点积值 " << i << " : " << value;
        if (std::isnan(value) || std::isinf(value)) {
            std::cout << " (警告：NaN 或 Inf)";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}