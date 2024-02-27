#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _server = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnStart_clicked()
{
    if (_server == nullptr) {
        auto port = ui->SpnPort->value();
        _server = std::make_shared<UDPServer>(port);
        connect(_server.get(), &UDPServer::NewClientConnected, this, &MainWindow::OnNewClientConnected);
        connect(_server.get(), &UDPServer::DataReceived, this, &MainWindow::ClientDataReceived);
        connect(_server.get(), &UDPServer::ClientDisconnect, this, &MainWindow::ClientDisconnected);
    }
    auto state = (_server->isStarted()) ? "1" : "0";
    ui->LblStatus->setProperty("state", state);
    style()->polish(ui->LblStatus);
}

void MainWindow::OnNewClientConnected()
{
    ui->LstConsole->addItem("New Client Connected");
}

void MainWindow::ClientDisconnected()
{
    ui->LstConsole->addItem("Client Disconnected");
}

void MainWindow::SetSendAudio(QString elem)
{
    auto socket = qobject_cast<QTcpSocket *>(sender());
    int idTo = elem.section(" ", 1, 1).toInt();
}

void MainWindow::ClientDataReceived(QByteArray message)
{
    QString str = (QString(message));
    _server->CheckClients();
    if (str.contains("Audio"))
        SendAudio(_server, message);
    else if (str.contains("Record"))
            SendRecord(_server, message);
    else {
        foreach (auto elem, str.split("\n")) {
            if (elem.section(" ", 0, 0) == "Calling") {
                CallClient(_server, elem);
            } else if (elem.section(" ", 0, 0) == "Accepted") {
                AcceptCall(_server, elem);
            } else if (elem.section(" ", 0, 0) == "Refused") {
                RefuseCall(_server, elem);
            } else if (elem.section(" ", 0, 0) == "IP") {
                SendIp(_server, elem);
            }
        }
        // ui->LstConsole->addItem(message);
    }
}

