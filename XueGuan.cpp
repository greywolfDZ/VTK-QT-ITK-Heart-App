#include "XueGuan.h"
XueGuan::XueGuan() {

}
vtkSmartPointer<vtkImageData> XueGuan::GetDICOMPolyData(string fileName)
{
    using ImageType = itk::Image<signed short, 3>; //多张dcm图片时

    itk::ImageSeriesReader< ImageType >::Pointer reader = itk::ImageSeriesReader< ImageType >::New();
    itk::GDCMImageIO::Pointer docomIO = itk::GDCMImageIO::New();
    reader->SetImageIO(docomIO);

    itk::GDCMSeriesFileNames::Pointer nameGenerator = itk::GDCMSeriesFileNames::New();
    nameGenerator->SetDirectory(fileName);

    std::vector< std::string > DICOMNames = nameGenerator->GetInputFileNames();
    reader->SetFileNames(DICOMNames);
    reader->Update();

    typedef itk::ImageToVTKImageFilter< ImageType> itkTovtkFilterType;
    itkTovtkFilterType::Pointer itkTovtkImageFilter = itkTovtkFilterType::New();
    itkTovtkImageFilter->SetInput(reader->GetOutput());
    itkTovtkImageFilter->Update();

    vtkSmartPointer<vtkImageData> imagedata = vtkSmartPointer<vtkImageData>::New();
    imagedata->DeepCopy(itkTovtkImageFilter->GetOutput());
    return imagedata;
}


void XueGuan::ReadSurface(string surfacePath, vtkPolyData* surface)
{
    // read surface
    vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
    reader->SetFileName(surfacePath.c_str());
    reader->Update();
    surface->DeepCopy(reader->GetOutput());
    surface->UpdatePointGhostArrayCache();
}

void XueGuan::ExtractCenterline(string surfacePath, vtkPolyData* inputSurface, vtkPolyData* cappedSurface)
{
    // read surface file
    ReadSurface(surfacePath, inputSurface);
    
    // capping
    vtkSmartPointer<vtkvmtkCapPolyData> capper = vtkSmartPointer<vtkvmtkCapPolyData>::New();
    capper->SetInputData(inputSurface);
    capper->Update();
    
    //清理
    vtkSmartPointer<vtkCleanPolyData> cleaner = vtkSmartPointer<vtkCleanPolyData>::New();
    cleaner->SetInputData(capper->GetOutput());
    cleaner->Update();

    //三角化
    vtkSmartPointer<vtkTriangleFilter> triangulator = vtkSmartPointer<vtkTriangleFilter>::New();
    triangulator->SetInputData(cleaner->GetOutput());
    triangulator->PassLinesOff();
    triangulator->PassVertsOff();
    triangulator->Update();
    
    int numberOfPolys = triangulator->GetOutput()->GetNumberOfPolys();
    //        std::cout << "There are " << triangulator->GetOutput()->GetNumberOfPolys() << " polygons." << std::endl;

            //如果 poly number 不超过 3e4，不需要数据抽取
    if (numberOfPolys < 30000)
        cappedSurface->DeepCopy(triangulator->GetOutput());
    else
    {
        //三角数据减少 (1-3e4/numberOfPolys)*100% ，加快计算
        vtkSmartPointer<vtkDecimatePro> decimate = vtkSmartPointer<vtkDecimatePro>::New();
        decimate->SetInputConnection(triangulator->GetOutputPort());
        decimate->SetTargetReduction(1 - 3e4 / (float)numberOfPolys);    //0.95
        decimate->PreserveTopologyOn();
        decimate->Update();

        cappedSurface->DeepCopy(decimate->GetOutput());
    }

    cout << "The number of the holes is:" << capper->GetCapCenterIds()->GetNumberOfIds() << endl;

    vtkSmartPointer<vtkPolyDataMapper> surfaceMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    surfaceMapper->SetInputData(triangulator->GetOutput());
    vtkSmartPointer<vtkActor> surfaceActor = vtkSmartPointer<vtkActor>::New();
    surfaceActor->SetMapper(surfaceMapper);

    // put the actor into render window
   
    ren->AddActor(surfaceActor);

    vtkSmartPointer<vtkPolyData> centerline = vtkSmartPointer<vtkPolyData>::New();
    //        vtkSmartPointer<vtkPolyDataMapper> centerlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    //        centerlineMapper->SetInputData(centerline);
    //        vtkSmartPointer<vtkActor> centerlineActor = vtkSmartPointer<vtkActor>::New();
    //        centerlineActor->SetMapper(centerlineMapper);
    //        ren->AddActor(centerlineActor);

    vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();
    renWin->AddRenderer(ren);
    renWin->SetSize(1920, 1080);

    vtkSmartPointer<vtkRenderWindowInteractor> iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
   
   iren->SetInteractorStyle(style);
    iren->SetRenderWindow(renWin);
    style->SetSurface(cappedSurface);
    style->SetCenterline(centerline);

    iren->Initialize();
    renWin->Render();
    ren->ResetCamera();
    iren->Start();
   
}
