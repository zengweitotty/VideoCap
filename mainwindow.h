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
    QWidget *main;  //�����ڵ�Widget
    QVBoxLayout *mainLayout;    //�����ڵĲ���
    QHBoxLayout *buttonLayout;
    QPushButton *ok;    //�����ڵİ���
    QPushButton *cap;   //�ɼ�ͼ�񰴼�
    QImage *imageData;
    QLabel *label;  //�����ڵ���ʾLabel
    GrabVideo *grabThread;
    bool stop;  //��Ƶͼ��Ķ�ȡ����ͣ
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void getFrame();
    void getQImage(uchar* ptrData,int heightData,int widthData,int flagData);
    void capImage();
};

#endif // MAINWINDOW_H
