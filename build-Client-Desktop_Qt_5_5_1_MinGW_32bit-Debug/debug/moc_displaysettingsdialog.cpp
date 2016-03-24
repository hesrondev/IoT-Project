/****************************************************************************
** Meta object code from reading C++ file 'displaysettingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/client-gui/displaysettingsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displaysettingsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DisplaySettingsDialog_t {
    QByteArrayData data[13];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DisplaySettingsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DisplaySettingsDialog_t qt_meta_stringdata_DisplaySettingsDialog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "DisplaySettingsDialog"
QT_MOC_LITERAL(1, 22, 11), // "globalParam"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 2), // "gp"
QT_MOC_LITERAL(4, 38, 16), // "componentsParams"
QT_MOC_LITERAL(5, 55, 3), // "pro"
QT_MOC_LITERAL(6, 59, 3), // "cpu"
QT_MOC_LITERAL(7, 63, 3), // "mem"
QT_MOC_LITERAL(8, 67, 4), // "disk"
QT_MOC_LITERAL(9, 72, 3), // "eth"
QT_MOC_LITERAL(10, 76, 16), // "enableCompsGroup"
QT_MOC_LITERAL(11, 93, 17), // "enableGlobalGroup"
QT_MOC_LITERAL(12, 111, 22) // "on_validButton_clicked"

    },
    "DisplaySettingsDialog\0globalParam\0\0"
    "gp\0componentsParams\0pro\0cpu\0mem\0disk\0"
    "eth\0enableCompsGroup\0enableGlobalGroup\0"
    "on_validButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DisplaySettingsDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    5,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   53,    2, 0x0a /* Public */,
      11,    0,   54,    2, 0x0a /* Public */,
      12,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DisplaySettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DisplaySettingsDialog *_t = static_cast<DisplaySettingsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->globalParam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->componentsParams((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 2: _t->enableCompsGroup(); break;
        case 3: _t->enableGlobalGroup(); break;
        case 4: _t->on_validButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DisplaySettingsDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DisplaySettingsDialog::globalParam)) {
                *result = 0;
            }
        }
        {
            typedef void (DisplaySettingsDialog::*_t)(int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DisplaySettingsDialog::componentsParams)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DisplaySettingsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DisplaySettingsDialog.data,
      qt_meta_data_DisplaySettingsDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DisplaySettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DisplaySettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DisplaySettingsDialog.stringdata0))
        return static_cast<void*>(const_cast< DisplaySettingsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int DisplaySettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void DisplaySettingsDialog::globalParam(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DisplaySettingsDialog::componentsParams(int _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
