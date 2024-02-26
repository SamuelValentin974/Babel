#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMetaEnum>
#include <QSoundEffect>
#include <iostream>
#include <fstream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _audio = std::make_shared<AudioController>();
    _udpController = std::make_shared<UdpController>();
    SetDeviceController();
    foreach (auto device, QMediaDevices::audioInputs())
        ui->CBInputs->addItem(device.description());
    foreach (auto device, QMediaDevices::audioOutputs())
        ui->CBOutputs->addItem(device.description());
    connect(_audio.get(), &AudioController::BufferRead, this, &MainWindow::ReadBufferDecoder);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnConnect_clicked()
{
    if (_controller->IsConnected()) {
        _controller->disconnect();
    } else {
        auto address = ui->LnAddr->text();
        auto port = ui->SpnPort->value();
        _controller->connectToDevice(address, port);
    }
}

void MainWindow::device_connected()
{
    ui->LstConsole->addItem("Device connected");
    ui->BtnConnect->setText("Disconnect");
}

void MainWindow::device_disconnected()
{
    ui->LstConsole->addItem("Device disconnected");
    ui->BtnConnect->setText("Connect");
}

void MainWindow::device_stateChanged(QAbstractSocket::SocketState state)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    ui->LstConsole->addItem(metaEnum.valueToKey(state));
}

void MainWindow::device_errorOccurred(QAbstractSocket::SocketError error)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    ui->LstConsole->addItem(metaEnum.valueToKey(error));
}

void MainWindow::udp_connected()
{
    ui->LstConsole->addItem("Udp connected");
}

void MainWindow::udp_disconnected()
{
    ui->LstConsole->addItem("udp disconnected");
}

void MainWindow::udp_stateChanged(QAbstractSocket::SocketState state)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    ui->LstConsole->addItem(metaEnum.valueToKey(state));
}

void MainWindow::udp_errorOccurred(QAbstractSocket::SocketError error)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    ui->LstConsole->addItem(metaEnum.valueToKey(error));
}

void MainWindow::ReadBufferDecoder()
{
    QAudioBuffer buffer = _audio->decoder()->read();
    qDebug() << "Data read";
    QByteArray arr = "Audio " + QString::number(_controller->callTo()).toUtf8() + " ";
    arr.append(buffer.constData<char>(), buffer.byteCount());
    _controller->socket()->write(arr);
}

void MainWindow::tcp_SendAudio()
{
    if (_controller->inCall()) {
        QString path = "./test.wav";
        QFile file(path);
        int i = 0;
        int nb = 0;
        QByteArray strAudio = "Audio " + QString::number(_controller->callTo()).toUtf8() + " ";
        const int chunksize = 8192;
        const int firstchunk = 8192 - strAudio.size();
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "file couldn't be opened";
            throw std::exception();
        }
        while(!file.atEnd()) {
            if (i == 0) {
                QByteArray arr = file.read(firstchunk);
                nb += _controller->socket()->write(strAudio + arr);
                qDebug() << "DataSent, bytes wrote : " << nb;
                /*if (!_controller->socket()->waitForBytesWritten()) {
                    qDebug() << "Error With wait audio sent";
                    return;
                }*/
                i++;
            } else {
                QByteArray arr = file.read(chunksize);
                nb += _controller->socket()->write(arr);
                qDebug() << "DataSent, bytes wrote : " << nb;
                /*if (!_controller->socket()->waitForBytesWritten()) {
                    qDebug() << "Error With wait audio sent";
                    return;
                }*/
            }
        }
        file.close();
    }
}

