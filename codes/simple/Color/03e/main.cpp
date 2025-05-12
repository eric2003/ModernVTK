#include <vtkNew.h>
#include <vtkNamedColors.h>
#include <iostream>

int main(int, char*[])
{
    vtkNew<vtkNamedColors> colors;
    if (colors->ColorExists("Red"))
    {
        std::cout << "Color 'Red' exists\n";
        vtkColor3d co = colors->GetColor3d("Red");
        int s = co.GetSize();
        double* t = co.GetData();
        std::cout << "size = " << s << "\n";
        std::cout << "color = " << t[0] << " " << t[1] << " " << t[2] << "\n";
    }
    else
    {
        std::cout << "Color 'Red' not found\n";
    }
    return 0;
}