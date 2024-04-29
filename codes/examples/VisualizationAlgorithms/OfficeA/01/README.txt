PS D:\work\vtk_2024_work\ModernVTK\codes\examples\VisualizationAlgorithms\OfficeA\01\build> .\Release\OfficeA.exe
Usage: D:\work\vtk_2024_work\ModernVTK\codes\examples\VisualizationAlgorithms\OfficeA\01\build\Release\OfficeA.exe filename [center] e.g. office.binary.vtk 3
Demonstrate the use of vtkPointSource to generate streamlines.
Where:
       filename: office.binary.vtk
       center: An optional parameter choosing the center for the seeds.
               0 - Corresponds to Fig 9-47(a) in the VTK textbook.
               1 - A slight shift to the left.
               2 - A slight shift to the upper left. (from the Original code).
               3 - The default, a slight shift to the upper left.
                   Roughly corresponds to Fig 9-47(b) in the VTK textbook.
.\Release\OfficeA.exe ../../../../Data/office.binary.vtk 3
