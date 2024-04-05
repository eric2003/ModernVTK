
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(AlgorithmFilter)

find_package(VTK COMPONENTS 
DICOM
zlib
MomentInvariants
eigen
kissfft
WrappingTools
ViewsContext2D
loguru
TestingRendering
TestingCore
vtksys
ViewsInfovis
CommonColor
RenderingVolumeOpenGL2
glew
opengl
RenderingLabel
octree
RenderingLOD
RenderingLICOpenGL2
RenderingImage
RenderingContextOpenGL2
RenderingCellGrid
IOVeraOut
hdf5
IOTecplotTable
utf8
IOSegY
IOParallelXML
IOParallel
jsoncpp
IOPLY
IOOggTheora
theora
ogg
IONetCDF
netcdf
libproj
IOMotionFX
pegtl
IOMINC
IOLSDyna
IOInfovis
libxml2
IOImport
IOIOSS
fmt
ioss
cgns
exodusII
IOFLUENTCFF
IOVideo
IOMovie
IOExportPDF
libharu
IOExportGL2PS
RenderingGL2PSOpenGL2
gl2ps
png
IOExport
RenderingVtkJS
nlohmannjson
RenderingSceneGraph
IOExodus
IOEnSight
IOCityGML
pugixml
IOChemistry
IOCesium3DTiles
IOGeometry
IOCellGrid
IOCONVERGECFD
IOHDF
IOCGNSReader
IOAsynchronous
IOAMR
InteractionImage
ImagingStencil
ImagingStatistics
ImagingMorphological
ImagingMath
ImagingFourier
IOSQL
sqlite
GeovisCore
InfovisLayout
ViewsCore
InteractionWidgets
RenderingVolume
RenderingAnnotation
ImagingHybrid
ImagingColor
InteractionStyle
FiltersTopology
FiltersTensor
FiltersSelection
FiltersSMP
FiltersReduction
FiltersProgrammable
FiltersPoints
FiltersParallelImaging
FiltersImaging
ImagingGeneral
FiltersGeometryPreview
FiltersGeneric
FiltersFlowPaths
FiltersCellGrid
FiltersAMR
FiltersParallel
FiltersTexture
FiltersModeling
DomainsChemistryOpenGL2
RenderingOpenGL2
RenderingHyperTreeGrid
RenderingUI
FiltersHybrid
DomainsChemistry
ChartsCore
InfovisCore
FiltersExtraction
ParallelDIY
diy2
IOXML
IOXMLParser
expat
ParallelCore
IOLegacy
IOCore
doubleconversion
lz4
lzma
fast_float
FiltersStatistics
FiltersHyperTree
ImagingSources
IOImage
DICOMParser
jpeg
metaio
tiff
RenderingContext2D
RenderingFreeType
freetype
kwiml
RenderingCore
FiltersSources
ImagingCore
FiltersGeneral
FiltersVerdict
verdict
FiltersGeometry
CommonComputationalGeometry
FiltersCore
CommonExecutionModel
CommonDataModel
CommonSystem
CommonMisc
exprtk
CommonTransforms
CommonMath
CommonCore

)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "AlgorithmFilter: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
#add_executable(AlgorithmFilter MACOSX_BUNDLE AlgorithmFilter.cxx )
add_executable(AlgorithmFilter MACOSX_BUNDLE
        AlgorithmFilter.cxx
		vtkTest.h vtkTest.cxx
		vtkTestAlgorithmFilter.h vtkTestAlgorithmFilter.cxx	
)

target_link_libraries(AlgorithmFilter PRIVATE ${VTK_LIBRARIES}
)
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS AlgorithmFilter
  MODULES ${VTK_LIBRARIES}
)
