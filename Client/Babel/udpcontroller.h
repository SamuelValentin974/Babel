#ifndef UDPCONTROLLER_H
#define UDPCONTROLLER_H

#include <QObject>
#include <QUdpSocket>
#include <queue>
#include <memory>
#include <QtMultimedia>

class UdpController : public QObject
{
    Q_OBJECT
public:
    explicit UdpController(QObject *parent = nullptr);

    void StartSocket();
    int port() const;
    void setPort(int newPort);

    int portTo() const;
    void setPortTo(int newPortTo);

    std::shared_ptr<QUdpSocket> socket() const;
    void setSocket(const std::shared_ptr<QUdpSocket> &newSocket);

    std::queue<QNetworkDatagram> queue() const;
    void setQueue(const std::queue<QNetworkDatagram> &newQueue);

    void SendData();

    QString ip() const;
    void setIp(const QString &newIp);

    bool sentAddr() const;
    void setSentAddr(bool newSentAddr);

    void SendDatas();
signals:
    void DataReady(QByteArray array);
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState);
    void errorOccurred(QAbstractSocket::SocketError);

private slots:
    void socket_ReadyRead();
    void socket_stateChanged(QAbstractSocket::SocketState state);

private:
    std::shared_ptr<QUdpSocket> _socket;
    QString _ip;
    int _port;
    int _portTo;
    std::queue<QNetworkDatagram> _queue;
    std::shared_ptr<QAudioOutput> _output;
    bool _sentAddr{};
};

QString GetLocalIP();
QNetworkAddressEntry GetIP();

#endif // UDPCONTROLLER_H
