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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
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
    QGroupBox *GrpInfo;
    QLabel *LblPort;
    QSpinBox *SpnPort;
    QPushButton *BtnStart;
    QLabel *LblStatus;
    QWidget *widget;
    QVBoxLayout *LayConsole;
    QListWidget *LstConsole;
    QPushButton *BtnClear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(879, 492);
        MainWindow->setStyleSheet(QString::fromUtf8("#LblStatus[state = \"0\"] {\n"
"	background-color: rgb(237, 51, 59);\n"
"}\n"
"\n"
"#LblStatus[state = \"1\"] {\n"
"	background-color: rgb(38, 162, 105);\n"
"}\n"
"\n"
"#GrpInfo{\n"
"	background-color: rgb(192, 191, 188);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"#LblPort {\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"#LayConsole{\n"
"	background-color: rgb(192, 191, 188);\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        GrpInfo = new QGroupBox(centralwidget);
        GrpInfo->setObjectName("GrpInfo");
        GrpInfo->setGeometry(QRect(20, 40, 321, 191));
        LblPort = new QLabel(GrpInfo);
        LblPort->setObjectName("LblPort");
        LblPort->setGeometry(QRect(10, 50, 41, 18));
        SpnPort = new QSpinBox(GrpInfo);
        SpnPort->setObjectName("SpnPort");
        SpnPort->setGeometry(QRect(50, 50, 71, 27));
        SpnPort->setMinimum(1024);
        SpnPort->setMaximum(65535);
        BtnStart = new QPushButton(GrpInfo);
        BtnStart->setObjectName("BtnStart");
        BtnStart->setGeometry(QRect(50, 80, 87, 26));
        LblStatus = new QLabel(GrpInfo);
        LblStatus->setObjectName("LblStatus");
        LblStatus->setGeometry(QRect(10, 80, 25, 25));
        LblStatus->setMinimumSize(QSize(25, 25));
        LblStatus->setMaximumSize(QSize(25, 25));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(590, 50, 258, 381));
        LayConsole = new QVBoxLayout(widget);
        LayConsole->setObjectName("LayConsole");
        LayConsole->setContentsMargins(0, 0, 0, 0);
        LstConsole = new QListWidget(widget);
        LstConsole->setObjectName("LstConsole");

        LayConsole->addWidget(LstConsole);

        BtnClear = new QPushButton(widget);
        BtnClear->setObjectName("BtnClear");

        LayConsole->addWidget(BtnClear);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 879, 23));
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
        GrpInfo->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        LblPort->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        BtnStart->setText(QCoreApplication::translate("MainWindow", "Start Server", nullptr));
        LblStatus->setText(QString());
        LblStatus->setProperty("state", QVariant(QCoreApplication::translate("MainWindow", "0", nullptr)));
        BtnClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
