#include "Gpuwidget.h"
Gpuwidget::Gpuwidget(vtkSmartPointer<vtkImageFlip> reader1 , QWidget* parent) :QWidget(parent) {
	vtkOutputWindow::SetGlobalWarningDisplay(0);
	ui.setupUi(this);
	this->qvtkwidget = ui.qvtkWidget;
	//std::string folder = ".\\Heart";
	this->reader = vtkSmartPointer<vtkImageFlip>::New();
	this->reader->SetInputData(reader1->GetOutput());
	vtkSmartPointer< vtkRenderWindow>pWin = vtkSmartPointer<vtkRenderWindow>::New();
	qvtkwidget->SetRenderWindow(pWin);
	this->gpumak = new Gpumake(reader);
    qvtkwidget->GetRenderWindow()->AddRenderer(this->gpumak->aRenderer);
	this->qvtkwidget->setParent(this);
	this->qvtkwidget->GetRenderWindow()->SetSize(40, 40);

	//this->qvtkwidget->setFixedSize(40, 40);
	this->qvtkwidget->show();
	this->qvtkwidget->setGeometry(0, 0, 400, 400);
	this->resize(400, 400);
	//this->setMaximumSize(500, 500);
	//this->setMaximumSize(500, 500);
}
Gpuwidget::~Gpuwidget()
{

}
