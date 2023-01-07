#pragma once
#include "vtkDICOMImageReader.h"

#include "vtkFixedPointVolumeRayCastMapper.h"
#include "vtkColorTransferFunction.h"
#include "vtkPiecewiseFunction.h"
#include "vtkVolumeProperty.h"
#include "vtkVolume.h"

#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkImageMapToColors.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkCutter.h"
#include "vtkPlane.h"
#include "vtkImageActor.h"
#include "vtkLODActor.h"
#include "vtkImageData.h"
#include "vtkImageCast.h"
#include "vtkPointData.h"
#include <vtkcamera.h>
#include "vtkImageShiftScale.h"
#include "vtkPolyDataToImageStencil.h"
#include "vtkImageStencil.h"
#include "vtkLookupTable.h"
#include "vtkImagePlaneWidget.h"
#include "vtkCellArray.h"
#include "vtkType.h"
#include "vtkPlaneWidget.h"
#include "vtkProperty.h"
#include "vtkCommand.h"
#include "vtkProbeFilter.h"
#include "vtkImplicitPlaneWidget.h"
#include "vtkNIFTIImageReader.h"
#include "vtkMetaImageReader.h"
#include "vtkSTLReader.h"
class vtkWidgetCall : public vtkCommand
{
public:


	static vtkWidgetCall* New()
	{
		return new vtkWidgetCall;
	}
public:
	virtual void Execute(vtkObject* caller, unsigned long eventId, void* callData)
	{
		vtkPlaneWidget* pWidget = vtkPlaneWidget::SafeDownCast(caller);

		pWidget->GetPlane(pPlane);

	}
public:

	vtkPlane* pPlane;

};
