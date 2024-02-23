/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *LblTitle;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *GrpIp;
    QLabel *LblAddr;
    QLabel *LblPort;
    QLineEdit *LnAddr;
    QSpinBox *SpnPort;
    QPushButton *BtnConnect;
    QPushButton *RecBtn;
    QComboBox *CBInputs;
    QLabel *LblMicro;
    QLabel *LblOutput;
    QComboBox *CBOutputs;
    QPushButton *BtnLst;
    QGroupBox *GrpClient;
    QListWidget *LstUsers;
    QPushButton *BtnCall;
    QPushButton *BtnAccept;
    QPushButton *BtnRefuse;
    QLabel *LblFrom;
    QLineEdit *LnMessage;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QListWidget *LstConsole;
    QPushButton *BtnClear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1086, 590);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("#LnAddr[state = \"0\"] {\n"
"	background-color: rgb(237, 51, 59);\n"
"}\n"
"\n"
"#LnAddr[state = \"1\"] {\n"
"	background-color: rgb(38, 162, 105);\n"
"}\n"
"\n"
"#GrpIp {\n"
"	background-color: rgb(192, 191, 188);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"#GrpClient{\n"
"	background-color: rgb(192, 191, 188);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"#LblMicro {\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"#LblFrom {\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setAutoFillBackground(false);
        LblTitle = new QLabel(centralwidget);
        LblTitle->setObjectName("LblTitle");
        LblTitle->setGeometry(QRect(450, 10, 161, 41));
        QFont font;
        font.setPointSize(36);
        LblTitle->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 80, 521, 451));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        GrpIp = new QGroupBox(layoutWidget);
        GrpIp->setObjectName("GrpIp");
        GrpIp->setStyleSheet(QString::fromUtf8(""));
        LblAddr = new QLabel(GrpIp);
        LblAddr->setObjectName("LblAddr");
        LblAddr->setGeometry(QRect(10, 50, 66, 18));
        LblAddr->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        LblPort = new QLabel(GrpIp);
        LblPort->setObjectName("LblPort");
        LblPort->setGeometry(QRect(10, 90, 66, 18));
        LblPort->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        LnAddr = new QLineEdit(GrpIp);
        LnAddr->setObjectName("LnAddr");
        LnAddr->setGeometry(QRect(90, 50, 113, 26));
        LnAddr->setStyleSheet(QString::fromUtf8(""));
        SpnPort = new QSpinBox(GrpIp);
        SpnPort->setObjectName("SpnPort");
        SpnPort->setGeometry(QRect(90, 90, 111, 27));
        SpnPort->setStyleSheet(QString::fromUtf8(""));
        SpnPort->setMinimum(1024);
        SpnPort->setMaximum(65534);
        BtnConnect = new QPushButton(GrpIp);
        BtnConnect->setObjectName("BtnConnect");
        BtnConnect->setGeometry(QRect(60, 130, 161, 26));
        BtnConnect->setStyleSheet(QString::fromUtf8(""));
        RecBtn = new QPushButton(GrpIp);
        RecBtn->setObjectName("RecBtn");
        RecBtn->setGeometry(QRect(420, 180, 87, 26));
        CBInputs = new QComboBox(GrpIp);
        CBInputs->setObjectName("CBInputs");
        CBInputs->setGeometry(QRect(360, 140, 141, 31));
        LblMicro = new QLabel(GrpIp);
        LblMicro->setObjectName("LblMicro");
        LblMicro->setGeometry(QRect(260, 140, 91, 20));
        LblOutput = new QLabel(GrpIp);
        LblOutput->setObjectName("LblOutput");
        LblOutput->setGeometry(QRect(260, 80, 66, 18));
        CBOutputs = new QComboBox(GrpIp);
        CBOutputs->setObjectName("CBOutputs");
        CBOutputs->setGeometry(QRect(360, 80, 141, 31));
        BtnLst = new QPushButton(GrpIp);
        BtnLst->setObjectName("BtnLst");
        BtnLst->setGeometry(QRect(330, 180, 87, 26));

        verticalLayout_2->addWidget(GrpIp);

        GrpClient = new QGroupBox(layoutWidget);
        GrpClient->setObjectName("GrpClient");
        LstUsers = new QListWidget(GrpClient);
        LstUsers->setObjectName("LstUsers");
        LstUsers->setGeometry(QRect(260, 20, 256, 192));
        BtnCall = new QPushButton(GrpClient);
        BtnCall->setObjectName("BtnCall");
        BtnCall->setEnabled(false);
        BtnCall->setGeometry(QRect(170, 180, 87, 26));
        BtnAccept = new QPushButton(GrpClient);
        BtnAccept->setObjectName("BtnAccept");
        BtnAccept->setGeometry(QRect(10, 150, 87, 26));
        BtnRefuse = new QPushButton(GrpClient);
        BtnRefuse->setObjectName("BtnRefuse");
        BtnRefuse->setGeometry(QRect(10, 180, 87, 26));
        LblFrom = new QLabel(GrpClient);
        LblFrom->setObjectName("LblFrom");
        LblFrom->setGeometry(QRect(0, 10, 181, 71));
        LnMessage = new QLineEdit(GrpClient);
        LnMessage->setObjectName("LnMessage");
        LnMessage->setGeometry(QRect(10, 100, 113, 26));

        verticalLayout_2->addWidget(GrpClient);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(800, 80, 258, 441));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        LstConsole = new QListWidget(layoutWidget1);
        LstConsole->setObjectName("LstConsole");
        LstConsole->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 191, 188);"));

        verticalLayout->addWidget(LstConsole);

        BtnClear = new QPushButton(layoutWidget1);
        BtnClear->setObjectName("BtnClear");

        verticalLayout->addWidget(BtnClear);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1086, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(BtnClear, &QPushButton::clicked, LstConsole, qOverload<>(&QListWidget::clear));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        LblTitle->setText(QCoreApplication::translate("MainWindow", "BABEL", nullptr));
        GrpIp->setTitle(QCoreApplication::translate("MainWindow", "Connection information", nullptr));
        LblAddr->setText(QCoreApplication::translate("MainWindow", "Address :", nullptr));
        LblPort->setText(QCoreApplication::translate("MainWindow", "Port :", nullptr));
        LnAddr->setInputMask(QCoreApplication::translate("MainWindow", "000.000.000.000;_", nullptr));
        LnAddr->setProperty("state", QVariant(QString()));
        BtnConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        RecBtn->setText(QCoreApplication::translate("MainWindow", "Record", nullptr));
        LblMicro->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        LblOutput->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        BtnLst->setText(QCoreApplication::translate("MainWindow", "Listen", nullptr));
        GrpClient->setTitle(QCoreApplication::translate("MainWindow", "Connect to client : ", nullptr));
        BtnCall->setText(QCoreApplication::translate("MainWindow", "Call", nullptr));
        BtnAccept->setText(QCoreApplication::translate("MainWindow", "Accept", nullptr));
        BtnRefuse->setText(QCoreApplication::translate("MainWindow", "Refuse", nullptr));
        LblFrom->setText(QCoreApplication::translate("MainWindow", "You're being called by : ", nullptr));
        BtnClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
