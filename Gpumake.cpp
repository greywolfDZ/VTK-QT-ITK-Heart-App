#include "Gpumake.h"

//����Ƽ���

//Gpu����ӳ��

Gpumake::Gpumake(vtkSmartPointer<vtkImageFlip> reader)
{
	vtkSmartPointer<vtkPointHandleRepresentation3D> handle = vtkSmartPointer<vtkPointHandleRepresentation3D>::New();
	vtkDistanceRepresentation2D* rep = vtkDistanceRepresentation2D::New();
	vtkSmartPointer<vtkHandleWidget> handlewidget = vtkSmartPointer<vtkHandleWidget>::New();
	
	rep->SetHandleRepresentation(handle);
	rep->GetAxis()->SetTickLength(9);

	//�����������
	//ָ��ָ�룻








	//���ò�͸���ȴ��ݺ�������Ϊһά�ֶδ��亯��
	vtkSmartPointer<vtkPiecewiseFunction> opacityTransferFunction =
		vtkSmartPointer<vtkPiecewiseFunction>::New();
	opacityTransferFunction->AddPoint(10, 0.0);//�Ҷ�ֵ����͸����ֵ
	opacityTransferFunction->AddPoint(50, 0.1);
	//opacityTransferFunction->AddPoint(20, 0.0);
	opacityTransferFunction->AddPoint(255, 0.5);
	//opacityTransferFunction->AddPoint(200, 0.6);
	opacityTransferFunction->AddPoint(1000, 0.7);

	//������ɫ���ݺ���
	vtkSmartPointer<vtkColorTransferFunction> colorTransferFunction =
		vtkSmartPointer<vtkColorTransferFunction>::New();
	colorTransferFunction->AddRGBPoint(0.0, 0.0, 0.5, 0.0);
	colorTransferFunction->AddRGBPoint(60.0, 1.0, 0.0, 0.0);
	//colorTransferFunction->AddRGBPoint(128.0, 0.2, 0.1, 0.9);
	colorTransferFunction->AddRGBPoint(196.0, 0.5, 0.21, 0.1);
	colorTransferFunction->AddRGBPoint(255.0, 0.8, 0.8, 0.8);

	//�����ݶȱ任����
	vtkPiecewiseFunction* gradient = vtkPiecewiseFunction::New();
	gradient->AddPoint(20, .2);//�Ҷ�ֵ�仯�ݶ��벻͸���ȵĹ�ϵ
	gradient->AddPoint(255, .7);
	gradient->AddPoint(2000, .7);

	vtkSmartPointer<vtkVolumeProperty> volumeProperty =
		vtkSmartPointer<vtkVolumeProperty>::New();
	//�趨��Ⱦ����
	volumeProperty->SetColor(colorTransferFunction);//���亯����ɫ
	volumeProperty->SetScalarOpacity(opacityTransferFunction);//���亯����͸����
	volumeProperty->SetGradientOpacity(gradient);//�����ݶ�ӳ��
	volumeProperty->SetInterpolationTypeToLinear();//������ֵ����
	volumeProperty->ShadeOn();//��Ӱ	
	volumeProperty->SetAmbient(0.5);//������
	volumeProperty->SetDiffuse(0.6);//������
	volumeProperty->SetSpecular(0.6);//�߹�ϵ��
	volumeProperty->SetSpecularPower(10); //�߹�ǿ�� 

	//������ȾMapper
	vtkSmartPointer<vtkFixedPointVolumeRayCastMapper> volumeMapper2 =
		vtkSmartPointer<vtkFixedPointVolumeRayCastMapper>::New();
	volumeMapper2->SetInputConnection(reader->GetOutputPort());
	vtkSmartPointer<vtkVolume> volume =
		vtkSmartPointer<vtkVolume>::New();
	//����������vtkActor
	//����������vtVolume
	volume->SetMapper(volumeMapper2);
	volume->SetProperty(volumeProperty);




	aRenderer->AddVolume(volume);
	//aRenderer->AddActor(outline);
	aRenderer->SetBackground(1, 1, 1);
	aRenderer->ResetCamera();

	//��������ļ��з�Χ��
	aRenderer->ResetCameraClippingRange();

	widget->SetRepresentation(rep);
	
	//mcbk->Renderer = aRenderer;
	//mcbk->RenderWindow = renWin;
	//mcbk->Distance = rep;
	//mcbk->DistanceWidget = widget;



	widget->On();

}
