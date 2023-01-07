#include "MainWidget.h"
#include <QVTKOpenGLNativeWidget.h>
#include <vtkDICOMImageReader.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkImageReSlice.h>
//#include <vtkImageResliceMapper.h>
#include <vtkImageReSliceMapper.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>
#include <vtkNew.h>
#include<vtkOutputWindow.h>


MainWidget::MainWidget(QWidget *parent)
    : QMainWindow(parent)
{
    flag = true;
    //vtkOutputWindow::SetGlobalWarningDisplay(0);
    ui.setupUi(this);   
    this->qvtkw = ui.qvtkWidget;
    ui.label_5->setText(std::to_string(ui.horizontalSlider->value()).c_str());
    ui.label_6->setText(std::to_string(ui.horizontalSlider_2->value()).c_str());
 
    ui.horizontalSlider->setRange(-1000,2000);
    ui.horizontalSlider_2->setRange(-400, 400);

}
void MainWidget::initiallize(std::string path)
{
    
    typedef short PixelType;
    const unsigned int   Dimension = 2;
    typedef itk::Image< PixelType, Dimension > Input2dImageType;
    typedef itk::Image< PixelType, 3 > Input3dImageType;

    typedef itk::Image< PixelType, Dimension > Output2dImageType;
    typedef itk::Image< PixelType, 3 > Output3dImageType;

    typedef itk::GDCMImageIO   ImageIOType;//GDCMImageIO读DICOM
    ImageIOType::Pointer gdcmImageIO = ImageIOType::New();

    using ReaderType3d = itk::ImageSeriesReader< Input3dImageType >;
    ReaderType3d::Pointer reader3d = ReaderType3d::New();

    typedef itk::ImageFileReader< Input2dImageType > ReaderType2d;
    ReaderType2d::Pointer reader2d = ReaderType2d::New();

    using NamesGeneratorType = itk::GDCMSeriesFileNames;
    NamesGeneratorType::Pointer nameGenerator = NamesGeneratorType::New();

    //std::string folder = "./CorCTA  0.75  B25f  Diastole 65%-unzip";

    gdcmImageIO->GetMetaDataDictionary();
    reader3d->SetImageIO(gdcmImageIO);
    nameGenerator->SetUseSeriesDetails(true);
    nameGenerator->SetDirectory(path.c_str());

    using SeriesIdContainer = std::vector< std::string >;
    const SeriesIdContainer& seriesUID = nameGenerator->GetSeriesUIDs();
    auto seriesItr = seriesUID.begin();
    auto seriesEnd = seriesUID.end();

    using FileNamesContainer = std::vector< std::string >;
    FileNamesContainer fileNames;
    std::string seriesIdentifier;
    while (seriesItr != seriesEnd)
    {
        seriesIdentifier = seriesItr->c_str();
        fileNames = nameGenerator->GetFileNames(seriesIdentifier);
        ++seriesItr;
    }
    reader3d->SetFileNames(fileNames);
    reader3d->Update();


    //ITK->VTK
    using IVFilterType = itk::ImageToVTKImageFilter<Input3dImageType>;
    IVFilterType::Pointer ivfilter = IVFilterType::New();
    ivfilter->SetInput(reader3d->GetOutput());
    ivfilter->Update();

    this->reader  = vtkSmartPointer< vtkImageFlip >::New();
    reader->SetInputData(ivfilter->GetOutput());
   // reader->SetFilteredAxes(1);
    reader->Update();

    try
    {
        reader3d->Update();
        reader3d->GetMetaDataDictionary();
        gdcmImageIO->GetMetaDataDictionary();// 读取头文件信息；

        //信息赋值
        char* name = new char[512];
        char* patientID = new char[512];
        char* time = new char[512];
        char* manufacture = new char[512];
        char* modility = new char[512];
        char* hospital = new char[512];
        char* sex = new char[512];
        char* age = new char[512];
        char* description = new char[512];

      //  int pixelType = gdcmImageIO->GetPixelType();
      //  int componentType = gdcmImageIO->GetComponentType();
      //  int fileType = gdcmImageIO->GetFileType();
        ImageIOType::ByteOrder byteOrder;
        byteOrder = gdcmImageIO->GetByteOrder();

        gdcmImageIO->GetPatientSex(sex);

        gdcmImageIO->GetPatientName(name);
       // ui.label_10->setText(name);
       gdcmImageIO->GetPatientAge(age);
        gdcmImageIO->GetStudyDescription(description);
        int spa = 0;
        gdcmImageIO->GetSpacing(spa);

        gdcmImageIO->GetModality(modility);
        gdcmImageIO->GetPatientID(patientID);
       gdcmImageIO->GetManufacturer(manufacture);
        gdcmImageIO->GetStudyDate(time);
        //ImageIOType::TCompressionType compressType;
        //compressType = gdcmImageIO->GetCompressionType();
        gdcmImageIO->GetInstitution(hospital);

       ui.label_21->setText(name);
       ui.label_24->setText(sex);
       ui.label_25->setText(age);
       ui.label_26->setText(patientID);
       ui.label_28->setText(modility);
       ui.label_29->setText(description);
       ui.label_30->setText(hospital);
       ui.label_23->setText(manufacture);



    }
    catch (const itk::ExceptionObject& excp)
    {

        return ;
    }
  





        this->showdm = new Showdicom(path);




    //this->gpm = new Gpumake(reader);
    vtkSmartPointer< vtkRenderWindow>pWin = vtkSmartPointer<vtkRenderWindow>::New();
    ui.qvtkWidget->SetRenderWindow(pWin);
    vtkNew<vtkRenderer> renderer;
    vtkNew<vtkRenderer> rendererx;
    vtkNew<vtkRenderer> renderery;
    vtkNew<vtkRenderer> rendererz;
    windowLevelx->SetInputConnection(this->showdm->imagePlaneX->GetReslice()->GetOutputPort());
    windowLevelx->SetLevel(100);
    windowLevelx->SetWindow(200);
    windowLevely->SetInputConnection(this->showdm->imagePlaneY->GetReslice()->GetOutputPort());
    windowLevely->SetLevel(100);
    windowLevely->SetWindow(200);
    windowLevelz->SetInputConnection(this->showdm->imagePlaneZ->GetReslice()->GetOutputPort());
    windowLevelz->SetLevel(100);
    windowLevelz->SetWindow(200);
    ImageActorX->GetMapper()->SetInputConnection(windowLevelx->GetOutputPort());
    ImageActorY->GetMapper()->SetInputConnection(windowLevely->GetOutputPort());
    ImageActorZ->GetMapper()->SetInputConnection(windowLevelz->GetOutputPort());

    rendererx->AddActor(this->ImageActorX);
    renderery->AddActor(this->ImageActorY);
    rendererz->AddActor(this->ImageActorZ);
    ui.qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
    rendererx->SetBackground(0.1, 0.2, 0.4);
    //rendererx->SetViewPort();
    rendererx->SetViewport(0, 0, 0.5, 0.5);
    renderery->SetViewport(0.5, 0, 1, 0.5);
    rendererz->SetViewport(0.5, 0.5, 1, 1);
    renderer->SetViewport(0, 0.5, 0.5, 1);
    renderery->SetBackground(0.2, 0.4, 0.1);
    rendererz->SetBackground(0.4, 0.2, 0.1);
    ui.qvtkWidget->GetRenderWindow()->AddRenderer(rendererx);
    ui.qvtkWidget->GetRenderWindow()->AddRenderer(renderery);
    ui.qvtkWidget->GetRenderWindow()->AddRenderer(rendererz);
    Picker = vtkCellPicker::New();
    Picker->SetTolerance(0.005);
    this->showdm->imagePlaneX->SetPicker(Picker);
    this->showdm->imagePlaneY->SetPicker(Picker);
    this->showdm->imagePlaneZ->SetPicker(Picker);
    vtkNew<vtkAxesActor> iconActor;
    this->showdm->orientationWidget->SetOrientationMarker(iconActor);
    this->showdm->orientationWidget->SetInteractor(ui.qvtkWidget->GetInteractor());
    this->showdm->imagePlaneX->SetDefaultRenderer(renderer);
    this->showdm->imagePlaneY->SetDefaultRenderer(renderer);
    this->showdm->imagePlaneZ->SetDefaultRenderer(renderer);
    this->showdm->imagePlaneX->SetInteractor(ui.qvtkWidget->GetInteractor());
    this->showdm->imagePlaneY->SetInteractor(ui.qvtkWidget->GetInteractor());
    this->showdm->imagePlaneZ->SetInteractor(ui.qvtkWidget->GetInteractor());

    // this->gpm->mcbk->RenderWindow = this->ui.qvtkWidget->GetRenderWindow();
     //ui.qvtkWidget->GetRenderWindow()->AddRenderer(this->gpm->aRenderer);

    vtkSmartPointer< vtkMyCallback > cbk = vtkSmartPointer< vtkMyCallback>::New();

    cbk->WidgetX = this->showdm->imagePlaneX;
    cbk->WidgetY = this->showdm->imagePlaneY;
    cbk->WidgetZ = this->showdm->imagePlaneZ;
    // rendererx->AddObserver(vtkCommand::MouseMoveEvent, cbk);
    // renderery->AddObserver(vtkCommand::MouseMoveEvent, cbk);
    // rendererz->AddObserver(vtkCommand::MouseMoveEvent, cbk);
    this->showdm->imagePlaneX->AddObserver(vtkCommand::EndWindowLevelEvent, cbk);
    this->showdm->imagePlaneY->AddObserver(vtkCommand::EndWindowLevelEvent, cbk);
    this->showdm->imagePlaneZ->AddObserver(vtkCommand::EndWindowLevelEvent, cbk);

    //cbk->Delete();

    this->showdm->imagePlaneX->On();
    this->showdm->imagePlaneY->On();
    this->showdm->imagePlaneZ->On();

    vtkAxesActor* axact = vtkAxesActor::New();
    axact->SetShaftTypeToCylinder();
    axact->SetXAxisLabelText("x");
    axact->SetYAxisLabelText("y");
    axact->SetZAxisLabelText("z");
    axact->SetTotalLength(0.2, 0.2, 0.2);
    vtkPropAssembly* prop = vtkPropAssembly::New();
    prop->AddPart(axact);
    vtkOrientationMarkerWidget* mark = vtkOrientationMarkerWidget::New();
    mark->SetOutlineColor(0, 0, 0);

    mark->SetOrientationMarker(prop);
    mark->SetInteractor(ui.qvtkWidget->GetInteractor());
    //mark->SetViewport(0, 0.5, 0.5, 1);
    mark->SetDefaultRenderer(renderer);
    mark->SetEnabled(1);
    mark->InteractiveOff();
    mark->EnabledOn();
    pos[0] = showdm->imagePlaneX->GetSliceIndex();
    pos[1] = showdm->imagePlaneY->GetSliceIndex();
    pos[2] = showdm->imagePlaneZ->GetSliceIndex();


    std::string strx = "x:" + std::to_string(pos[0]);
    std::string stry = "y:" + std::to_string(pos[1]);
    std::string strz = "z:" + std::to_string(pos[2]);
    textActorx->SetInput(strx.c_str());
    textActorx->GetTextProperty()->SetFontSize(24);
    textActorx->GetTextProperty()->SetColor(1, 1, 1);
    rendererx->AddActor(textActorx);
    textActory->SetInput(stry.c_str());
    textActory->GetTextProperty()->SetFontSize(24);
    textActory->GetTextProperty()->SetColor(1, 1, 1);
    renderery->AddActor(textActory);
    textActorz->SetInput(strx.c_str());
    textActorz->GetTextProperty()->SetFontSize(24);
    textActorz->GetTextProperty()->SetColor(1, 1, 1);
    rendererz->AddActor(textActorz);

    vtkSmartPointer< vtkMyCall > mycall = vtkSmartPointer< vtkMyCall>::New();
    mycall->pos = pos;
    mycall->WidgetX = showdm->imagePlaneX;
    mycall->WidgetY = showdm->imagePlaneY;
    mycall->WidgetZ = showdm->imagePlaneZ;
    mycall->textActorx = textActorx;
    mycall->textActory = textActory;
    mycall->textActorz = textActorz;
    this->ui.qvtkWidget->GetInteractor()->AddObserver(vtkCommand::MouseMoveEvent, mycall);

    Gpuw = new Gpuwidget(reader);
    // Gpuw->gpumak = new Gpumake(reader);
}
void MainWidget::on_horizontalSlider_valueChanged(int val)
{
    
    
    windowLevelx->SetWindow(val);
    windowLevely->SetWindow(val);
    windowLevelz->SetWindow(val);
    windowLevelx->Update();
    windowLevely->Update();
    windowLevelz->Update();
    ui.qvtkWidget->GetRenderWindow()->Render();
    ui.label_5->setText(std::to_string(val).c_str());
}
void MainWidget::on_horizontalSlider_2_valueChanged(int val)
{

    //ui.label_4->setText(std::to_string(val).c_str());
    windowLevelx->SetLevel(val);
    windowLevely->SetLevel(val);
    windowLevelz->SetLevel(val);
    windowLevelx->Update();
    windowLevely->Update();
    windowLevelz->Update();
    ui.qvtkWidget->GetRenderWindow()->Render();
    ui.label_6->setText(std::to_string(val).c_str());
}
void MainWidget::on_openaction_triggered()
{
    flag = true;
    QString dirpath = QFileDialog::getExistingDirectory(this, "Open Dir", "./", QFileDialog::ShowDirsOnly);//打开D盘study文件夹

    if (dirpath == "")
        return;
    std::string str = "HeartApp ---" + dirpath.toStdString();
    this->setWindowTitle(str.c_str());
    if (iniflag)
    {
        try {
            initiallize(dirpath.toStdString());
            this->folder = dirpath.toStdString();
            iniflag = false;
            
        }
        catch(const itk::ExceptionObject& excp) { 
            QMessageBox::warning(this, "error path", "No such path or error load dicom image");
            return;
        }
        iniflag = false;
        return;
    }
    try
    {
 
        //std::string folder = dirpath.toStdString();
        this->folder= dirpath.toStdString();
        typedef short PixelType;
        const unsigned int   Dimension = 2;
        typedef itk::Image< PixelType, Dimension > Input2dImageType;
        typedef itk::Image< PixelType, 3 > Input3dImageType;

        typedef itk::Image< PixelType, Dimension > Output2dImageType;
        typedef itk::Image< PixelType, 3 > Output3dImageType;

        typedef itk::GDCMImageIO   ImageIOType;//GDCMImageIO读DICOM
        ImageIOType::Pointer gdcmImageIO = ImageIOType::New();

        using ReaderType3d = itk::ImageSeriesReader< Input3dImageType >;
        ReaderType3d::Pointer reader3d = ReaderType3d::New();

        typedef itk::ImageFileReader< Input2dImageType > ReaderType2d;
        ReaderType2d::Pointer reader2d = ReaderType2d::New();

        using NamesGeneratorType = itk::GDCMSeriesFileNames;
        NamesGeneratorType::Pointer nameGenerator = NamesGeneratorType::New();


        gdcmImageIO->GetMetaDataDictionary();
        reader3d->SetImageIO(gdcmImageIO);
        nameGenerator->SetUseSeriesDetails(true);
        nameGenerator->SetDirectory(folder.c_str());

        using SeriesIdContainer = std::vector< std::string >;
        const SeriesIdContainer& seriesUID = nameGenerator->GetSeriesUIDs();
        auto seriesItr = seriesUID.begin();
        auto seriesEnd = seriesUID.end();

        using FileNamesContainer = std::vector< std::string >;
        FileNamesContainer fileNames;
        std::string seriesIdentifier;
        while (seriesItr != seriesEnd)
        {
            seriesIdentifier = seriesItr->c_str();
            fileNames = nameGenerator->GetFileNames(seriesIdentifier);
            ++seriesItr;
        }
        reader3d->SetFileNames(fileNames);
        reader3d->Update();


        //ITK->VTK
        using IVFilterType = itk::ImageToVTKImageFilter<Input3dImageType>;
        IVFilterType::Pointer ivfilter = IVFilterType::New();
        ivfilter->SetInput(reader3d->GetOutput());
        ivfilter->Update();


        reader->SetInputData(ivfilter->GetOutput());
       reader->SetFilteredAxes(1);
        reader->Update();

        try
        {
            reader3d->Update();
            reader3d->GetMetaDataDictionary();
            gdcmImageIO->GetMetaDataDictionary();// 读取头文件信息；

            //信息赋值
            char* name = new char[512];
            char* patientID = new char[512];
            char* time = new char[512];
            char* manufacture = new char[512];
            char* modility = new char[512];
            char* hospital = new char[512];
            char* sex = new char[512];
            char* age = new char[512];
            char* description = new char[512];

            //  int pixelType = gdcmImageIO->GetPixelType();
            //  int componentType = gdcmImageIO->GetComponentType();
            //  int fileType = gdcmImageIO->GetFileType();
            ImageIOType::ByteOrder byteOrder;
            byteOrder = gdcmImageIO->GetByteOrder();

            gdcmImageIO->GetPatientSex(sex);

            gdcmImageIO->GetPatientName(name);
            // ui.label_10->setText(name);
            gdcmImageIO->GetPatientAge(age);
            gdcmImageIO->GetStudyDescription(description);
            int spa = 0;
            gdcmImageIO->GetSpacing(spa);

            gdcmImageIO->GetModality(modility);
            gdcmImageIO->GetPatientID(patientID);
            gdcmImageIO->GetManufacturer(manufacture);
            gdcmImageIO->GetStudyDate(time);
            //ImageIOType::TCompressionType compressType;
            //compressType = gdcmImageIO->GetCompressionType();
            gdcmImageIO->GetInstitution(hospital);

            ui.label_21->setText(name);
            ui.label_24->setText(sex);
            ui.label_25->setText(age);
            ui.label_26->setText(patientID);
            ui.label_28->setText(modility);
            ui.label_29->setText(description);
            ui.label_30->setText(hospital);
            ui.label_23->setText(manufacture);



        }
        catch (const itk::ExceptionObject& excp)
        {
            cout << " Reading Exceptaion Caught" << endl;
            cout << excp.what() << endl;

            return;
        }



      



       this->showdm->reader->SetDirectoryName(folder.c_str());
       // this->showdm->reader->SetInputData(dicomreader->GetOutput());
        this->showdm->reader->Update();
        ui.qvtkWidget->GetRenderWindow()->Render();
        Gpuw->reader->SetInputData(reader->GetOutput());
        Gpuw->reader->Update();
    }
    catch (const itk::ExceptionObject& excp)
    {
        QMessageBox::warning(this,"error path", "No such path or error load dicom image");
        return;
    }

    

   // ui.label_4->setText(name.c_str());
   // ui.label_10->setText(ID.c_str());
}
void MainWidget::on_action_X_triggered()
{
    delete(Gpuw);
    Gpuw = new Gpuwidget(reader);
   // 
  //  pos[1] = showdm->imagePlaneX->GetSliceIndex();
  //  std::string str = std::to_string(pos[1]) ;
   // ui.label_24->setText(str.c_str());
   Gpuw->reader->SetInputData(reader->GetOutput());
   Gpuw->reader->Update();
   Gpuw->update();
   Gpuw->show();

}
void MainWidget::on_cropaction_triggered()
{


    if (flag)
    {
        delete(cropwidget);
        cropwidget = new CropWidget();
        QDialog* dialog = new QDialog(this);
        //当主窗口不关闭，即不进行析构时，多次打开关闭对话框会导致内存泄漏
        dialog->setAttribute(Qt::WA_DeleteOnClose);//防止内存泄漏
        dialog->resize(500, 20);
    
        //dialog->setToolTip("segmenting images,please waiting...");
        //dialog->setWindowIcon(QIcon(":new/texture/Images/Sunny.jpg"));
       dialog->setWindowTitle("segmenting images,please waiting...");
        dialog->show();
        rawreader->SetInputData(reader->GetOutput());
        rawreader->Update();

        vtkSmartPointer<vtkImageCast> imgCast =
            vtkSmartPointer<vtkImageCast>::New();
        imgCast->SetInputData((vtkDataObject*)reader->GetOutput());
        imgCast->SetOutputScalarTypeToFloat();
        imgCast->Update();


        //类型转换
        typedef   float           InternalPixelType;
        const     unsigned int    Dimension = 3;
        typedef itk::Image< InternalPixelType, Dimension >  InternalImageType;

        typedef unsigned char                            OutputPixelType;
        typedef itk::Image< OutputPixelType, Dimension > OutputImageType;

        typedef itk::CastImageFilter< InternalImageType, OutputImageType >
            CastingFilterType;
        CastingFilterType::Pointer caster = CastingFilterType::New();
        using VIfiltertype = itk::VTKImageToImageFilter<InternalImageType>;
        VIfiltertype::Pointer vifilter = VIfiltertype::New();

            typedef  itk::ImageFileReader< InternalImageType > ReaderType;
        typedef  itk::ImageFileWriter<  OutputImageType  > WriterType;

        //ReaderType::Pointer itkreader = ReaderType::New();
        WriterType::Pointer writer = WriterType::New();

        typedef itk::MetaImageIO             ImageIOType;
        ImageIOType::Pointer metaIO = ImageIOType::New();
       // itkreader->SetImageIO(metaIO);
       // writer->SetImageIO(metaIO);
       // itkreader->SetFileName("D:/pythonProject5/Heart3.mha");
       // writer->SetFileName("D:/Example-Data/TONTATIX/Heart_3.mha");
        vifilter->SetInput(imgCast->GetOutput());
          typedef itk::CurvatureFlowImageFilter< InternalImageType, InternalImageType >
            CurvatureFlowImageFilterType;
        CurvatureFlowImageFilterType::Pointer smoothing =
            CurvatureFlowImageFilterType::New();

        typedef itk::ConfidenceConnectedImageFilter<InternalImageType, InternalImageType>
            ConnectedFilterType;
        ConnectedFilterType::Pointer confidenceConnected = ConnectedFilterType::New();
        
        smoothing->SetInput(vifilter->GetOutput());
         confidenceConnected->SetInput(smoothing->GetOutput());
        //caster->SetInput(confidenceConnected->GetOutput());
        //writer->SetInput(caster->GetOutput());

        smoothing->SetNumberOfIterations(2);//
        smoothing->SetTimeStep(0.05);//每步迭代时间
        smoothing->Update();
        confidenceConnected->SetMultiplier(1.7);//；设置乘法因子f 2.5  可调
        confidenceConnected->SetNumberOfIterations(5);//设置迭代次数为5（迭代器数目）
        confidenceConnected->SetInitialNeighborhoodRadius(1);//设置领域范围为2
        confidenceConnected->SetReplaceValue(255);

        //设置种子点1
        InternalImageType::IndexType index1;
        index1[0] = pos[0];//X 轴
        index1[1] = pos[1];//Y 轴
        index1[2] = pos[2];//Z 轴 （第几个切片）
        confidenceConnected->AddSeed(index1);

        ////设置种子点1
        //InternalImageType::IndexType index2;
        //index2[0] = 160;//X 轴
        //index2[1] = 278;//Y 轴
        //index2[2] = 58;//Z 轴 （第几个切片）
        //confidenceConnected->AddSeed(index2);

        confidenceConnected->Update();
        
         typedef itk::BinaryBallStructuringElement<InternalImageType::InternalPixelType, Dimension>
            StructuringElementType;
        StructuringElementType structuringElement;
        structuringElement.SetRadius(20);
        structuringElement.CreateStructuringElement();

        typedef itk::BinaryMorphologicalClosingImageFilter <InternalImageType, InternalImageType, StructuringElementType>//形态学闭包
            BinaryMorphologicalClosingImageFilterType;
        BinaryMorphologicalClosingImageFilterType::Pointer closingFilter
            = BinaryMorphologicalClosingImageFilterType::New();
        closingFilter->SetInput(confidenceConnected->GetOutput());
        closingFilter->SetKernel(structuringElement);
        closingFilter->Update();
        
        //ITK->VTK

        using IVFilterType = itk::ImageToVTKImageFilter<InternalImageType>;
        IVFilterType::Pointer ivfilter = IVFilterType::New();
        ivfilter->SetInput(confidenceConnected->GetOutput());
        ivfilter->Update();
       
        showdm->reader2->SetInputData(ivfilter->GetOutput());
        showdm->reader2->Update();
        showdm->TovtkImageFlip();
        
        dialog->close();
        delete(dialog);
        reader->SetInputData(ivfilter->GetOutput());
        delete(Gpuw->gpumak);
        Gpuw->gpumak = new Gpumake(reader);
        flag = false;
        
        cropwidget->show(); 
        
    }
    else
    {
        reader->SetInputData(rawreader->GetOutput());
        reader->Update();
        this->showdm->reader->SetDirectoryName(this->folder.c_str());
        this->showdm->reader->Update();
        this->showdm->TovtkDICOMImageReader();

        Gpuw->gpumak = new Gpumake(reader);
        flag = true;
    }
   

}

