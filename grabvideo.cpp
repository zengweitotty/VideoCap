#include "grabvideo.h"
/*不可重入线程*/
GrabVideo::GrabVideo(QObject *parent) :
    QThread(parent)
{
    //tempImg = new QImage(320,240,QImage::Format_Indexed8);
    //qImageBuffer = (uchar*)malloc(4 * width * height * sizeof(uchar));
    qImageBuffer = NULL;
    /*功能编程*/
    capture = cvCreateCameraCapture(0);    //初始化摄像头读取视频
    cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH,320);
    cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT,240);
    cvSetCaptureProperty(capture,CV_CAP_PROP_FPS,20);
}
void GrabVideo::run(){
    while(true){
        pImg = cvQueryFrame(capture);
        width = pImg->width;
        height = pImg->height;
        widthStep = pImg->widthStep;
        /*struct IplImage to QImage*/
        switch(pImg->depth){
        case IPL_DEPTH_8U:  //OpenCV 图像深度8U
            //qDebug("IplImage Depth is IPL_DEPTH_8U");
            if(pImg->nChannels == 1){
                //qDebug("IplImage nChannel is 1");
                qImageBuffer = (uchar*)malloc(width * height * sizeof(uchar));
                uchar* QImagePtr = qImageBuffer;
                uchar* IplImagePtr = (uchar*)pImg->imageData;
                for(y = 0;y < height;y++){
                    memcpy(QImagePtr,IplImagePtr,width);
                    QImagePtr += width;
                    IplImagePtr += widthStep;
                }
                //tempImg = new QImage(qImageBuffer,width,height,QImage::Format_Indexed8);
                //tempImg->loadFromData(qImageBuffer,QImage::Format_Indexed8);
            }else if(pImg->nChannels == 3){
                //qDebug("IplImage nChannel is 3");
                qImageBuffer = (uchar*)malloc(4 * width * height * sizeof(uchar));
                uchar* QImagePtr = qImageBuffer;
                uchar* IplImagePtr = (uchar*)pImg->imageData;
                for(y = 0;y < height;y++){
                    for(x = 0;x < width;x++){
                        QImagePtr[0] = IplImagePtr[0];
                        QImagePtr[1] = IplImagePtr[1];
                        QImagePtr[2] = IplImagePtr[2];
                        QImagePtr[3] = 0;
                        QImagePtr += 4;
                        IplImagePtr += 3;
                    }
                    IplImagePtr += widthStep-3*width;
                }
                //tempImg = new QImage(qImageBuffer,width,height,QImage::Format_RGB32);
                //tempImg->loadFromData(qImageBuffer,QImage::Format_RGB32);
            }else{
                qDebug("Camera IplImage channels can not support");
            }
            break;
        case IPL_DEPTH_16U: //OpenCV 图像深度16U
            qDebug("IplImage Depth is IPL_DEPTH_16U");
            break;
        case IPL_DEPTH_32F://OpenCV 图像深度32U
            qDebug("IplImage Depth is IPL_DEPTH_16U");
            break;
        case IPL_DEPTH_64F://OpenCV 图像深度64U
            qDebug("IplImage Depth is IPL_DEPTH_16U");
            break;
        }
        while(queue.size() >= QUEUE_SIZE){
            uchar* temp = queue.head();
            queue.dequeue();
            free(temp);
        }
        queue.enqueue(qImageBuffer);
        emit sendQImage(qImageBuffer,height,width,32);//
    }
}
GrabVideo::~GrabVideo(){
    while(!queue.isEmpty()){
        uchar* temp = queue.head();
        queue.dequeue();
        free(temp);
    }
    delete pImg;
    cvReleaseCapture(&capture);
    //delete tempImg;
}

