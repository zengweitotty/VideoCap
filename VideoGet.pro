#-------------------------------------------------
#
# Project created by QtCreator 2013-03-21T12:34:56
#
#-------------------------------------------------

QT       += core gui

TARGET = VideoGet
TEMPLATE = app

# ���ͷ�ļ�·��
QMAKE_INCDIR       += /usr/local/include/opencv

SOURCES += main.cpp\
        mainwindow.cpp \
    grabvideo.cpp

HEADERS  += mainwindow.h \
    grabvideo.h

QMAKE_CXXFLAGS += -fno-rtti



