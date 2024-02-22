#include "DeviceController.h"

void CallClient(const std::shared_ptr<DeviceController> &device, QString str)
{
    QString id = "Calling " + QString::number(device->id()) + " " +  str.section(" ", 1, 1);
    device->socket()->write(id.toUtf8());
}

QString GetLocalIP()
{
    QList<QNetworkInterface> allInterfaces = QNetworkInterface::allInterfaces();

    foreach (const auto &interfaces, allInterfaces) {
        QNetworkInterface::InterfaceFlags flags = interfaces.flags();
        if ((bool)(flags & QNetworkInterface::IsRunning) && !(bool)(flags & QNetworkInterface::IsLoopBack)) {
            foreach(const auto &addr,  interfaces.addressEntries()) {
                if (addr.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                    return addr.ip().toString();
                }
            }
        }
    }
    return "";
}

QNetworkAddressEntry GetIP()
{
    QList<QNetworkInterface> allInterfaces = QNetworkInterface::allInterfaces();

    foreach (const auto &interfaces, allInterfaces) {
        QNetworkInterface::InterfaceFlags flags = interfaces.flags();
        if ((bool)(flags & QNetworkInterface::IsRunning) && !(bool)(flags & QNetworkInterface::IsLoopBack)) {
            foreach(const auto &addr,  interfaces.addressEntries()) {
                if (addr.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                    return addr;
                }
            }
        }
    }
}

