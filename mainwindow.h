#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QPixmap>
#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QFileDialog>
#include "grabvideo.h"
#include "cv.h"
#include "highgui.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QWidget *main;  //主窗口的Widget
    QVBoxLayout *mainLayout;    //主窗口的布局
    QHBoxLayout *buttonLayout;
    QPushButton *ok;    //主窗口的按键
    QPushButton *cap;   //采集图像按键
    QImage *imageData;
    QLabel *label;  //主窗口的显示Label
    GrabVideo *grabThread;
    bool stop;  //视频图像的读取或暂停
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void getFrame();
    void getQImage(uchar* ptrData,int heightData,int widthData,int flagData);
    void capImage();
};

#endif // MAINWINDOW_H
