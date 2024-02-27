#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include "User.h"
#include <unordered_map>

class UDPServer : public QObject
{
    Q_OBJECT
public:
    explicit UDPServer(int port, QObject *parent = nullptr);
    bool isStarted() const {return _isStarted;}
    void ReadClient();
    void SendClientsConnected();
    std::shared_ptr<User> GetUserFromId(int id) const {
        foreach (auto user, _userList) {
            if (user->id() == id)
                return user;
        }
        return nullptr;
    }

    QList<std::shared_ptr<User>> userList() const;
    void setUserList(const QList<std::shared_ptr<User> > &newUserList);
    void ListenAudio(int from, int to);

    void CheckClients();
signals:
    void NewClientConnected();
    void ClientDisconnect();
    void DataReceived(QByteArray message);

private slots:
    void onClientConnecting();
    void ClientDisconnected();
    void ClientDataReady();

private:
    std::shared_ptr<QTcpServer> _server;
    QList<std::shared_ptr<User>> _userList;
    bool _isStarted{};
    int _countId{};
    std::unordered_map<std::string, std::function<void(QList<std::shared_ptr<User>>, QString)>> _cmds;
};

void CallClient(std::shared_ptr<UDPServer> _server,  QString str);
void RefuseCall(std::shared_ptr<UDPServer> _server,  QString str);
void AcceptCall(std::shared_ptr<UDPServer> _server,  QString str);
void SendAudio(std::shared_ptr<UDPServer> _server,  QByteArray str);
void SendEnd(std::shared_ptr<UDPServer> _server,  QString str);
void SendRecord(std::shared_ptr<UDPServer> _server,  QByteArray str);

#endif // UDPSERVER_H
