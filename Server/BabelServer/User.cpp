#include "User.h"

User::User(QObject *parent)
    : QObject{parent}
{}

int User::id() const
{
    return _id;
}

void User::setId(int newId)
{
    _id = newId;
}

QTcpSocket *User::socket() const
{
    return _socket;
}

void User::setSocket(QTcpSocket *newSocket)
{
    _socket = newSocket;
}

bool User::isCalling() const
{
    return _isCalling;
}

void User::setIsCalling(bool newIsCalling)
{
    _isCalling = newIsCalling;
}

int User::callingTo() const
{
    return _callingTo;
}

void User::setCallingTo(int newCallingTo)
{
    _callingTo = newCallingTo;
}

bool User::sendingAudio() const
{
    return _sendingAudio;
}

void User::setSendingAudio(bool newSendingAudio)
{
    _sendingAudio = newSendingAudio;
}
