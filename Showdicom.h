#pragma once
#include <vtkAxesActor.h>
#include <vtkImageData.h>
#include <vtkImagePlaneWidget.h>
#include <vtkCellPicker.h>
#include <vtkProperty.h>
#include <vtkCamera.h>
#include <vtkActor.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
// headers needed for this example
#include <vtkOrientationMarkerWidget.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageReader2.h>
#include <vtkImageViewer2.h>
#include <vtkInteractorStyleImage.h>
#include <vtkTextMapper.h>
#include<vtkImageFlip.h>
// needed to easily convert int to std::string
#include <sstream>
class Showdicom
{
public:
	Showdicom(std::string path);
	void TovtkImageFlip();
	void TovtkDICOMImageReader();
	~Showdicom();
	vtkSmartPointer<vtkDICOMImageReader> reader;
	vtkSmartPointer<vtkImageFlip> reader2=vtkSmartPointer<vtkImageFlip>::New();
	vtkSmartPointer <vtkImagePlaneWidget> imagePlaneX;
	vtkSmartPointer <vtkImagePlaneWidget> imagePlaneY;
	vtkSmartPointer <vtkImagePlaneWidget> imagePlaneZ;
	vtkSmartPointer <vtkOrientationMarkerWidget> orientationWidget;
};

