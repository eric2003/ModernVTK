PS D:\work\vtk_2024_work\ModernVTK\codes\examples\VolumeRendering\FixedPointVolumeRayCastMapperCT\01\build> .\Release\FixedPointVolumeRayCastMapperCT.exe
Error: you must specify a directory of DICOM data or a .vti file or a .mha!

Usage:

  FixedPointVolumeRayCastMapperCT <options>

where options may include:

  -DICOM <directory>
  -VTI <filename>
  -MHA <filename>
  -DependentComponents
  -Clip
  -MIP <window> <level>
  -CompositeRamp <window> <level>
  -CompositeShadeRamp <window> <level>
  -CT_Skin
  -CT_Bone
  -CT_Muscle
  -FrameRate <rate>
  -DataReduction <factor>

You must use either the -DICOM option to specify the directory where
the data is located or the -VTI or -MHA option to specify the path of a .vti file.

By default, the program assumes that the file has independent components,
use -DependentComponents to specify that the file has dependent components.

Use the -Clip option to display a cube widget for clipping the volume.
Use the -FrameRate option with a desired frame rate (in frames per second)
which will control the interactive rendering rate.
Use the -DataReduction option with a reduction factor (greater than zero and
less than one) to reduce the data before rendering.
Use one of the remaining options to specify the blend function
and transfer functions. The -MIP option utilizes a maximum intensity
projection method, while the others utilize compositing. The
-CompositeRamp option is unshaded compositing, while the other
compositing options employ shading.

Note: MIP, CompositeRamp, CompositeShadeRamp, CT_Skin, CT_Bone,
and CT_Muscle are appropriate for DICOM data. MIP, CompositeRamp,
and RGB_Composite are appropriate for RGB data.

Example: FixedPointVolumeRayCastMapperCT -DICOM CTNeck -MIP 4096 1024
e.g. -MHA /FullHead.mhd -CT_Bone

.\Release\FixedPointVolumeRayCastMapperCT.exe -DICOM ../../../../Data/DICOMDirectory -MIP 4096 1024
.\Release\FixedPointVolumeRayCastMapperCT.exe -MHA ../../../../Data/FullHead.mhd -CT_Bone
-MHA /FullHead.mhd -CT_Bone

.\Release\BluntStreamlines.exe ../../../../Data/bluntfinxyz.bin  ../../../../Data/bluntfinq.bin
