#include "mainwindow.h"
/*显示线程*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*界面编程*/
    stop = 0;
    ok = new QPushButton("Start");  //初始化按键的初值
    cap = new QPushButton("CAPTURE");   //捕获图像按键

    label = new QLabel();

    connect(ok,SIGNAL(clicked()),this,SLOT(getFrame()));
    grabThread = new GrabVideo;
    connect(grabThread,SIGNAL(sendQImage(uchar*,int,int,int)),this,SLOT(getQImage(uchar*,int,int,int)));
    connect(cap,SIGNAL(clicked()),this,SLOT(capImage()));

    /*布局*/
    mainLayout = new QVBoxLayout;
    buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(ok);
    buttonLayout->addWidget(cap);
    mainLayout->addWidget(label);
    mainLayout->addLayout(buttonLayout);
    main = new QWidget;
    main->setLayout(mainLayout);
    setCentralWidget(main);

}
void MainWindow::getFrame(){
    if(stop == 1){  //之前是Stop状态
        stop = 0;
        ok->setText("Start");
        grabThread->terminate();
        grabThread->wait();
    }else{//之前是Start状态
        stop = 1;
        ok->setText("Stop");
        grabThread->start();
    }
}
void MainWindow::getQImage(uchar* ptrData,int heightData,int widthData,int flagData){
    qDebug() << "Get video from Cam";
    if(flagData == 32){
        imageData = new QImage(ptrData,widthData,heightData,QImage::Format_RGB32);
        label->setPixmap(QPixmap::fromImage(*imageData));
    }else if(flagData == 8){
        ;;
    }else{
        ;;
    }
}
void MainWindow::capImage(){
    //暂停图像数据
    stop = 0;
    ok->setText("Start");
    cap->setDisabled(true);
    grabThread->terminate();
    grabThread->wait();
	
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save QImage"),
                                                    "untitled.jpg",
                                                    tr("Images (*.jpg)"));//获取需要保存的图像的文件名
    //QString fileName = QFileDialog::getSaveFileName(this);
    if(fileName.isEmpty()){
    }
    imageData->save(fileName,0,-1);
    
	cap->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete imageData;
    delete ok;
    delete cap;
    delete buttonLayout;
    delete label;
    delete mainLayout;
    //delete grabThread;
    delete main;
}
