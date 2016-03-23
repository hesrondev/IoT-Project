/****************************************************************************
** Meta object code from reading C++ file 'serverlogindialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/client-gui/serverlogindialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverlogindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ServerLoginDialog_t {
    QByteArrayData data[8];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerLoginDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerLoginDialog_t qt_meta_stringdata_ServerLoginDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ServerLoginDialog"
QT_MOC_LITERAL(1, 18, 22), // "serverConnectionSignal"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 2), // "ip"
QT_MOC_LITERAL(4, 45, 4), // "port"
QT_MOC_LITERAL(5, 50, 10), // "clientName"
QT_MOC_LITERAL(6, 61, 3), // "mdp"
QT_MOC_LITERAL(7, 65, 15) // "validBtnClicked"

    },
    "ServerLoginDialog\0serverConnectionSignal\0"
    "\0ip\0port\0clientName\0mdp\0validBtnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerLoginDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ServerLoginDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerLoginDialog *_t = static_cast<ServerLoginDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serverConnectionSignal((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 1: _t->validBtnClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ServerLoginDialog::*_t)(const QString & , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ServerLoginDialog::serverConnectionSignal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ServerLoginDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ServerLoginDialog.data,
      qt_meta_data_ServerLoginDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ServerLoginDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerLoginDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ServerLoginDialog.stringdata0))
        return static_cast<void*>(const_cast< ServerLoginDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ServerLoginDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ServerLoginDialog::serverConnectionSignal(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
