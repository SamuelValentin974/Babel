#include "udpserver.h"
#include <iostream>

void UDPServer::SendClientsConnected()
{
    foreach (auto user, _userList) {
        foreach (auto sd, _userList) {
            if (user->id() != sd->id()) {
                QString str = "Client " + QString::number(sd->id()) + "\n";
                user->socket()->write(str.toUtf8());
                user->socket()->flush();
            }
        }
    }
}

void CallClient(std::shared_ptr<UDPServer> _server,  QString str)
{
    int idFrom = str.section(" ", 1, 1).toInt();
    int idTo = str.section(" ", 2, 2).toInt();
    auto userFrom = _server->GetUserFromId(idFrom);
    auto userTo = _server->GetUserFromId(idTo);

    if (!userFrom || !userTo) {
        qDebug() << "Users not found";
        return;
    }
    //if (!users[idFrom]->isCalling() && !users[idTo]->isCalling()) {
    qDebug() << "Start call from " << idFrom << " to " << idTo;
    userTo->socket()->write(("Called " + QString::number(idFrom)).toUtf8());
    userTo->socket()->flush();
   // }
}

void AcceptCall(std::shared_ptr<UDPServer> _server,  QString str)
{
    int idFrom = str.section(" ", 1, 1).toInt();
    int idTo = str.section(" ", 2, 2).toInt();
    auto userFrom = _server->GetUserFromId(idFrom);
    auto userTo = _server->GetUserFromId(idTo);
    if (!userFrom || !userTo) {
        qDebug() << "Users not found";
        return;
    }
    userFrom->setIsCalling(true);
    userFrom->socket()->write("Accepted\n");
    userFrom->setCallingTo(idTo);
    userTo->setIsCalling(true);
    userTo->socket()->write("Accepted\n");
    userTo->setCallingTo(idFrom);
}

void RefuseCall(std::shared_ptr<UDPServer> _server,  QString str)
{
    int idFrom = str.section(" ", 1, 1).toInt();
    int idTo = str.section(" ", 2, 2).toInt();
    auto userFrom = _server->GetUserFromId(idFrom);
    auto userTo = _server->GetUserFromId(idTo);

    if (!userFrom || !userTo) {
        qDebug() << "Users not found";
        return;
    }
    if (!userFrom->isCalling() && !userTo->isCalling()) {
        qDebug() << "Start call from " << idFrom << " to " << idTo;
        userTo->socket()->write("Refused\n");
        userTo->socket()->flush();
        userFrom->socket()->write("Refused\n");
        userFrom->socket()->flush();
    }
}

void SendIp(std::shared_ptr<UDPServer> _server,  QString str)
{
    int idTo = str.section(" ", 1, 1).toInt();
    auto userTo = _server->GetUserFromId(idTo);
    if (!userTo) {
        qDebug() << "Users not found";
        return;
    }
    userTo->socket()->write(str.toUtf8());
}

void SendEnd(std::shared_ptr<UDPServer> _server,  QString str)
{
    int idTo = str.section(" ", 1, 1).toInt();
    auto userTo = _server->GetUserFromId(idTo);

    if (!userTo) {
        qDebug() << "Users not found";
        return;
    }
    userTo->socket()->write(str.toUtf8());
}

void SendAudio(std::shared_ptr<UDPServer> _server,  QByteArray str)
{
    QString line = QString(str);
    qint64 bytesWritten = 0;
    int idTo = line.section(" ", 1, 1).toInt();
    auto userTo = _server->GetUserFromId(idTo);
    auto userFrom = _server->GetUserFromId(userTo->callingTo());

    if (!userTo) {
        qDebug() << "Users not found";
        return;
    }
    bytesWritten = userTo->socket()->write(str);
    qDebug() << "Bytes written before loop = " << bytesWritten;
    // while (userFrom->socket()->waitForReadyRead()) {
    //     while (userFrom->socket()->bytesAvailable() > 0) {
    //         QByteArray buffer = userFrom->socket()->readAll();
    //         bytesWritten += userTo->socket()->write(buffer);
    //         if (bytesWritten == -1) {
    //             qDebug() << "Erreur lors de l'écriture des données dans le fichier audio : " << userTo->socket()->errorString();
    //             return;
    //         }
    //         qDebug() << "Looping";
    //     }
    // }
    // qDebug() << "Bytes written after loop = " << bytesWritten;
    userTo->socket()->flush();
}

void SendRecord(std::shared_ptr<UDPServer> _server,  QByteArray str)
{
    QString line = QString(str);
    qint64 bytesWritten = 0;
    int idTo = line.section(" ", 1, 1).toInt();
    auto userTo = _server->GetUserFromId(idTo);
    auto userFrom = _server->GetUserFromId(userTo->callingTo());

    if (!userTo) {
        qDebug() << "Users not found";
        return;
    }
    bytesWritten = userTo->socket()->write(str);
    qDebug() << "Bytes written before loop = " << bytesWritten;
    while (userFrom->socket()->waitForReadyRead()) {
        while (userFrom->socket()->bytesAvailable() > 0) {
            QByteArray buffer = userFrom->socket()->readAll();
            bytesWritten += userTo->socket()->write(buffer);
            if (bytesWritten == -1) {
                qDebug() << "Erreur lors de l'écriture des données dans le fichier audio : " << userTo->socket()->errorString();
                return;
            }
            qDebug() << "Looping";
        }
    }
    qDebug() << "Bytes written after loop = " << bytesWritten;
}
