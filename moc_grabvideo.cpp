/****************************************************************************
** Meta object code from reading C++ file 'grabvideo.h'
**
** Created: Tue Apr 16 22:50:29 2013
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "grabvideo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grabvideo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GrabVideo[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      49,   11,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_GrabVideo[] = {
    "GrabVideo\0\0ptrData,heightData,widthData,flagData\0"
    "sendQImage(uchar*,int,int,int)\0"
};

const QMetaObject GrabVideo::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GrabVideo,
      qt_meta_data_GrabVideo, 0 }
};

const QMetaObject *GrabVideo::metaObject() const
{
    return &staticMetaObject;
}

void *GrabVideo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GrabVideo))
        return static_cast<void*>(const_cast< GrabVideo*>(this));
    return QThread::qt_metacast(_clname);
}

int GrabVideo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendQImage((*reinterpret_cast< uchar*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GrabVideo::sendQImage(uchar * _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
