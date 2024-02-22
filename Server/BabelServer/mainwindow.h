#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStyle>
#include "udpserver.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetSendAudio(QString elem);
private slots:
    void on_BtnStart_clicked();
    void OnNewClientConnected();
    void ClientDisconnected();
    void ClientDataReceived(QByteArray message);

private:
    Ui::MainWindow *ui;
    std::shared_ptr<UDPServer> _server;
};

void SendIp(std::shared_ptr<UDPServer> _server,  QString str);
#endif // MAINWINDOW_H
