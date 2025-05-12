#pragma once
#include <vtkAlgorithm.h>

class vtkTest;

class vtkTestAlgorithmFilter : public vtkAlgorithm
{
public:
  static vtkTestAlgorithmFilter* New();
  vtkTypeMacro(vtkTestAlgorithmFilter, vtkAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;
  vtkTest* GetOutput();
  vtkTest* GetOutput(int);
  void SetInput(vtkDataObject*);
  void SetInput(int, vtkDataObject*);
};