void MainWidget::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About", "The main functions of this APP are as follows: \n1. Medical image reading and three-view display \n2. Segmentation based on seed points \n3.3D volume rendering\n4.Vascular centerline extraction\n5.Vascular cross-sectional display\nAuthor: Medical image visualization team");
}
void MainWidget::on_actionvalue_triggered()
{//窗宽值
    bool bOk = false;
    double dbWeight = QInputDialog::getDouble(this,
        "Input",
        "Please input window value",
        ui.horizontalSlider->value(),		//默认值
        -2147483647.0,			//最小值
        2147483647.0,		//最大值
        2,			//精确到小数点后几位
        &bOk);

    ui.horizontalSlider->setValue(dbWeight);

}
void MainWidget::on_actionmax_triggered()
{//窗宽max
    bool bOk = false;
    double dbWeight = QInputDialog::getDouble(this,
        "Input",
        "Please input the maximum value of window slider",
        ui.horizontalSlider->maximum(),		//默认值
        -2147483647.0,			//最小值
        2147483647.0,		//最大值
        2,			//精确到小数点后几位
        &bOk);
    if (dbWeight > ui.horizontalSlider->minimum())
        ui.horizontalSlider->setMaximum(dbWeight);
    else
        QMessageBox::warning(this, "Error Value", "Should be larger than the minimum value set now");
}
void MainWidget::on_actionminvalue_triggered()
{//窗宽min
    bool bOk = false;
    double dbWeight = QInputDialog::getDouble(this,
        "Input",
        "Please input the minimum value of window slider",
        ui.horizontalSlider->minimum(),		//默认值
        -2147483647.0,			//最小值
        2147483647.0,		//最大值
        2,			//精确到小数点后几位
        &bOk);
    if (dbWeight < ui.horizontalSlider->maximum())
        ui.horizontalSlider->setMinimum(dbWeight);
    else
        QMessageBox::warning(this, "Error Value", "Should be lower than the maximum value you set now");
}
void MainWidget::on_actionvalue_2_triggered()
{//窗宽值
    bool bOk = false;
    double dbWeight = QInputDialog::getDouble(this,
        "Input",
        "Please input level value ",
        ui.horizontalSlider_2->value(),		//默认值
        -2147483647.0,			//最小值
        2147483647.0,		//最大值
        2,			//精确到小数点后几位
        &bOk);

    ui.horizontalSlider_2->setValue(dbWeight);

}
void MainWidget::on_actionvalue_max_triggered()
{//窗宽max
    bool bOk = false;
    double dbWeight = QInputDialog::getDouble(this,
        "Input",
        "Please input the maximum value of level slider",
        ui.horizontalSlider_2->maximum(),		//默认值
        -2147483647.0,			//最小值
        2147483647.0,		//最大值
        2,			//精确到小数点后几位
        &bOk);
    if (dbWeight > ui.horizontalSlider_2->minimum())
        ui.horizontalSlider_2->setMaximum(dbWeight);
    else
        QMessageBox::warning(this, "Error Value", "Should be larger than the minimum value set now");
}
void MainWidget::on_actionvalue_min_triggered()
{//窗宽min
    bool bOk = false;
    double dbWeight = QInputDialog::getDouble(this,
        "Input",
        "Please input the minimum value of level slider",
        ui.horizontalSlider_2->minimum(),		//默认值
        -2147483647.0,			//最小值
        2147483647.0,		//最大值
        2,			//精确到小数点后几位
        &bOk);
    if (dbWeight < ui.horizontalSlider_2->maximum())
        ui.horizontalSlider_2->setMinimum(dbWeight);
    else
        QMessageBox::warning(this, "Error Value", "Should be lower than the maximum value you set now");
}
void MainWidget::on_actionslice_x_triggered()
{
    bool bOk = false;
    int dbWeight = QInputDialog::getInt(this,
        "Input",
        "Please input the minimum value of level slider",
        pos[0],		//默认值
        0,			//最小值
        1000,		//最大值
        2,			//步进
        &bOk);
    showdm->imagePlaneX->SetSliceIndex(dbWeight);
    pos[0] = dbWeight;
    std::string strx = "x:" + std::to_string(pos[0]);
    textActorx->SetInput(strx.c_str());
}
void MainWidget::on_actionslice_y_triggered()
{
    bool bOk = false;
    int dbWeight = QInputDialog::getInt(this,
        "Input",
        "Please input the minimum value of level slider",
        pos[1],		//默认值
        0,			//最小值
        1000,		//最大值
        2,			//步进
        &bOk);
    showdm->imagePlaneY->SetSliceIndex(dbWeight);
    pos[1] = dbWeight;
    std::string stry = "y:" + std::to_string(pos[1]);
    textActorx->SetInput(stry.c_str());
   
}
void MainWidget::on_actionslice_z_triggered()
{
    bool bOk = false;
    int dbWeight = QInputDialog::getInt(this,
        "Input",
        "Please input the minimum value of level slider",
        pos[2],		//默认值
        0,			//最小值
        1000,		//最大值
        2,			//步进
        &bOk);
    showdm->imagePlaneZ->SetSliceIndex(dbWeight);
    pos[2] = dbWeight;
    std::string strz = "z:" + std::to_string(pos[2]);
    textActorx->SetInput(strz.c_str());
}
MainWidget::~MainWidget()
{
    
}
