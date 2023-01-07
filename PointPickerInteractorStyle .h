#pragma once
#include<vtkInteractorStyleTrackballCamera.h>
#include<vtkPointPicker.h>
#include<vtkRenderWindowInteractor.h>
#include<vtkRenderWindow.h>
#include<vtkRendererCollection.h>
#include<vtkProperty.h>
#include<vtkSphereSource.h>
#include<vtkPolyDataMapper.h>

#include<vtkCommand.h>
#include <vtkImagePlaneWidget.h>
#include<vtkImageMapToWindowLevelColors.h>
class PointPickerInteractorStyle : public vtkCommand
{
public:
	static PointPickerInteractorStyle* New()
	{
		return new PointPickerInteractorStyle;
	}
	void Execute(vtkObject* caller, unsigned long vtkNotUsed(event), void* callData)
	{

		vtkImagePlaneWidget* self = reinterpret_cast<vtkImagePlaneWidget*>(caller);

		if (!self) return;
		double* wl = static_cast<double*>(callData);
		if (self == this->w1)
		{
			w1->GetCursorData(pos);
			pos[0] = 1;
		}
		else if (self == this->w2)
		{
			w2->GetCursorData(pos);
			pos[0] = 2;
		}
		else if(self == this->w3)
		{
			w3->GetCursorData(pos);
			pos[0] = 3;
		}
	


	}
	PointPickerInteractorStyle() :w1(0), w2(0), w3(0) {}
	double pos[4] = {0, 0, 0, 0};
	int flag = 0;
	vtkImagePlaneWidget* w1;
	vtkImagePlaneWidget* w2;
	vtkImagePlaneWidget* w3;
};