void MainWindow::tcp_ReadAudio(QByteArray str)
{
    if (_controller->inCall()) {
        QString targetPath = QDir(QCoreApplication::applicationDirPath()).filePath("target.wav");
        QFile target(targetPath);
        qint64 bytesWritten = 0;
        int firstindex = str.indexOf(" ");
        QByteArray buff;

        if (str.contains("Audio")) {
            if (firstindex != -1) {
                int secondindex = str.indexOf(" ", firstindex + 1);
                if (secondindex != -1)
                    str.remove(0, secondindex + 1);
            }
        }
        buff = str;
        // while (_controller->socket()->waitForReadyRead()) {
        //     while (_controller->socket()->bytesAvailable() > 0) {
        //         str = _controller->socket()->readAll();
        //         buff += str;
        //         qDebug() << "Looping readaudio tcp";
        //     }
        // }
        if (!target.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Append)) {
            qDebug() << "file couldn't be opened";
            throw std::exception();
        }
        bytesWritten = target.write(buff);
        if (bytesWritten == -1) {
            qDebug() << "Erreur lors de l'écriture des données dans le fichier audio : " << target.errorString();
            return;
        }
        target.close();
        _controller->setReceivingData(false);
        ListenAudio();
        qDebug() << "Bytes written to file : " << bytesWritten;
        qDebug() << "File size sent = " << target.size();
    }
}


void MainWindow::ListenAudio(QByteArray array)
{
    _audio->player()->setAudioOutput(_audio->output().get());
    _audio->output()->setVolume(25);
    _audio->player()->setPosition(20);
    _audio->player()->setSource(QUrl::fromEncoded(array));
    _audio->player()->play();
}

void MainWindow::ListenAudio()
{
    _audio->player()->setAudioOutput(_audio->output().get());
    _audio->output()->setVolume(25);
    _audio->player()->setPosition(0);
    _audio->player()->setSource(QUrl::fromLocalFile("./target.wav"));
    _audio->player()->play();
}

void MainWindow::on_BtnLst_clicked()
{
    //QString path = QDir(QCoreApplication::applicationDirPath()).filePath("test.wav");
    QString path = "./test.wav";
    _audio->player()->setSource(path);
    _audio->player()->setPosition(0);
    _audio->player()->setAudioOutput(_audio->output().get());
    _audio->player()->play();
}

bool MainWindow::isMuted() const
{
    return _isMuted;
}

void MainWindow::setIsMuted(bool newIsMuted)
{
    _isMuted = newIsMuted;
}

void MainWindow::OpenFile()
{
    qDebug("In open filke");
    //std::ifstream infile((QDir(QCoreApplication::applicationDirPath()).filePath("test.wav")).toStdString()); // Open the file for reading
    std::ifstream infile("./test.wav");

    if (!infile) {
        std::cerr << "Error opening file." << std::endl;
        throw std::exception();
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::cout << "line = " << line << std::endl; // Output each line to the console
    }

    infile.close(); // Close the file
}

void MainWindow::udp_DataReady(QByteArray array)
{
    if (_controller->inCall()) {
        QByteArray buffer;
        _audio->player()->setAudioOutput(_audio->output().get());
        qint64 size = _udpController->socket()->pendingDatagramSize();
        qDebug() << "size = " << size;
        buffer.resize(size);

        QHostAddress sender;
        quint16 port = 0;
        _udpController->socket()->readDatagram(buffer.data(), buffer.size(), &sender, &port);
        qDebug() << "BUFFER SIZE : " << buffer.size();
        std::string str(buffer, buffer.length());
        _audio->player()->setSource(QUrl::fromEncoded(buffer));
        _audio->player()->play();
        if (!str.empty()) {
            qDebug() << "Message from: " << sender.toString();
            qDebug() << "Message port: " << port;
        }
    }
}

void MainWindow::udp_SendDatas()
{
    if (_controller->inCall()) {
             //QString path = QDir(QCoreApplication::applicationDirPath()).filePath("test.wav");
        QString path = "./test.wav";
        QFile file(path);
        if (!file.open(QIODevice::ReadWrite)) {
            qDebug() << "file couldn't be opened";
            throw std::exception();
        }
        QByteArray arr = file.readAll();
        qDebug() << "ARRAY SIZE : " << arr.size();

        _udpController->socket()->writeDatagram(arr, QHostAddress(_udpController->ip()), _udpController->portTo());
        qDebug() << "DataSent";
        file.close();
    }
}

