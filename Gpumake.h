#pragma once
#include<vtkRenderWindowInteractor.h>
#include<vtkDICOMImageReader.h>
#include<vtkCamera.h>
#include<vtkActor.h>
#include<vtkRenderer.h>
#include<vtkVolumeProperty.h>
#include<vtkProperty.h>
#include<vtkPolyDataNormals.h>
#include<vtkImageShiftScale.h>
#include <vtkFixedPointVolumeRayCastMapper.h>
#include<vtkPiecewiseFunction.h>
#include<vtkColorTransferFunction.h>
#include<vtkRenderWindow.h>
#include<vtkImageCast.h>
#include<vtkOBJExporter.h>
#include<vtkOutlineFilter.h>
#include<vtkPolyDataMapper.h>
#include <vtkFixedPointVolumeRayCastMIPHelper.h>
#include<vtkInteractorStyleTrackballCamera.h>
#include<vtkImageGaussianSmooth.h>
#include<vtkMetaImageReader.h>
#include<vtkLODProp3D.h>
#include<vtkLoopSubdivisionFilter.h>
#include<vtkPointHandleRepresentation3D.h>
#include<vtkPolygonalSurfacePointPlacer.h>
#include <vtkAutoInit.h>
#include<vtkDistanceWidget.h>
#include<vtkHandleWidget.h>
#include<vtkAxisActor2D.h>
#include<vtkDistanceRepresentation2D.h>
#include<vtkGPUVolumeRayCastMapper.h>
#include<iostream>
#include<vtkImageFlip.h>

class Gpumake
{
public:
	vtkRenderer* aRenderer = vtkRenderer::New();
	Gpumake(vtkSmartPointer<vtkImageFlip> reader);
	vtkDistanceWidget* widget = vtkDistanceWidget::New();
	//vtkDistanceCallback1* mcbk = vtkDistanceCallback1::New();
	vtkInteractorStyleTrackballCamera* style = vtkInteractorStyleTrackballCamera::New();
};

