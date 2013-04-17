#-------------------------------------------------
#
# Project created by QtCreator 2013-03-21T12:34:56
#
#-------------------------------------------------

QT       += core gui

TARGET = VideoGet
TEMPLATE = app

# 添加头文件路径
QMAKE_INCDIR       += /usr/local/include/opencv

SOURCES += main.cpp\
        mainwindow.cpp \
    grabvideo.cpp

HEADERS  += mainwindow.h \
    grabvideo.h

QMAKE_CXXFLAGS += -fno-rtti



