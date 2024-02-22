#include "udpcontroller.h"
#include <QRandomGenerator>


UdpController::UdpController(QObject *parent)
    : QObject{parent}
{
    _socket = std::make_shared<QUdpSocket>(this);
    _port = QRandomGenerator::global()->generate() % (4000 - 1030 + 1) + 1030;
    _socket->bind(GetIP().ip(), _port);
    qDebug() << "Udp port = " << _port;
    connect(_socket.get(), &QUdpSocket::connected, this, &UdpController::connected);
    connect(_socket.get(), &QUdpSocket::disconnected, this, &UdpController::disconnected);
    connect(_socket.get(), &QUdpSocket::stateChanged, this, &UdpController::socket_stateChanged);
    connect(_socket.get(), &QUdpSocket::errorOccurred, this, &UdpController::errorOccurred);
    connect(_socket.get(), &QUdpSocket::readyRead, this, &UdpController::socket_ReadyRead);
}

void UdpController::StartSocket()
{
    _socket->connectToHost(_ip, _portTo);
    connect(_socket.get(), &QUdpSocket::readyRead, this, &UdpController::socket_ReadyRead);
}

int UdpController::port() const
{
    return _port;
}

void UdpController::setPort(int newPort)
{
    _port = newPort;
}

int UdpController::portTo() const
{
    return _portTo;
}

void UdpController::setPortTo(int newPortTo)
{
    _portTo = newPortTo;
}

std::shared_ptr<QUdpSocket> UdpController::socket() const
{
    return _socket;
}

void UdpController::setSocket(const std::shared_ptr<QUdpSocket> &newSocket)
{
    _socket = newSocket;
}

std::queue<QNetworkDatagram> UdpController::queue() const
{
    return _queue;
}

void UdpController::setQueue(const std::queue<QNetworkDatagram> &newQueue)
{
    _queue = newQueue;
}

void UdpController::socket_ReadyRead()
{
    auto data = _socket->readAll();
    emit DataReady(data);
}

void UdpController::socket_stateChanged(QAbstractSocket::SocketState state)
{
    if (state == QAbstractSocket::UnconnectedState) {
        _socket->close();
    }
    emit stateChanged(state);
}

bool UdpController::sentAddr() const
{
    return _sentAddr;
}

void UdpController::setSentAddr(bool newSentAddr)
{
    _sentAddr = newSentAddr;
}

QString UdpController::ip() const
{
    return _ip;
}

void UdpController::SendDatas()
{

}

void UdpController::setIp(const QString &newIp)
{
    _ip = newIp;
}
