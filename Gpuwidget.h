#pragma once
#include <qwidget.h>
#include<QVTKWidget.h>
#include"Gpumake.h"
#include"ui_Widget.h"
#include<vtkOutputWindow.h>
#include<vtkImageFlip.h>
#include<vtkImageData.h>
class Gpuwidget :
    public QWidget
{
public:
    QVTKWidget* qvtkwidget;
    vtkSmartPointer <vtkImageFlip> reader;
    Gpuwidget(  vtkSmartPointer<vtkImageFlip> reader1,QWidget* parent = nullptr );
    Gpumake* gpumak;
    ~Gpuwidget();
private:
    Ui::Form ui;
};

