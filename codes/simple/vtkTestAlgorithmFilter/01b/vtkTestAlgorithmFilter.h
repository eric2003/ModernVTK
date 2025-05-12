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
  virtual void SetOutput(vtkDataObject* d);
  virtual int ProcessRequest(vtkInformation*, vtkInformationVector**,
      vtkInformationVector*) override;
protected:
    vtkTestAlgorithmFilter();
    ~vtkTestAlgorithmFilter();
    virtual int FillOutputPortInformation(int port,
        vtkInformation* info) override;
    virtual int FillInputPortInformation(int port, vtkInformation* info) override;

    virtual int RequestDataObject(vtkInformation* request,
        vtkInformationVector** inputVector,
        vtkInformationVector* outputVector);

    // convenience method
    virtual int RequestInformation(vtkInformation* request,
        vtkInformationVector** inputVector,
        vtkInformationVector* outputVector);

    virtual int RequestData(vtkInformation* request,
        vtkInformationVector** inputVector,
        vtkInformationVector* outputVector);

    virtual int RequestUpdateExtent(vtkInformation*, vtkInformationVector**,
        vtkInformationVector*);
};