#pragma once
#include<vtkCommand.h>
#include <vtkImagePlaneWidget.h>
#include<vtkImageMapToWindowLevelColors.h>
class vtkMyCallback : public vtkCommand
{
public:
    static vtkMyCallback* New()
    {
        return new vtkMyCallback;
    }
	void Execute(vtkObject* caller, unsigned long vtkNotUsed(event), void* callData)
	{

		vtkImagePlaneWidget* self = reinterpret_cast<vtkImagePlaneWidget*>(caller);
		if (!self) return;
		double* wl = static_cast<double*>(callData);
		if (self == this->WidgetX)
		{
			this->WidgetY->SetWindowLevel(wl[0], wl[1]);
			this->WidgetZ->SetWindowLevel(wl[0], wl[1]);

		}
		else if (self == this->WidgetY)
		{
			this->WidgetX->SetWindowLevel(wl[0], wl[1]);
			this->WidgetZ->SetWindowLevel(wl[0], wl[1]);
		}
		else if (self == this->WidgetZ)
		{
			this->WidgetX->SetWindowLevel(wl[0], wl[1]);
			this->WidgetY->SetWindowLevel(wl[0], wl[1]);
		}
		//windowLevelx->SetWindow(wl[0]);
		//windowLevelx->SetLevel(wl[1]);
		//windowLevely->SetWindow(wl[0]);
		//windowLevely->SetLevel(wl[1]);
		//windowLevelz->SetWindow(wl[0]);
		//windowLevelz->SetLevel(wl[1]);

	}
	vtkMyCallback() :WidgetX(0), WidgetY(0), WidgetZ(0) {}
	vtkImagePlaneWidget* WidgetX;
	vtkImagePlaneWidget* WidgetY;
	vtkImagePlaneWidget* WidgetZ;
	vtkImageMapToWindowLevelColors* windowLevelx;
	vtkImageMapToWindowLevelColors* windowLevely;
	vtkImageMapToWindowLevelColors* windowLevelz;
    

};