void MainWindow::device_dataReady(QByteArray array)
{
    QString str = QString(array);
    if (str.contains("Client"))
        ui->LstUsers->clear();
    if (str.contains("Audio")) {
        _controller->setReceivingData(true);
        tcp_ReadAudio(array);
    } else {
        foreach(auto elem, str.split("\n")) {
            if (elem.contains("Client"))
                AddClientToLst(elem);
            else if (elem.contains("ID"))
                SetId(elem);
            else if (elem.contains("Called"))
                CalledFrom(elem);
            else if (elem.contains("Refused"))
                CallRefused(elem);
            else if (elem.contains("Accepted"))
                CallAccepted(elem);
            else if (elem.contains("IP"))
                SendBackIp(elem);
            else if (_controller->ReceivingData())
                tcp_ReadAudio(array);
        }
    }
}

void MainWindow::SendBackIp(QString elem)
{
    SetUdpController(elem);
    if (!_udpController->sentAddr()) {
        QString str = "IP " + QString::number(_controller->callTo()) + " " +
                      GetLocalIP() + " " + QString::number(_udpController->port());
        _controller->socket()->write(str.toUtf8());
        _udpController->setSentAddr(true);
    }
    _controller->setInCall(true);
    _timer = std::make_shared<QTimer>(this);
    connect(_timer.get(), &QTimer::timeout, this, &MainWindow::TimerSendData);
    _timer->start(475);
    _audio->RecordAudio();
    _audio->setIsRecording(true);
}

void MainWindow::TimerSendData()
{
    if (!_isMuted && _controller->inCall()) {
        _audio->StopRecord();
        _audio->setIsRecording(false);
        QString path = "./test.wav";
        QFile file(path);
        int i = 0;
        int nb = 0;
        QByteArray strAudio = "Audio " + QString::number(_controller->callTo()).toUtf8() + " ";
        const int chunksize = 8192;
        const int firstchunk = 8192 - strAudio.size();
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "file couldn't be opened";
            throw std::exception();
        }


        while(!file.atEnd() && nb < chunksize * 7) {
            if (i == 0) {
                QByteArray arr = file.read(firstchunk);
                nb += _controller->socket()->write(strAudio + arr);
                _controller->socket()->flush();
                qDebug() << "DataSent, bytes wrote : " << nb;
                // if (!_controller->socket()->waitForBytesWritten()) {
                //     qDebug() << "Error With wait audio sent";
                //     return;
                // }
                i++;
            } else {
                QByteArray arr = file.read(chunksize);
                nb += _controller->socket()->write(arr);
                _controller->socket()->flush();
                qDebug() << "DataSent, bytes wrote : " << nb;
                // if (!_controller->socket()->waitForBytesWritten()) {
                //     qDebug() << "Error With wait audio sent";
                //     return;
                // }
            }
        }
        QByteArray arr = file.read(chunksize);
        nb += _controller->socket()->write(arr);
        _controller->socket()->flush();
        file.close();
        _audio->RecordAudio();
        _audio->setIsRecording(true);
    }
}

void MainWindow::AddClientToLst(QString str)
{
    ui->LstUsers->addItem(str);
}

void MainWindow::SetId(QString str)
{
    _controller->SetId(str.section(" ", 1, 1).toInt());
    qDebug() << "id = " << _controller->id();
}

void MainWindow::CalledFrom(QString str)
{
    ui->LblFrom->setText("You're being called by : Client " + str.section(" ", 1, 1));
    _controller->setCallTo(str.section(" ", 1, 1).toInt());
}

void MainWindow::CallRefused(QString str)
{
    ui->LblFrom->setText("Client " + str.section(" ", 1, 1) + " Refused");
    _controller->setCallTo(-84);
}

void MainWindow::SetDeviceController()
{
    _controller = std::make_shared<DeviceController>();
    connect(_controller.get(), &DeviceController::connected, this, &MainWindow::device_connected);
    connect(_controller.get(), &DeviceController::disconnected, this, &MainWindow::device_disconnected);
    connect(_controller.get(), &DeviceController::stateChanged, this, &MainWindow::device_stateChanged);
    connect(_controller.get(), &DeviceController::errorOccurred, this, &MainWindow::device_errorOccurred);
    connect(_controller.get(), &DeviceController::DataReady, this, &MainWindow::device_dataReady);
}

