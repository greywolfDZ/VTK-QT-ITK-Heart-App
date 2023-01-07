#include "CropWidget.h"
CropWidget::CropWidget( QWidget* parent) :QWidget(parent) {
	vtkOutputWindow::SetGlobalWarningDisplay(0);
	ui.setupUi(this);
	vtkRenderer* ren1 = vtkRenderer::New();
	//设置相机
	ren1->GetActiveCamera()->SetClippingRange(0.294421, 29.4421);
	ren1->GetActiveCamera()->SetDistance(7.94348);
	ren1->GetActiveCamera()->SetFocalPoint(-66.9367, -49.4539, 258.453);
	ren1->GetActiveCamera()->SetPosition(-67.8091, -57.3489, 258.377);
	ren1->GetActiveCamera()->SetViewAngle(20);
	ren1->GetActiveCamera()->SetViewUp(-0.82718, 0.0860684, 0.555306);
	ren1->GetActiveCamera()->SetParallelProjection(0);
	ren1->GetActiveCamera()->SetUseHorizontalViewAngle(0);
	ren1->SetBackground(0.1, 0.2, 0.4);
	ren1->SetLightFollowCamera(1);
	//创建绘制窗口
	//vtkRenderWindow* renWin = vtkRenderWindow::New();
	
	ui.qvtkWidget->GetRenderWindow()->AddRenderer(ren1);
	//创建交互器
	ui.qvtkWidget->GetRenderWindow()->GetInteractor()->SetLightFollowCamera(1);
	//读源对象读取stl数据文件
	vtkSTLReader* reader = vtkSTLReader::New();
    stlpath = "1.stl";
    reader->SetFileName(stlpath.c_str());
    reader->Update();
	//创建过滤器对象，该对象将输入数据集的每个单元向单元质心收缩
	//将会导致相邻单元之间出现裂缝
    vtkSmartPointer<vtkPlane> plane =
        vtkSmartPointer<vtkPlane>::New();
    plane->SetOrigin(1.0, 1.5, 2.0);
    plane->SetNormal(0.4, 0.2, 1.0);

    /* ================= Mapper ================= */

    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(reader->GetOutputPort());
    mapper->AddClippingPlane(plane);

    /* ================= Actor ================= */

    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);

    /* ================= Renderer ================= */

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);
    renderer->SetBackground(.0, .0, .0);

    /* ================= Window ================= */

   // vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();

    ui.qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
    /* ================= Interactor ================= */


    /* The callback will do the work */
  

    vtkSmartPointer<vtkImplicitPlaneRepresentation> rep =
        vtkSmartPointer<vtkImplicitPlaneRepresentation>::New();
    rep->SetPlaceFactor(1.25); // This must be set prior to placing the widget
    rep->PlaceWidget(actor->GetBounds());
    rep->SetNormal(plane->GetNormal());
    rep->SetOrigin(plane->GetOrigin());

    vtkSmartPointer<vtkImplicitPlaneWidget2> planeWidget =
        vtkSmartPointer<vtkImplicitPlaneWidget2>::New();
    planeWidget->SetInteractor(ui.qvtkWidget->GetRenderWindow()->GetInteractor());
    planeWidget->SetRepresentation(rep);

    planeWidget->On();

    /* ================= Run pipeline ================= */
 
   


    
    

}
void CropWidget::on_pushButton_2_clicked()
{

	vtkRenderer* ren1 = vtkRenderer::New();
	//设置相机
	ren1->GetActiveCamera()->SetClippingRange(0.294421, 29.4421);
	ren1->GetActiveCamera()->SetDistance(7.94348);
	ren1->GetActiveCamera()->SetFocalPoint(-66.9367, -49.4539, 258.453);
	ren1->GetActiveCamera()->SetPosition(-67.8091, -57.3489, 258.377);
	ren1->GetActiveCamera()->SetViewAngle(20);
	ren1->GetActiveCamera()->SetViewUp(-0.82718, 0.0860684, 0.555306);
	ren1->GetActiveCamera()->SetParallelProjection(0);
	ren1->GetActiveCamera()->SetUseHorizontalViewAngle(0);
	ren1->SetBackground(0.1, 0.2, 0.4);
	ren1->SetLightFollowCamera(1);
	//创建绘制窗口
	//vtkRenderWindow* renWin = vtkRenderWindow::New();

	ui.qvtkWidget->GetRenderWindow()->AddRenderer(ren1);
	//创建交互器
	ui.qvtkWidget->GetRenderWindow()->GetInteractor()->SetLightFollowCamera(1);
	//读源对象读取stl数据文件
	vtkSTLReader* reader = vtkSTLReader::New();
	stlpath = "2.stl";
	reader->SetFileName(stlpath.c_str());
	reader->Update();
	//创建过滤器对象，该对象将输入数据集的每个单元向单元质心收缩
	//将会导致相邻单元之间出现裂缝
	vtkSmartPointer<vtkPlane> plane =
		vtkSmartPointer<vtkPlane>::New();
	plane->SetOrigin(1.0, 1.5, 2.0);
	plane->SetNormal(0.4, 0.2, 1.0);

	/* ================= Mapper ================= */

	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(reader->GetOutputPort());
	mapper->AddClippingPlane(plane);

	/* ================= Actor ================= */

	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetOpacity(0.7);
	/* ================= Renderer ================= */

	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	renderer->AddActor(actor);
	renderer->SetBackground(.0, .0, .0);

	/* ================= Window ================= */

   // vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();

	ui.qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
	/* ================= Interactor ================= */


	/* The callback will do the work */


	vtkSmartPointer<vtkImplicitPlaneRepresentation> rep =
		vtkSmartPointer<vtkImplicitPlaneRepresentation>::New();
	rep->SetPlaceFactor(1.25); // This must be set prior to placing the widget
	rep->PlaceWidget(actor->GetBounds());
	rep->SetNormal(plane->GetNormal());
	rep->SetOrigin(plane->GetOrigin());

	vtkSmartPointer<vtkImplicitPlaneWidget2> planeWidget =
		vtkSmartPointer<vtkImplicitPlaneWidget2>::New();
	planeWidget->SetInteractor(ui.qvtkWidget->GetRenderWindow()->GetInteractor());
	planeWidget->SetRepresentation(rep);

	planeWidget->On();
}
void CropWidget::on_pushButton_clicked()
{



   // vtkSmartPointer<vtkPolyData> inputSurface = vtkSmartPointer<vtkPolyData>::New();
    //vtkSmartPointer<vtkPolyData> cappedSurface = vtkSmartPointer<vtkPolyData>::New();
	vtkSTLReader* part = vtkSTLReader::New();
	part->SetFileName("./1.stl");

	vtkPolyDataMapper* partMapper = vtkPolyDataMapper::New();
	partMapper->SetInputConnection(part->GetOutputPort());

	vtkLODActor* partActor = vtkLODActor::New();
	partActor->SetMapper(partMapper);
	partActor->GetProperty()->SetColor(0.8275, 0.8275, 0.8275);
	partActor->RotateX(0);
	partActor->RotateY(0);

	vtkRenderer* ren1 = vtkRenderer::New();
	ren1->AddActor(partActor);
	ren1->SetBackground(0.3, 0.3, 0.3);
	ren1->ResetCamera();
	ren1->GetActiveCamera()->Zoom(1.5);

	vtkRenderer* pRender1 = vtkRenderer::New();
	vtkRenderer* pRender2 = vtkRenderer::New();
	//vtkRenderWindow* pWin = vtkRenderWindow::New();
	//vtkRenderWindowInteractor* pInt = vtkRenderWindowInteractor::New();
	//pWin->SetSize(1200, 600);
	//pWin->AddRenderer(pRender1);
	//pWin->AddRenderer(ren1);
	//pWin->AddRenderer(pRender2);
	//ui.qvtkWidget->GetRenderWindow()->AddRenderer(pRender1);
	ui.qvtkWidget->GetRenderWindow()->AddRenderer(pRender2);
	ui.qvtkWidget->GetRenderWindow()->AddRenderer(ren1);
	//pRender1->SetViewport(0, 0, .5, 1);
	ren1->SetViewport(0, 0, .5, 1);
	pRender2->SetViewport(0.5, 0, 1, 1);
	pRender2->SetBackground(.3, .3, .3);
	
	//pInt->SetRenderWindow(pWin);


	std::string stl = "Untitled2.nii.gz";

	vtkSmartPointer<vtkNIFTIImageReader> pReader = vtkSmartPointer<vtkNIFTIImageReader>::New();
	pReader->SetFileName(stl.c_str());
	pReader->Update();

	double range[2];
	pReader->GetOutput()->GetScalarRange(range);
	vtkImageShiftScale* m_pShift = vtkImageShiftScale::New();
	m_pShift->SetShift(-1.0 * range[0]);
	m_pShift->SetScale(255.0 / (range[1] - range[0]));
	m_pShift->SetOutputScalarTypeToUnsignedChar();
	m_pShift->SetInputConnection(pReader->GetOutputPort());
	m_pShift->ReleaseDataFlagOff();
	m_pShift->Update();

	vtkFixedPointVolumeRayCastMapper* pMapper = vtkFixedPointVolumeRayCastMapper::New();
	pMapper->SetInputConnection(pReader->GetOutputPort()); //映射:第一步

	vtkColorTransferFunction* pColor = vtkColorTransferFunction::New(); //第二步:color
	pColor->AddRGBSegment(0, 1, 1, 1, 255, 1, 1, 1);

	vtkPiecewiseFunction* pPiceFun = vtkPiecewiseFunction::New();
	pPiceFun->AddSegment(0, 0, 3000, 1);//第三步: vtkPiecwise分段

	pMapper->SetBlendModeToMaximumIntensity();

	vtkVolumeProperty* pProperty = vtkVolumeProperty::New();//设置属性
	pProperty->SetColor(pColor);

	pProperty->SetScalarOpacity(pPiceFun);
	pProperty->SetInterpolationTypeToLinear();
	pProperty->ShadeOff();

	vtkVolume* pVolume = vtkVolume::New();
	pVolume->SetProperty(pProperty);
	pVolume->SetMapper(pMapper); //生成体对象

	ren1->AddVolume(pVolume); //增加体数据到渲染器中渲染


	vtkPlaneWidget* pWidget = vtkPlaneWidget::New();
	pWidget->SetInteractor(ui.qvtkWidget->GetRenderWindow()->GetInteractor());
	pWidget->SetInputData(m_pShift->GetOutput());
	pWidget->SetResolution(10);
	pWidget->GetPlaneProperty()->SetColor(.9, .4, .4);
	pWidget->GetHandleProperty()->SetColor(0, .4, .7);
	pWidget->GetHandleProperty()->SetLineWidth(1.5);
	pWidget->NormalToYAxisOn();
	pWidget->SetRepresentationToSurface();
	pWidget->SetPlaceFactor(1.0);
	pWidget->SetCenter(m_pShift->GetOutput()->GetCenter());
	pWidget->PlaceWidget();

	pWidget->On();


	vtkPlane* pPlane = vtkPlane::New();
	pPlane->SetOrigin(pReader->GetOutput()->GetCenter());
	pPlane->SetNormal(1, 0, 0);
	vtkCutter* pCut = vtkCutter::New();
	pCut->SetCutFunction(pPlane);
	pCut->SetInputConnection(m_pShift->GetOutputPort());
	pCut->Update();


	vtkPolyDataMapper* selectMapper = vtkPolyDataMapper::New();
	selectMapper->SetInputConnection(pCut->GetOutputPort());

	vtkActor* pActor = vtkActor::New();
	pActor->SetMapper(selectMapper);
	pRender2->AddActor(pActor);


	vtkWidgetCall* pCall = vtkWidgetCall::New();
	pCall->pPlane = pPlane;
	pWidget->AddObserver(vtkCommand::EndInteractionEvent, pCall);


  
   // ui.qvtkWidget->GetRenderWindow()->AddRenderer(xueguan->ren);
   // ui.qvtkWidget->GetRenderWindow()->GetInteractor()->SetInteractorStyle(xueguan->style);
   // xueguan->ExtractCenterline(stlpath.c_str(), inputSurface, cappedSurface);
  // ui.qvtkWidget->GetRenderWindow()->Render();
   
}
   

CropWidget::~CropWidget()
{

}
