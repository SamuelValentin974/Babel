#include "udpserver.h"
#include <QBuffer>
#include <QEventLoop>

UDPServer::UDPServer(int port, QObject *parent)
    : QObject{parent}
{
    _countId = 0;
    _server = std::make_shared<QTcpServer>(this);
    connect(_server.get(), &QTcpServer::newConnection, this, &UDPServer::onClientConnecting);
    _isStarted = _server->listen(QHostAddress::Any, port);

    if (!_isStarted) {
        qDebug() << "Server couldn't start !";
    } else
        qDebug() << "Server started !";
}


void UDPServer::onClientConnecting()
{
    std::shared_ptr<User> user = std::make_shared<User>();
    QTcpSocket *socket = _server->nextPendingConnection();

    qDebug() << "a client is connected ! ";
    user->setSocket(socket);
    user->setId(_countId);
    _countId++;

    connect(socket, &QTcpSocket::readyRead, this, &UDPServer::ClientDataReady);
    connect(socket, &QTcpSocket::disconnected, this, &UDPServer::ClientDisconnected);

    _userList.append(user);
    QString str = "ID " + QString::number(user->id()) + "\n";
    socket->write(str.toUtf8());
    socket->flush();
    SendClientsConnected();

    emit NewClientConnected();
}

void UDPServer::ClientDisconnected()
{
    foreach(auto user, _userList) {
        if (user->socket()->state() == QAbstractSocket::UnconnectedState) {
            _userList.removeOne(user);
            SendClientsConnected();
        }
    }
    emit ClientDisconnect();
}

void UDPServer::CheckClients()
{
    foreach(auto user, _userList) {
        if (user->socket()->state() == QAbstractSocket::UnconnectedState) {
            _userList.removeOne(user);
            SendClientsConnected();
        }
    }
}

void UDPServer::ClientDataReady()
{
    auto socket = qobject_cast<QTcpSocket *>(sender());
    auto data = socket->readAll();
    emit DataReceived(data);
}

QList<std::shared_ptr<User> > UDPServer::userList() const
{
    return _userList;
}

void UDPServer::setUserList(const QList<std::shared_ptr<User> > &newUserList)
{
    _userList = newUserList;
}

