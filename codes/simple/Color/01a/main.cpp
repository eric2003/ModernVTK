#include <vtkNew.h>
#include "vtkNamedColors.h"
#include "vtkSmartPointer.h"

int main(int, char*[])
{
    //vtkNew<vtkNamedColors> colors;
    vtkSmartPointer<vtkNamedColors> colors = vtkSmartPointer<vtkNamedColors>::New();
    vtkColor3d co = colors->GetColor3d( "Red" );
    int s = co.GetSize();
    double * t = co.GetData();
    std::cout << "haha\n";
    std::cout << "size = " << s << "\n";
    std::cout << "color = " << t[0] << " " << t[1] << " " << t[2] << " " << "\n";
    return 0;
}
