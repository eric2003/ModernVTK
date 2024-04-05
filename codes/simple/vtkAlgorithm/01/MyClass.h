#pragma once
#include <vtkAlgorithm.h>

class vtkTestAlgorithmFilter : public vtkAlgorithm
{
public:
  static vtkTestAlgorithmFilter* New();
  vtkTypeMacro(vtkTestAlgorithmFilter, vtkAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;
};