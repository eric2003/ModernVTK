#include <vtkCallbackCommand.h>
#include <vtkCamera.h>
#include <vtkRenderer.h>

#include <iostream>

namespace {

// Get the camera position.
void CameraModifiedCallback(vtkObject* caller,
                            long unsigned int vtkNotUsed(eventId),
                            void* vtkNotUsed(clientData),
                            void* vtkNotUsed(callData));
} // namespa

namespace {

void CameraModifiedCallback(vtkObject* caller,
                            long unsigned int vtkNotUsed(eventId),
                            void* vtkNotUsed(clientData),
                            void* vtkNotUsed(callData))
{
  std::cout << caller->GetClassName() << " modified" << std::endl;
  vtkCamera* camera = static_cast<vtkCamera*>(caller);
  // Print the interesting stuff.
  std::cout << "  auto camera = renderer->GetActiveCamera();" << std::endl;
  std::cout << "  camera->SetPosition(" << camera->GetPosition()[0] << ", "
            << camera->GetPosition()[1] << ", " << camera->GetPosition()[2]
            << ");" << std::endl;
  std::cout << "  camera->SetFocalPoint(" << camera->GetFocalPoint()[0] << ", "
            << camera->GetFocalPoint()[1] << ", " << camera->GetFocalPoint()[2]
            << ");" << std::endl;
  std::cout << "  camera->SetViewUp(" << camera->GetViewUp()[0] << ", "
            << camera->GetViewUp()[1] << ", " << camera->GetViewUp()[2] << ");"
            << std::endl;
  std::cout << "  camera->SetDistance(" << camera->GetDistance() << ");"
            << std::endl;
  std::cout << "  camera->SetClippingRange(" << camera->GetClippingRange()[0]
            << ", " << camera->GetClippingRange()[1] << ");" << std::endl;
  std::cout << std::endl;
}
} // namespace

int main(int argc, char* argv[])
{

    // Create a renderer, render window, and interactor
    vtkNew<vtkRenderer> renderer;
	
  // Call vtkRenderWindow::Render() before this code e.g. renWin->Render();
   vtkNew<vtkCallbackCommand> modifiedCallback;
   modifiedCallback->SetCallback(CameraModifiedCallback);
   renderer->GetActiveCamera()->AddObserver(vtkCommand::ModifiedEvent,
                                           modifiedCallback);

  return EXIT_SUCCESS;
}
