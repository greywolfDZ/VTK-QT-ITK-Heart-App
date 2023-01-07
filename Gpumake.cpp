#include "Gpumake.h"

//体绘制加速

//Gpu光照映射

Gpumake::Gpumake(vtkSmartPointer<vtkImageFlip> reader)
{
	vtkSmartPointer<vtkPointHandleRepresentation3D> handle = vtkSmartPointer<vtkPointHandleRepresentation3D>::New();
	vtkDistanceRepresentation2D* rep = vtkDistanceRepresentation2D::New();
	vtkSmartPointer<vtkHandleWidget> handlewidget = vtkSmartPointer<vtkHandleWidget>::New();
	
	rep->SetHandleRepresentation(handle);
	rep->GetAxis()->SetTickLength(9);

	//定义绘制器；
	//指向指针；








	//设置不透明度传递函数，此为一维分段传输函数
	vtkSmartPointer<vtkPiecewiseFunction> opacityTransferFunction =
		vtkSmartPointer<vtkPiecewiseFunction>::New();
	opacityTransferFunction->AddPoint(10, 0.0);//灰度值及不透明度值
	opacityTransferFunction->AddPoint(50, 0.1);
	//opacityTransferFunction->AddPoint(20, 0.0);
	opacityTransferFunction->AddPoint(255, 0.5);
	//opacityTransferFunction->AddPoint(200, 0.6);
	opacityTransferFunction->AddPoint(1000, 0.7);

	//设置颜色传递函数
	vtkSmartPointer<vtkColorTransferFunction> colorTransferFunction =
		vtkSmartPointer<vtkColorTransferFunction>::New();
	colorTransferFunction->AddRGBPoint(0.0, 0.0, 0.5, 0.0);
	colorTransferFunction->AddRGBPoint(60.0, 1.0, 0.0, 0.0);
	//colorTransferFunction->AddRGBPoint(128.0, 0.2, 0.1, 0.9);
	colorTransferFunction->AddRGBPoint(196.0, 0.5, 0.21, 0.1);
	colorTransferFunction->AddRGBPoint(255.0, 0.8, 0.8, 0.8);

	//设置梯度变换函数
	vtkPiecewiseFunction* gradient = vtkPiecewiseFunction::New();
	gradient->AddPoint(20, .2);//灰度值变化梯度与不透明度的关系
	gradient->AddPoint(255, .7);
	gradient->AddPoint(2000, .7);

	vtkSmartPointer<vtkVolumeProperty> volumeProperty =
		vtkSmartPointer<vtkVolumeProperty>::New();
	//设定渲染属性
	volumeProperty->SetColor(colorTransferFunction);//传输函数颜色
	volumeProperty->SetScalarOpacity(opacityTransferFunction);//传输函数不透明度
	volumeProperty->SetGradientOpacity(gradient);//载入梯度映射
	volumeProperty->SetInterpolationTypeToLinear();//函数插值方法
	volumeProperty->ShadeOn();//阴影	
	volumeProperty->SetAmbient(0.5);//环境光
	volumeProperty->SetDiffuse(0.6);//漫反射
	volumeProperty->SetSpecular(0.6);//高光系数
	volumeProperty->SetSpecularPower(10); //高光强度 

	//定义渲染Mapper
	vtkSmartPointer<vtkFixedPointVolumeRayCastMapper> volumeMapper2 =
		vtkSmartPointer<vtkFixedPointVolumeRayCastMapper>::New();
	volumeMapper2->SetInputConnection(reader->GetOutputPort());
	vtkSmartPointer<vtkVolume> volume =
		vtkSmartPointer<vtkVolume>::New();
	//几何数据是vtkActor
	//而体数据是vtVolume
	volume->SetMapper(volumeMapper2);
	volume->SetProperty(volumeProperty);




	aRenderer->AddVolume(volume);
	//aRenderer->AddActor(outline);
	aRenderer->SetBackground(1, 1, 1);
	aRenderer->ResetCamera();

	//重设相机的剪切范围；
	aRenderer->ResetCameraClippingRange();

	widget->SetRepresentation(rep);
	
	//mcbk->Renderer = aRenderer;
	//mcbk->RenderWindow = renWin;
	//mcbk->Distance = rep;
	//mcbk->DistanceWidget = widget;



	widget->On();

}
