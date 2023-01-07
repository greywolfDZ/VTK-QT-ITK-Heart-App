#pragma once
#include <iostream>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkSmartPointer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkPolyDataReader.h>
#include <vtkUnstructuredGrid.h>
#include <vtkSTLReader.h>
#include <vtkSTLWriter.h>
#include <vtkUnstructuredGridVolumeMapper.h>
#include <vtkProperty.h>
#include <vtkIdList.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkPointData.h>
#include <vtkLookupTable.h>
#include <vtkScalarBarActor.h>
#include <vtkCleanPolyData.h>
#include <vtkTriangleFilter.h>
#include <vtkXMLImageDataWriter.h>
#include <vtkImageData.h>
#include <vtkImageShiftScale.h>
#include <vtkPNGWriter.h>

#include <vtkvmtkCenterlineAttributesFilter.h>
#include <vtkvmtkCenterlineBranchExtractor.h>
#include <vtkvmtkCenterlineBranchGeometry.h>
#include <vtkvmtkPolyDataCenterlineGroupsClipper.h>
#include <vtkvmtkCenterlineBifurcationReferenceSystems.h>
#include <vtkvmtkPolyDataCenterlineAngularMetricFilter.h>
#include <vtkvmtkPolyDataCenterlineAbscissaMetricFilter.h>
#include <vtkvmtkPolyDataReferenceSystemBoundaryMetricFilter.h>
#include <vtkvmtkPolyDataMultipleCylinderHarmonicMappingFilter.h>
#include <vtkvmtkPolyDataStretchMappingFilter.h>
#include <vtkvmtkCapPolyData.h>
#include <vtkvmtkPolyDataPatchingFilter.h>
#include <vtkvmtkCenterlineGeometry.h>
#include <vtkParametricSpline.h>
#include <vtkParametricFunctionSource.h>
#include <itkImageSeriesReader.h>
#include <itkImage.h>
#include <vtkDecimatePro.h>

#include"interactorStyleCenterline.h"
#include"Centerline.h"

//itk
#include <itkImageSeriesReader.h>
#include <itkGDCMImageIO.h>
#include <itkGDCMSeriesFileNames.h>
#include <itkImageToVTKImageFilter.h>

#include <iostream>
using namespace std;
class XueGuan
{
public:
	void ReadSurface(string surfacePath, vtkPolyData* surface);
	void ExtractCenterline(string surfacePath, vtkPolyData* inputSurface, vtkPolyData* cappedSurface);
	vtkSmartPointer<vtkImageData> GetDICOMPolyData(string fileName);
	XueGuan();
	vtkSmartPointer<MouseInteractorStyleCenterline> style = vtkSmartPointer<MouseInteractorStyleCenterline>::New();
	vtkSmartPointer<vtkRenderer> ren = vtkSmartPointer<vtkRenderer>::New();

};

