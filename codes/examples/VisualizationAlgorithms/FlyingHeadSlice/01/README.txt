Generate 2D contour lines, corresponding to tissue density, on one CT slice through the head.
The contour lines are colored by the tissue density.
Usage: D:\work\vtk_2024_work\ModernVTK\codes\examples\VisualizationAlgorithms\FlyingHeadSlice\01\build\Release\FlyingHeadSlice.exe FullHead.mhd [useContourFilter]
where: filename is FullHead.mhd,
       useContourFilter = 0|1
Examples:
Contouring, using vtkFlyingEdges2D: FullHead.mhd
Contouring, using vtkContourFilter: FullHead.mhd 1
.\Release\FlyingHeadSlice.exe ../../../../Data/FullHead.mhd
.\Release\FlyingHeadSlice.exe ../../../../Data/FullHead.mhd 1
