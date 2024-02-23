/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Babel/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_BtnConnect_clicked",
    "",
    "ReadBufferDecoder",
    "device_connected",
    "device_disconnected",
    "device_stateChanged",
    "QAbstractSocket::SocketState",
    "device_errorOccurred",
    "QAbstractSocket::SocketError",
    "device_dataReady",
    "array",
    "udp_connected",
    "udp_disconnected",
    "udp_stateChanged",
    "udp_errorOccurred",
    "udp_DataReady",
    "on_LnAddr_textChanged",
    "arg1",
    "on_RecBtn_clicked",
    "on_CBInputs_currentIndexChanged",
    "index",
    "on_CBOutputs_currentIndexChanged",
    "on_LstUsers_itemActivated",
    "QListWidgetItem*",
    "item",
    "on_BtnCall_clicked",
    "on_LstUsers_itemChanged",
    "on_BtnAccept_clicked",
    "on_BtnRefuse_clicked",
    "on_BtnLst_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[62];
    char stringdata0[11];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[17];
    char stringdata5[20];
    char stringdata6[20];
    char stringdata7[29];
    char stringdata8[21];
    char stringdata9[29];
    char stringdata10[17];
    char stringdata11[6];
    char stringdata12[14];
    char stringdata13[17];
    char stringdata14[17];
    char stringdata15[18];
    char stringdata16[14];
    char stringdata17[22];
    char stringdata18[5];
    char stringdata19[18];
    char stringdata20[32];
    char stringdata21[6];
    char stringdata22[33];
    char stringdata23[26];
    char stringdata24[17];
    char stringdata25[5];
    char stringdata26[19];
    char stringdata27[24];
    char stringdata28[21];
    char stringdata29[21];
    char stringdata30[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 21),  // "on_BtnConnect_clicked"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 17),  // "ReadBufferDecoder"
        QT_MOC_LITERAL(52, 16),  // "device_connected"
        QT_MOC_LITERAL(69, 19),  // "device_disconnected"
        QT_MOC_LITERAL(89, 19),  // "device_stateChanged"
        QT_MOC_LITERAL(109, 28),  // "QAbstractSocket::SocketState"
        QT_MOC_LITERAL(138, 20),  // "device_errorOccurred"
        QT_MOC_LITERAL(159, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(188, 16),  // "device_dataReady"
        QT_MOC_LITERAL(205, 5),  // "array"
        QT_MOC_LITERAL(211, 13),  // "udp_connected"
        QT_MOC_LITERAL(225, 16),  // "udp_disconnected"
        QT_MOC_LITERAL(242, 16),  // "udp_stateChanged"
        QT_MOC_LITERAL(259, 17),  // "udp_errorOccurred"
        QT_MOC_LITERAL(277, 13),  // "udp_DataReady"
        QT_MOC_LITERAL(291, 21),  // "on_LnAddr_textChanged"
        QT_MOC_LITERAL(313, 4),  // "arg1"
        QT_MOC_LITERAL(318, 17),  // "on_RecBtn_clicked"
        QT_MOC_LITERAL(336, 31),  // "on_CBInputs_currentIndexChanged"
        QT_MOC_LITERAL(368, 5),  // "index"
        QT_MOC_LITERAL(374, 32),  // "on_CBOutputs_currentIndexChanged"
        QT_MOC_LITERAL(407, 25),  // "on_LstUsers_itemActivated"
        QT_MOC_LITERAL(433, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(450, 4),  // "item"
        QT_MOC_LITERAL(455, 18),  // "on_BtnCall_clicked"
        QT_MOC_LITERAL(474, 23),  // "on_LstUsers_itemChanged"
        QT_MOC_LITERAL(498, 20),  // "on_BtnAccept_clicked"
        QT_MOC_LITERAL(519, 20),  // "on_BtnRefuse_clicked"
        QT_MOC_LITERAL(540, 17)   // "on_BtnLst_clicked"
    },
    "MainWindow",
    "on_BtnConnect_clicked",
    "",
    "ReadBufferDecoder",
    "device_connected",
    "device_disconnected",
    "device_stateChanged",
    "QAbstractSocket::SocketState",
    "device_errorOccurred",
    "QAbstractSocket::SocketError",
    "device_dataReady",
    "array",
    "udp_connected",
    "udp_disconnected",
    "udp_stateChanged",
    "udp_errorOccurred",
    "udp_DataReady",
    "on_LnAddr_textChanged",
    "arg1",
    "on_RecBtn_clicked",
    "on_CBInputs_currentIndexChanged",
    "index",
    "on_CBOutputs_currentIndexChanged",
    "on_LstUsers_itemActivated",
    "QListWidgetItem*",
    "item",
    "on_BtnCall_clicked",
    "on_LstUsers_itemChanged",
    "on_BtnAccept_clicked",
    "on_BtnRefuse_clicked",
    "on_BtnLst_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  146,    2, 0x08,    1 /* Private */,
       3,    0,  147,    2, 0x08,    2 /* Private */,
       4,    0,  148,    2, 0x08,    3 /* Private */,
       5,    0,  149,    2, 0x08,    4 /* Private */,
       6,    1,  150,    2, 0x08,    5 /* Private */,
       8,    1,  153,    2, 0x08,    7 /* Private */,
      10,    1,  156,    2, 0x08,    9 /* Private */,
      12,    0,  159,    2, 0x08,   11 /* Private */,
      13,    0,  160,    2, 0x08,   12 /* Private */,
      14,    1,  161,    2, 0x08,   13 /* Private */,
      15,    1,  164,    2, 0x08,   15 /* Private */,
      16,    1,  167,    2, 0x08,   17 /* Private */,
      17,    1,  170,    2, 0x08,   19 /* Private */,
      19,    0,  173,    2, 0x08,   21 /* Private */,
      20,    1,  174,    2, 0x08,   22 /* Private */,
      22,    1,  177,    2, 0x08,   24 /* Private */,
      23,    1,  180,    2, 0x08,   26 /* Private */,
      26,    0,  183,    2, 0x08,   28 /* Private */,
      27,    1,  184,    2, 0x08,   29 /* Private */,
      28,    0,  187,    2, 0x08,   31 /* Private */,
      29,    0,  188,    2, 0x08,   32 /* Private */,
      30,    0,  189,    2, 0x08,   33 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_BtnConnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ReadBufferDecoder'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'device_connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'device_disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'device_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketState, std::false_type>,
        // method 'device_errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'device_dataReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'udp_connected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'udp_disconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'udp_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketState, std::false_type>,
        // method 'udp_errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'udp_DataReady'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'on_LnAddr_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_RecBtn_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CBInputs_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_CBOutputs_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_LstUsers_itemActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_BtnCall_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_LstUsers_itemChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_BtnAccept_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BtnRefuse_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_BtnLst_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_BtnConnect_clicked(); break;
        case 1: _t->ReadBufferDecoder(); break;
        case 2: _t->device_connected(); break;
        case 3: _t->device_disconnected(); break;
        case 4: _t->device_stateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 5: _t->device_errorOccurred((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 6: _t->device_dataReady((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 7: _t->udp_connected(); break;
        case 8: _t->udp_disconnected(); break;
        case 9: _t->udp_stateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 10: _t->udp_errorOccurred((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 11: _t->udp_DataReady((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 12: _t->on_LnAddr_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->on_RecBtn_clicked(); break;
        case 14: _t->on_CBInputs_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->on_CBOutputs_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->on_LstUsers_itemActivated((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 17: _t->on_BtnCall_clicked(); break;
        case 18: _t->on_LstUsers_itemChanged((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 19: _t->on_BtnAccept_clicked(); break;
        case 20: _t->on_BtnRefuse_clicked(); break;
        case 21: _t->on_BtnLst_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_WARNING_POP
