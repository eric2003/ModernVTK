#include <vtkFloatArray.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkVectorDot.h>
#include <vtkVersion.h>
#include <vtkObject.h>
#include <iostream>

// For compatibility with new VTK generic data arrays.
#ifdef vtkGenericDataArray_h
#define InsertNextTupleValue InsertNextTypedTuple
#endif

int main(int, char*[])
{
    // ���� VTK ������־
    vtkObject::GlobalWarningDisplayOn();

    // ��ӡ VTK �汾
    std::cout << "VTK �汾: " << vtkVersion::GetVTKVersion() << std::endl;

    // ���ɵ�����
    vtkNew<vtkPoints> points;
    points->InsertNextPoint(0, 0, 0);
    points->InsertNextPoint(1, 0, 0);
    points->InsertNextPoint(2, 0, 0);

    vtkNew<vtkPolyData> polydata;
    polydata->SetPoints(points);

    // ��ӷ�����
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

    // �������
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

    // ��֤��������
    if (!polydata->GetPointData()->GetNormals()) {
        std::cerr << "���󣺷�����δ��ȷ���ã�" << std::endl;
        return EXIT_FAILURE;
    }
    if (!polydata->GetPointData()->GetVectors()) {
        std::cerr << "��������δ��ȷ���ã�" << std::endl;
        return EXIT_FAILURE;
    }
    if (polydata->GetNumberOfPoints() != normals->GetNumberOfTuples() ||
        polydata->GetNumberOfPoints() != vectors->GetNumberOfTuples()) {
        std::cerr << "���󣺵������뷨����������������ƥ�䣡" << std::endl;
        return EXIT_FAILURE;
    }

    // ���ԣ���ӡ������������
    for (vtkIdType i = 0; i < normals->GetNumberOfTuples(); i++) {
        double* n = normals->GetTuple(i);
        double* v = vectors->GetTuple(i);
        std::cout << "������ " << i << ": (" << n[0] << ", " << n[1] << ", " << n[2] << ")" << std::endl;
        std::cout << "���� " << i << ": (" << v[0] << ", " << v[1] << ", " << v[2] << ")" << std::endl;
        double dot = n[0] * v[0] + n[1] * v[1] + n[2] * v[2];
        std::cout << "�ֶ������� " << i << ": " << dot << std::endl;
    }

    // ������
    vtkNew<vtkVectorDot> vectorDot;
    vectorDot->SetInputData(polydata);
    // vectorDot->SetScalarRange(0.0, 1.0); // ��ʱ���ñ�����Χ
    try {
        vectorDot->Update();
    } catch (...) {
        std::cerr << "����vtkVectorDot ִ��ʱ�����쳣��" << std::endl;
        return EXIT_FAILURE;
    }

    // ��ȡ���
    auto output = vectorDot->GetOutput();
    if (!output) {
        std::cerr << "����vtkVectorDot ���Ϊ�գ�" << std::endl;
        return EXIT_FAILURE;
    }
    auto pointData = output->GetPointData();
    if (!pointData) {
        std::cerr << "�����޷���ȡ�����ݣ�" << std::endl;
        return EXIT_FAILURE;
    }
    auto scalars = dynamic_cast<vtkFloatArray*>(pointData->GetScalars());
    if (!scalars) {
        std::cerr << "�����޷���ȡ�������ݣ�" << std::endl;
        // �󱸷������ֶ�������
        vtkNew<vtkFloatArray> manualScalars;
        manualScalars->SetNumberOfComponents(1);
        manualScalars->SetName("DotProduct");
        for (vtkIdType i = 0; i < normals->GetNumberOfTuples(); i++) {
            double* n = normals->GetTuple(i);
            double* v = vectors->GetTuple(i);
            double dot = n[0] * v[0] + n[1] * v[1] + n[2] * v[2];
            manualScalars->InsertNextValue(dot);
        }
        polydata->GetPointData()->SetScalars(manualScalars);
        scalars = manualScalars;
    }

    // �������������Ϣ
    std::cout << "������������: " << (scalars->GetName() ? scalars->GetName() : "δ����") << std::endl;
    std::cout << "���������С: " << scalars->GetNumberOfTuples() << std::endl;

    // ������
    for (vtkIdType i = 0; i < scalars->GetNumberOfTuples(); i++) {
        double value = scalars->GetValue(i);
        std::cout << "���ֵ " << i << " : " << value;
        if (std::isnan(value) || std::isinf(value)) {
            std::cout << " (���棺NaN �� Inf)";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}