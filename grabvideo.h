#ifndef GRABVIDEO_H
#define GRABVIDEO_H

#include <QThread>
#include <QDebug>
#include <QImage>
#include <QQueue>
#include "cv.h"
#include "highgui.h"

#define QUEUE_SIZE  10

class GrabVideo : public QThread
{
    Q_OBJECT
private:
    CvCapture* capture; //初始化从摄像头获取视频
    IplImage *pImg; //OpenCV读取图像数据
    //QImage *tempImg;    //转换后QImage类型的数据
    uchar* qImageBuffer;
    QQueue<uchar*> queue;
    int x;
    int y;
    int width;
    int height;
    int widthStep;
public:
    explicit GrabVideo(QObject *parent = 0);
    ~GrabVideo();
signals:
    void sendQImage(uchar* ptrData,int heightData,int widthData,int flagData);
protected:
    void run();
};

#endif // GRABVIDEO_H
