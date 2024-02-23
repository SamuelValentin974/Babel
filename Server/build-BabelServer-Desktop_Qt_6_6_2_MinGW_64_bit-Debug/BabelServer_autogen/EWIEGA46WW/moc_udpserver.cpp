/****************************************************************************
** Meta object code from reading C++ file 'udpserver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../BabelServer/udpserver.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSUDPServerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUDPServerENDCLASS = QtMocHelpers::stringData(
    "UDPServer",
    "NewClientConnected",
    "",
    "ClientDisconnect",
    "DataReceived",
    "message",
    "onClientConnecting",
    "ClientDisconnected",
    "ClientDataReady"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSUDPServerENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[10];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[13];
    char stringdata5[8];
    char stringdata6[19];
    char stringdata7[19];
    char stringdata8[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSUDPServerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSUDPServerENDCLASS_t qt_meta_stringdata_CLASSUDPServerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "UDPServer"
        QT_MOC_LITERAL(10, 18),  // "NewClientConnected"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 16),  // "ClientDisconnect"
        QT_MOC_LITERAL(47, 12),  // "DataReceived"
        QT_MOC_LITERAL(60, 7),  // "message"
        QT_MOC_LITERAL(68, 18),  // "onClientConnecting"
        QT_MOC_LITERAL(87, 18),  // "ClientDisconnected"
        QT_MOC_LITERAL(106, 15)   // "ClientDataReady"
    },
    "UDPServer",
    "NewClientConnected",
    "",
    "ClientDisconnect",
    "DataReceived",
    "message",
    "onClientConnecting",
    "ClientDisconnected",
    "ClientDataReady"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUDPServerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    1,   52,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   55,    2, 0x08,    5 /* Private */,
       7,    0,   56,    2, 0x08,    6 /* Private */,
       8,    0,   57,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject UDPServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSUDPServerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUDPServerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUDPServerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UDPServer, std::true_type>,
        // method 'NewClientConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ClientDisconnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'onClientConnecting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ClientDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ClientDataReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UDPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UDPServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->NewClientConnected(); break;
        case 1: _t->ClientDisconnect(); break;
        case 2: _t->DataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 3: _t->onClientConnecting(); break;
        case 4: _t->ClientDisconnected(); break;
        case 5: _t->ClientDataReady(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UDPServer::*)();
            if (_t _q_method = &UDPServer::NewClientConnected; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UDPServer::*)();
            if (_t _q_method = &UDPServer::ClientDisconnect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UDPServer::*)(QByteArray );
            if (_t _q_method = &UDPServer::DataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *UDPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUDPServerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UDPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UDPServer::NewClientConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void UDPServer::ClientDisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UDPServer::DataReceived(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