void MainWindow::SetUdpController(QString elem)
{
    _udpController->setPortTo(elem.section(" ", 3, 3).toInt());
    _udpController->setIp(elem.section(" ", 2, 2));
    _udpController->StartSocket();
    connect(_udpController.get(), &UdpController::DataReady, this, &MainWindow::udp_DataReady);
}

void  MainWindow::CallAccepted(QString str)
{
    ui->LblFrom->setText("In call with Client "  + QString::number(_controller->callTo()));
    _controller->setInCall(true);
}

void MainWindow::on_LnAddr_textChanged(const QString &arg1)
{
    QString state = "0";

    if (arg1 == "...") {
        state = "";
    } else {
        QHostAddress addr(arg1);

        if (QAbstractSocket::IPv4Protocol == addr.protocol()) {
            state = "1";
        }
    }
    ui->LnAddr->setProperty("state", state);
    style()->polish(ui->LnAddr);
}

void MainWindow::on_RecBtn_clicked()
{
    if (!_audio->isRecording()) {
        _audio->RecordAudio();
        ui->RecBtn->setText("Stop");
        _audio->setIsRecording(true);
    } else {
        _audio->StopRecord();
        ui->RecBtn->setText("Record");
        _audio->setIsRecording(false);
        if (_controller->inCall()) {
            qDebug() << "before open file";
            //udp_SendDatas();
            tcp_SendAudio();
        }
    }
}

void MainWindow::on_CBInputs_currentIndexChanged(int index)
{
    _audio->SetInputAudio(QMediaDevices::audioInputs()[index]);
}


void MainWindow::on_CBOutputs_currentIndexChanged(int index)
{
    _audio->setOutput(QMediaDevices::audioOutputs()[index]);
}

void MainWindow::on_LstUsers_itemActivated(QListWidgetItem *item)
{
    ui->BtnCall->setEnabled(true);
    QString str = item->text();
    _controller->setCallTo(str.section(" ", 1, 1).toInt());
}

void MainWindow::on_BtnCall_clicked()
{
    if (_controller->callTo() != -84 && !_controller->inCall())
        _controller->socket()->write(QString("Calling " + QString::number(_controller->id()) + " " + QString::number(_controller->callTo()) + "\n").toUtf8());
}

void MainWindow::on_LstUsers_itemChanged(QListWidgetItem *item)
{
    ui->BtnCall->setEnabled(true);
    QString str = item->text();
    _controller->setCallTo(str.section(" ", 1, 1).toInt());
}

void MainWindow::on_BtnAccept_clicked()
{
    if (_controller->callTo() != -84 && !_controller->inCall()) {
        QString str = "IP " + QString::number(_controller->callTo()) + " " + GetLocalIP() + " " + QString::number(_udpController->port());
        _controller->socket()->write(("Accepted " + QString::number(_controller->id()) + " " + QString::number(_controller->callTo()) + "\n").toUtf8());
        _controller->socket()->write(str.toUtf8());
        ui->LblFrom->setText("In call with Client "  + QString::number(_controller->callTo()));
        _udpController->setSentAddr(true);
        _controller->setInCall(true);
    }
}

void MainWindow::on_BtnRefuse_clicked()
{
    if (_controller->callTo() != -84) {
        _controller->socket()->write(("Refused " + QString::number(_controller->id()) + " " + QString::number(_controller->callTo()) + "\n").toUtf8());
        ui->LblFrom->setText("Refused call with client "  + QString::number(_controller->callTo()));
    }
}


void MainWindow::on_BtnMute_clicked()
{
    _isMuted = !_isMuted;
    if (_isMuted) {
        ui->BtnMute->setText("Unmute");
        if (_controller->inCall() &&  _audio->recorder()->recorderState() == QMediaRecorder::RecordingState)
            _audio->StopRecord();
    } else {
        ui->BtnMute->setText("Mute");
        if (_controller->inCall() && _audio->recorder()->recorderState() == QMediaRecorder::StoppedState)
            _audio->RecordAudio();
    }
}

