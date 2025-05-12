#include "MyClass.h"
#include "vtkTest.h"

#include <vtkObjectFactory.h>

vtkStandardNewMacro(vtkTestAlgorithmFilter);

void vtkTestAlgorithmFilter::PrintSelf(ostream& os, vtkIndent indent)
{
    this->Superclass::PrintSelf(os, indent);
}

//----------------------------------------------------------------------------
vtkTest* vtkTestAlgorithmFilter::GetOutput()
{
    return this->GetOutput(0);
}

//----------------------------------------------------------------------------
vtkTest* vtkTestAlgorithmFilter::GetOutput(int port)
{
    return dynamic_cast<vtkTest*>(this->GetOutputDataObject(port));
}


//----------------------------------------------------------------------------
void vtkTestAlgorithmFilter::SetInput(vtkDataObject* input)
{
    this->SetInput(0, input);
}

//----------------------------------------------------------------------------
void vtkTestAlgorithmFilter::SetInput(int index, vtkDataObject* input)
{
    if (input)
    {
        this->SetInputDataObject(index, input);
    }
    else
    {
        // Setting a NULL input removes the connection.
        this->SetInputDataObject(index, 0);
    }
}