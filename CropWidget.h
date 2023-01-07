#pragma once
#include <qwidget.h>
#include<QVTKWidget.h>
#include"ui_CropWidget.h"
#include<vtkOutputWindow.h>
#include<vtkImageFlip.h>
#include<vtkImageData.h>
#include "vtkCamera.h"
#include "vtkGenericRenderWindowInteractor.h"
#include "vtkInteractorStyleJoystickCamera.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkLODActor.h"
#include "vtkLight.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkPropPicker.h"
#include "vtkProperty.h"
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkSTLReader.h"
#include "vtkShrinkPolyData.h"
#include<vtkImplicitPlaneWidget2.h>
#include<vtkImplicitPlaneRepresentation.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>
#include<vtkPlane.h>
//#include"XueGuan.h"
#include<qmessagebox.h>
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
#include"xueguan3.h"
using namespace std;
class CropWidget:public QWidget
{
	Q_OBJECT;
public:
	CropWidget( QWidget* parent = nullptr);
	
	
	//XueGuan* xueguan = new XueGuan();
	string stlpath;
	~CropWidget();
public slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
private:
	Ui::Form2 ui;

};

