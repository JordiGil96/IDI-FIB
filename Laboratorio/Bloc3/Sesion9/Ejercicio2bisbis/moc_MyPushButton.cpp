/****************************************************************************
** Meta object code from reading C++ file 'MyPushButton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyPushButton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyPushButton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyPushButton_t {
    QByteArrayData data[8];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyPushButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyPushButton_t qt_meta_stringdata_MyPushButton = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MyPushButton"
QT_MOC_LITERAL(1, 13, 7), // "setFile"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 3), // "str"
QT_MOC_LITERAL(4, 26, 6), // "setOBJ"
QT_MOC_LITERAL(5, 33, 8), // "sendName"
QT_MOC_LITERAL(6, 42, 9), // "myClicked"
QT_MOC_LITERAL(7, 52, 10) // "myClicked2"

    },
    "MyPushButton\0setFile\0\0str\0setOBJ\0"
    "sendName\0myClicked\0myClicked2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyPushButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       5,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyPushButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyPushButton *_t = static_cast<MyPushButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setOBJ((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->myClicked(); break;
        case 4: _t->myClicked2(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyPushButton::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyPushButton::setFile)) {
                *result = 0;
            }
        }
        {
            typedef void (MyPushButton::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyPushButton::setOBJ)) {
                *result = 1;
            }
        }
        {
            typedef void (MyPushButton::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyPushButton::sendName)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MyPushButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_MyPushButton.data,
      qt_meta_data_MyPushButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyPushButton.stringdata0))
        return static_cast<void*>(const_cast< MyPushButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int MyPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MyPushButton::setFile(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyPushButton::setOBJ(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyPushButton::sendName(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
