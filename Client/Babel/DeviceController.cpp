#include "DeviceController.h"

DeviceController::DeviceController(QObject *parent)
    : QObject{parent}
{
    _socket = std::make_shared<QTcpSocket>();
    connect(_socket.get(), &QTcpSocket::connected, this, &DeviceController::connected);
    connect(_socket.get(), &QTcpSocket::disconnected, this, &DeviceController::disconnected);
    connect(_socket.get(), &QTcpSocket::stateChanged, this, &DeviceController::socket_stateChanged);
    connect(_socket.get(), &QTcpSocket::errorOccurred, this, &DeviceController::errorOccurred);
    connect(_socket.get(), &QTcpSocket::readyRead, this, &DeviceController::socket_ReadyRead);
}

void DeviceController::connectToDevice(QString ip, int port)
{
    if (_socket->isOpen()) {
        if(ip == _ip && port == _port)
            return;
        _socket->close();
    }
    _ip = ip;
    _port = port;
    _socket->connectToHost(_ip, _port);
}

void DeviceController::disconnect()
{
    _socket->close();
}

QAbstractSocket::SocketState DeviceController::state()
{
    return _socket->state();
}

bool DeviceController::IsConnected()
{
    return _socket->state() == QAbstractSocket::ConnectedState;
}

void DeviceController::Send(QString message)
{
    _socket->write(message.toUtf8());
}

void DeviceController::socket_stateChanged(QAbstractSocket::SocketState state)
{
    if (state == QAbstractSocket::UnconnectedState) {
        _socket->close();
    }
    emit stateChanged(state);
}

void DeviceController::socket_ReadyRead()
{
    auto data = _socket->readAll();
    emit DataReady(data);
}

bool DeviceController::ReceivingData() const
{
    return _ReceivingData;
}

void DeviceController::setReceivingData(bool newReceivingData)
{
    _ReceivingData = newReceivingData;
}

int DeviceController::id() const
{
    return _id;
}

int DeviceController::callTo() const
{
    return _callTo;
}

void DeviceController::setCallTo(int newCallTo)
{
    _callTo = newCallTo;
}

const std::shared_ptr<QTcpSocket> &DeviceController::socket() const
{
    return _socket;
}

void DeviceController::setSocket(const std::shared_ptr<QTcpSocket> &newSocket)
{
    _socket = newSocket;
}

bool DeviceController::inCall() const
{
    return _inCall;
}

void DeviceController::setInCall(bool newInCall)
{
    _inCall = newInCall;
}
