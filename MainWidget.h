#pragma once
#include <itkCurvatureFlowImageFilter.h>
#include <itkNeighborhoodConnectedImageFilter.h>
#include <QtWidgets/QMainWindow>
#include <vtkDICOMImageReader.h>
#include<vtkImageViewer2.h>
#include "ui_MainWidget.h"
#include "vtkAutoInit.h"
#include<vtkSmartPointer.h>
#include<qfiledialog.h>
#include<qaction.h>
#include"Showdicom.h"
#include<vtkResliceImageViewer.h>
#include"Gpumake.h"
#include<vtkImageActor.h>
#include"Mycallback.h"
#include<vtkInteractorStyleTrackballActor.h>
#include<vtkImageMapToWindowLevelColors.h>
#include"Gpuwidget.h"
#include"PointPickerInteractorStyle .h"
#include <itkVTKImageToImageFilter.h>
#include <vtkImageFlip.h>
#include "itkImageToVTKImageFilter.h"
#include "itkImage.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImageSeriesReader.h"
#include<vtkPropAssembly.h>
#include<vtkTextActor.h>
#include<vtkTextProperty.h>
#include"Mycall.h"
#include<itkConfidenceConnectedImageFilter.h>
#include<itkCastImageFilter.h>
#include<itkBinaryBallStructuringElement.h>
#include<itkBinaryMorphologicalClosingImageFilter.h>
#include"CropWidget.h"
#include<itkMetaImageIO.h>
#include<itkImageFileWriter.h>
#include<vtkImageCast.h>
#include<QInputDialog>
#include<vtkLookupTable.h>
// needed to easily convert int to std::string
#include <sstream>
//VTK_MODULE_INIT(vtkRenderingOpenGL2);
//VTK_MODULE_INIT(vtkInteractionStyle);
class MainWidget : public QMainWindow
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    QVTKWidget* qvtkw;
    vtkSmartPointer <vtkImageViewer2> myViewer;
    vtkSmartPointer <vtkRenderer>  myRender;
    vtkSmartPointer <vtkImageFlip> reader= vtkSmartPointer <vtkImageFlip>::New();
    vtkSmartPointer <vtkImageFlip> rawreader = vtkSmartPointer <vtkImageFlip>::New();
    vtkSmartPointer<vtkImageActor> ImageActorX = vtkSmartPointer<vtkImageActor>::New();
    vtkSmartPointer<vtkImageActor> ImageActorY = vtkSmartPointer<vtkImageActor>::New();
    vtkSmartPointer<vtkImageActor> ImageActorZ = vtkSmartPointer<vtkImageActor>::New();
    Showdicom* showdm;
    Gpumake* gpm;
    vtkNew<vtkRenderer> renderer;
    vtkNew<vtkRenderer> rendererx;
    vtkNew<vtkRenderer> renderery;
    vtkNew<vtkRenderer> rendererz;
    std::string folder ;
    Gpuwidget *Gpuw;
    int pos[3];
   // vtkSmartPointer< PointPickerInteractorStyle > style = vtkSmartPointer< PointPickerInteractorStyle >::New();
    vtkImageMapToWindowLevelColors* windowLevelx = vtkImageMapToWindowLevelColors::New();
    vtkImageMapToWindowLevelColors* windowLevely = vtkImageMapToWindowLevelColors::New();
    vtkImageMapToWindowLevelColors* windowLevelz = vtkImageMapToWindowLevelColors::New();
    vtkSmartPointer<vtkTextActor> textActorx = vtkSmartPointer<vtkTextActor>::New();
    vtkSmartPointer<vtkTextActor> textActory = vtkSmartPointer<vtkTextActor>::New();
    vtkSmartPointer<vtkTextActor> textActorz = vtkSmartPointer<vtkTextActor>::New();
    vtkCellPicker* Picker;
    CropWidget *cropwidget=new CropWidget();
    bool flag;
    bool iniflag = true;
    void initiallize(std::string path);
    ~MainWidget();
private slots:
    void on_action_X_triggered();
    void on_openaction_triggered();
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int val);
    void on_cropaction_triggered();
    void on_actionvalue_triggered();
    void on_actionmax_triggered();
    void on_actionminvalue_triggered();
    void on_actionvalue_2_triggered();
    void on_actionvalue_max_triggered();
    void on_actionvalue_min_triggered();
    void on_actionslice_x_triggered();
    void on_actionslice_y_triggered();
    void on_actionslice_z_triggered();
    void on_actionAbout_triggered();
private:

    Ui::MainWidgetClass ui;
    

};

