#pragma once
#pragma once
#include<vtkCommand.h>
#include <vtkImagePlaneWidget.h>
#include<vtkImageMapToWindowLevelColors.h>
class vtkMyCall : public vtkCommand
{
public:
	static vtkMyCall* New()
	{
		return new vtkMyCall;
	}
	void Execute(vtkObject* caller, unsigned long vtkNotUsed(event), void* callData)
	{

		vtkImagePlaneWidget* self = reinterpret_cast<vtkImagePlaneWidget*>(caller);
		pos[0] = WidgetX->GetSliceIndex();
		pos[1] = WidgetY->GetSliceIndex();
		pos[2] = WidgetZ->GetSliceIndex();
		std::string strx = "x:"+std::to_string(pos[0]);
		std::string stry = "y:" + std::to_string(pos[1]);
		std::string strz = "z:" + std::to_string(pos[2]);
		textActorx->SetInput(strx.c_str());
		textActory->SetInput(stry.c_str());
		textActorz->SetInput(strz.c_str());



	}
	vtkMyCall() :WidgetX(0), WidgetY(0), WidgetZ(0) {}
	vtkImagePlaneWidget* WidgetX;
	vtkImagePlaneWidget* WidgetY;
	vtkImagePlaneWidget* WidgetZ;
	int* pos;

	vtkSmartPointer<vtkTextActor> textActorx ;
	vtkSmartPointer<vtkTextActor> textActory ;
	vtkSmartPointer<vtkTextActor> textActorz ;

};
