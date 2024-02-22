#ifndef USER_H
#define USER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);

    int id() const;
    void setId(int newId);

    QTcpSocket *socket() const;
    void setSocket(QTcpSocket *newSocket);

    bool isCalling() const;
    void setIsCalling(bool newIsCalling);

    int callingTo() const;
    void setCallingTo(int newCallingTo);

    bool sendingAudio() const;
    void setSendingAudio(bool newSendingAudio);

signals:

private:
    QTcpSocket *_socket;
    int _id;
    QString _name{};
    bool _isCalling{};
    int _callingTo{-84};
    bool _sendingAudio{};
};

#endif // USER_H
