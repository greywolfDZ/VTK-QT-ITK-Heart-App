#include "Showdicom.h"
Showdicom::Showdicom(std::string path) {

	vtkNew<vtkNamedColors> colors;

	// Verify input arguments


	//std::string folder = path;
	// Read all the DICOM files in the specified directory.
	this-> reader= vtkSmartPointer<vtkDICOMImageReader>::New();;
	this->reader->SetDirectoryName(path.c_str());
	this->reader->Update();

	// Get the dimensions of the image.
	int dimensions[3] = { 0,0,0 };
	this->reader->GetOutput()->GetDimensions(dimensions);

	//Init the vtkImagePlaneWidget for the x¡¢y¡¢z orientation.
	this->imagePlaneX = vtkSmartPointer<vtkImagePlaneWidget>::New();
	this->imagePlaneY = vtkSmartPointer<vtkImagePlaneWidget>::New();
	this->imagePlaneZ = vtkSmartPointer<vtkImagePlaneWidget>::New();
	this->orientationWidget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
	//Init the picker for the vtkImagePlaneWidget.
	vtkNew<vtkCellPicker> picker;

	//Set the property of the imagePlane.
	this->imagePlaneX->SetInputConnection(reader->GetOutputPort());
	//this->imagePlaneX->SetInputData(reader->GetOutput());
	this->imagePlaneX->SetPicker(picker);
	this->imagePlaneX->RestrictPlaneToVolumeOn();
	this->imagePlaneX->GetMarginProperty()->SetOpacity(0);
	this->imagePlaneX->SetMarginSizeX(0);
	this->imagePlaneX->SetMarginSizeY(0);
	this->imagePlaneX->DisplayTextOn();
	this->imagePlaneX->SetResliceInterpolateToLinear();
	this->imagePlaneX->SetPlaneOrientationToXAxes();
	this->imagePlaneX->SetWindowLevel(800, 400, 0);
	this->imagePlaneX->SetSliceIndex(dimensions[0] / 2);
	this->imagePlaneX->SetLeftButtonAction(1);
	this->imagePlaneX->SetMiddleButtonAction(0);
	this->imagePlaneX->GetTexturePlaneProperty()->SetOpacity(1);
	this->imagePlaneX->GetPlaneProperty()->SetColor(0.5, 1,0.5);//ÉèÖÃÇÐÆ¬±ß¿òÎªÀ¶É«£¨Î´Ñ¡Ôñ×´Ì¬£©
	this->imagePlaneX->GetSelectedPlaneProperty()->SetColor(1, 0, 0);//ÉèÖÃÇÐÆ¬±ß¿òÎªºìÉ«£¨Ñ¡Ôñ×´Ì¬£©
	this->imagePlaneY->SetInputConnection(reader->GetOutputPort());
	//this->imagePlaneY->SetInputData(reader->GetOutput());
	this->imagePlaneY->SetPicker(picker);
	this->imagePlaneY->RestrictPlaneToVolumeOn();
	this->imagePlaneY->GetMarginProperty()->SetOpacity(0);
	this->imagePlaneY->GetPlaneProperty()->SetColor(1, 0.5, 0.5);//ÉèÖÃÇÐÆ¬±ß¿òÎªÀ¶É«£¨Î´Ñ¡Ôñ×´Ì¬£©
	this->imagePlaneY->GetSelectedPlaneProperty()->SetColor(1, 0, 0);//ÉèÖÃÇÐÆ¬±ß¿òÎªºìÉ«£¨Ñ¡Ôñ×´Ì¬£©
	this->imagePlaneY->SetMarginSizeX(0);
	this->imagePlaneY->SetMarginSizeY(0);
	this->imagePlaneY->DisplayTextOn();
	this->imagePlaneY->SetResliceInterpolateToLinear();
	this->imagePlaneY->SetPlaneOrientationToYAxes();
	this->imagePlaneY->SetWindowLevel(800, 400, 0);
	this->imagePlaneY->SetSliceIndex(dimensions[1] / 2);
	this->imagePlaneY->SetLeftButtonAction(1);
	this->imagePlaneY->SetMiddleButtonAction(0);
	this->imagePlaneY->GetTexturePlaneProperty()->SetOpacity(1);

	this->imagePlaneZ->SetInputConnection(reader->GetOutputPort());
	//this->imagePlaneZ->SetInputData(reader->GetOutput());
	this->imagePlaneZ->SetPicker(picker);
	this->imagePlaneZ->RestrictPlaneToVolumeOn();
	this->imagePlaneZ->GetMarginProperty()->SetOpacity(0);
	this->imagePlaneZ->GetPlaneProperty()->SetColor(0.5, 0.5, 1);//ÉèÖÃÇÐÆ¬±ß¿òÎªÀ¶É«£¨Î´Ñ¡Ôñ×´Ì¬£©
	this->imagePlaneZ->GetSelectedPlaneProperty()->SetColor(1, 0, 0);//ÉèÖÃÇÐÆ¬±ß¿òÎªºìÉ«£¨Ñ¡Ôñ×´Ì¬£©
	this->imagePlaneZ->SetMarginSizeX(0);
	this->imagePlaneZ->SetMarginSizeY(0);
	this->imagePlaneZ->DisplayTextOn();
	this->imagePlaneZ->SetResliceInterpolateToLinear();
	this->imagePlaneZ->SetPlaneOrientationToZAxes();
	this->imagePlaneZ->SetWindowLevel(800, 400, 0);
	this->imagePlaneZ->SetSliceIndex(dimensions[2] / 2);
	this->imagePlaneZ->SetLeftButtonAction(1);
	this->imagePlaneZ->SetMiddleButtonAction(0);
	this->imagePlaneZ->GetTexturePlaneProperty()->SetOpacity(1);

	// initialize rendering and interaction
/*	vtkNew<vtkRenderer> renderer;
	vtkNew<vtkRenderWindow> renderWindow;
	renderWindow->AddRenderer(renderer);
	renderWindow->SetSize(800, 800);
	renderWindow->SetWindowName("3D");
	
	vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	renderWindowInteractor->SetRenderWindow(renderWindow);

	vtkNew<vtkInteractorStyleTrackballCamera> style;
	renderWindowInteractor->SetInteractorStyle(style);
	*/
	// vtkOrientationMarkerWidget
	//vtkNew<vtkAxesActor> iconActor;
	
	orientationWidget->SetOutlineColor(0.9300, 0.5700, 0.1300);
	//orientationWidget->SetOrientationMarker(iconActor);
	//orientationWidget->SetInteractor(renderWindowInteractor);
	orientationWidget->SetViewport(0.0, 0.0, 0.2, 0.2);
	orientationWidget->SetEnabled(1);
	//orientationWidget->InteractiveOn();

	//Render
	//renderWindow->Render();
	//imagePlaneX->SetInteractor(renderWindowInteractor);
	//imagePlaneY->SetInteractor(renderWindowInteractor);
	//imagePlaneZ->SetInteractor(renderWindowInteractor);

	//renderWindowInteractor->Initialize();
	//imagePlaneX->On();
	//imagePlaneY->On();
	//imagePlaneZ->On();
	//renderer->ResetCamera();

	// Begin mouse interaction
//	renderWindowInteractor->Start();
}
Showdicom::~Showdicom() {

}
void Showdicom::TovtkImageFlip()
{
	this->imagePlaneX->SetInputConnection(reader2->GetOutputPort());
	this->imagePlaneY->SetInputConnection(reader2->GetOutputPort());
	this->imagePlaneZ->SetInputConnection(reader2->GetOutputPort());
	
}
void Showdicom::TovtkDICOMImageReader()
{
	this->imagePlaneX->SetInputConnection(reader->GetOutputPort());
	this->imagePlaneY->SetInputConnection(reader->GetOutputPort());
	this->imagePlaneZ->SetInputConnection(reader->GetOutputPort());

}