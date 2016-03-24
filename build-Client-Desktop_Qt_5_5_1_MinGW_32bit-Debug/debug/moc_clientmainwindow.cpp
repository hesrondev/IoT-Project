/****************************************************************************
** Meta object code from reading C++ file 'clientmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/client-protocol/clientmainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientMainWindow_t {
    QByteArrayData data[22];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientMainWindow_t qt_meta_stringdata_ClientMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ClientMainWindow"
QT_MOC_LITERAL(1, 17, 26), // "on_boutonConnexion_clicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 2), // "ip"
QT_MOC_LITERAL(4, 48, 4), // "port"
QT_MOC_LITERAL(5, 53, 10), // "clientName"
QT_MOC_LITERAL(6, 64, 3), // "mdp"
QT_MOC_LITERAL(7, 68, 13), // "donneesRecues"
QT_MOC_LITERAL(8, 82, 8), // "connecte"
QT_MOC_LITERAL(9, 91, 10), // "deconnecte"
QT_MOC_LITERAL(10, 102, 11), // "deconnexion"
QT_MOC_LITERAL(11, 114, 12), // "erreurSocket"
QT_MOC_LITERAL(12, 127, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(13, 156, 6), // "erreur"
QT_MOC_LITERAL(14, 163, 22), // "updateComponentsParams"
QT_MOC_LITERAL(15, 186, 3), // "pro"
QT_MOC_LITERAL(16, 190, 3), // "cpu"
QT_MOC_LITERAL(17, 194, 3), // "mem"
QT_MOC_LITERAL(18, 198, 4), // "disk"
QT_MOC_LITERAL(19, 203, 3), // "eth"
QT_MOC_LITERAL(20, 207, 17), // "updateGlobalParam"
QT_MOC_LITERAL(21, 225, 3) // "glo"

    },
    "ClientMainWindow\0on_boutonConnexion_clicked\0"
    "\0ip\0port\0clientName\0mdp\0donneesRecues\0"
    "connecte\0deconnecte\0deconnexion\0"
    "erreurSocket\0QAbstractSocket::SocketError\0"
    "erreur\0updateComponentsParams\0pro\0cpu\0"
    "mem\0disk\0eth\0updateGlobalParam\0glo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   54,    2, 0x08 /* Private */,
       7,    0,   63,    2, 0x08 /* Private */,
       8,    0,   64,    2, 0x08 /* Private */,
       9,    0,   65,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    1,   67,    2, 0x08 /* Private */,
      14,    5,   70,    2, 0x08 /* Private */,
      20,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,   18,   19,
    QMetaType::Void, QMetaType::Int,   21,

       0        // eod
};

void ClientMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientMainWindow *_t = static_cast<ClientMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_boutonConnexion_clicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 1: _t->donneesRecues(); break;
        case 2: _t->connecte(); break;
        case 3: _t->deconnecte(); break;
        case 4: _t->deconnexion(); break;
        case 5: _t->erreurSocket((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 6: _t->updateComponentsParams((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 7: _t->updateGlobalParam((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject ClientMainWindow::staticMetaObject = {
    { &MainWindow::staticMetaObject, qt_meta_stringdata_ClientMainWindow.data,
      qt_meta_data_ClientMainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClientMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClientMainWindow.stringdata0))
        return static_cast<void*>(const_cast< ClientMainWindow*>(this));
    return MainWindow::qt_metacast(_clname);
}

int ClientMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
