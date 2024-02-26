#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DeviceController.h"
#include "AudioController.h"
#include <QTimer>

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
    void SetDeviceController();
    ~MainWindow();

    void OpenFile();
    void AddClientToLst(QString str);
    void SetId(QString str);
    void CalledFrom(QString str);
    void CallAccepted(QString str);
    void CallRefused(QString str);
    void SetUdpController(QString elem);
    void udp_SendDatas();
    void tcp_SendAudio();
    void tcp_ReadAudio();
    void tcp_ReadAudio(QByteArray str);
    void ListenAudio();
    void SendBackIp(QString elem);
    bool isMuted() const;
    void setIsMuted(bool newIsMuted);

    bool isFirstListen() const;
    void setIsFirstListen(bool newIsFirstListen);

    void ListenAudio(QByteArray array);
private slots:
    void on_BtnConnect_clicked();

    void ReadBufferDecoder();

    void device_connected();
    void device_disconnected();
    void device_stateChanged(QAbstractSocket::SocketState);
    void device_errorOccurred(QAbstractSocket::SocketError);
    void device_dataReady(QByteArray array);

    void udp_connected();
    void udp_disconnected();
    void udp_stateChanged(QAbstractSocket::SocketState);
    void udp_errorOccurred(QAbstractSocket::SocketError);
    void udp_DataReady(QByteArray array);

    void on_LnAddr_textChanged(const QString &arg1);
    void on_RecBtn_clicked();
    void on_CBInputs_currentIndexChanged(int index);
    void on_CBOutputs_currentIndexChanged(int index);
    void on_LstUsers_itemActivated(QListWidgetItem *item);
    void on_BtnCall_clicked();
    void on_LstUsers_itemChanged(QListWidgetItem *item);
    void on_BtnAccept_clicked();
    void on_BtnRefuse_clicked();

    void on_BtnLst_clicked();

    void TimerSendData();
    void on_BtnMute_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<UdpController> _udpController;
    std::shared_ptr<DeviceController> _controller;
    std::shared_ptr<AudioController> _audio;
    std::shared_ptr<QTimer> _timer;
    bool _isFirstListen{};
    bool _isMuted{};
};

#endif // MAINWINDOW_H
