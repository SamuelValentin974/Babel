#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include <QObject>
#include <QUdpSocket>
#include <QTcpSocket>
#include "udpcontroller.h"

class DeviceController : public QObject
{
    Q_OBJECT
public:
    explicit DeviceController(QObject *parent = nullptr);
    void connectToDevice(QString ip, int port);
    void disconnect();
    QAbstractSocket::SocketState state();
    bool IsConnected();
    void Send(QString message);
    void SetId(int id) {_id = id;}

    bool inCall() const;
    void setInCall(bool newInCall);

    const std::shared_ptr<QTcpSocket> &socket() const;
    void setSocket(const std::shared_ptr<QTcpSocket> &newSocket);

    int callTo() const;
    void setCallTo(int newCallTo);

    int id() const;

    void ListenAudio();

    bool ReceivingData() const;
    void setReceivingData(bool newReceivingData);

signals:
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState);
    void errorOccurred(QAbstractSocket::SocketError);
    void DataReady(QByteArray array);

private slots:
    void socket_stateChanged(QAbstractSocket::SocketState state);
    void socket_ReadyRead();

private:
    std::shared_ptr<QTcpSocket> _socket;

    QString _ip;
    int _port;
    int _id;
    bool _inCall{};
    bool _ReceivingData{};
    int _callTo{-84};
};

#endif // DEVICECONTROLLER_H
