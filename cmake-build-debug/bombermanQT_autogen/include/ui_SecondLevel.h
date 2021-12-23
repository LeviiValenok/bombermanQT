/********************************************************************************
** Form generated from reading UI file 'SecondLevel.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDLEVEL_H
#define UI_SECONDLEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondLevel
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SecondLevel)
    {
        if (SecondLevel->objectName().isEmpty())
            SecondLevel->setObjectName(QString::fromUtf8("SecondLevel"));
        SecondLevel->resize(800, 600);
        centralwidget = new QWidget(SecondLevel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 150, 171, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 150, 151, 31));
        SecondLevel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SecondLevel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        SecondLevel->setMenuBar(menubar);
        statusbar = new QStatusBar(SecondLevel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SecondLevel->setStatusBar(statusbar);

        retranslateUi(SecondLevel);

        QMetaObject::connectSlotsByName(SecondLevel);
    } // setupUi

    void retranslateUi(QMainWindow *SecondLevel)
    {
        SecondLevel->setWindowTitle(QCoreApplication::translate("SecondLevel", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("SecondLevel", "Start new game", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SecondLevel", "Exit nahooi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondLevel: public Ui_SecondLevel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDLEVEL_H
