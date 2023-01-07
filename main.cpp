#include "MainWidget.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include<Windows.h>
#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingFreeType)
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2)
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.setWindowTitle("HeartApp");
    w.show();

    
    return a.exec();
}
