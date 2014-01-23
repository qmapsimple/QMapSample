/********************************************************************************
** Form generated from reading UI file 'testclient.ui'
**
** Created: Tue Jan 7 16:19:46 2014
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCLIENT_H
#define UI_TESTCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestClientClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionViewEntire;
    QAction *actionPan;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuMap;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestClientClass)
    {
        if (TestClientClass->objectName().isEmpty())
            TestClientClass->setObjectName(QString::fromUtf8("TestClientClass"));
        TestClientClass->resize(800, 600);
        TestClientClass->setAnimated(true);
        actionOpen = new QAction(TestClientClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(TestClientClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionClose = new QAction(TestClientClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionZoomIn = new QAction(TestClientClass);
        actionZoomIn->setObjectName(QString::fromUtf8("actionZoomIn"));
        actionZoomOut = new QAction(TestClientClass);
        actionZoomOut->setObjectName(QString::fromUtf8("actionZoomOut"));
        actionViewEntire = new QAction(TestClientClass);
        actionViewEntire->setObjectName(QString::fromUtf8("actionViewEntire"));
        actionPan = new QAction(TestClientClass);
        actionPan->setObjectName(QString::fromUtf8("actionPan"));
        centralWidget = new QWidget(TestClientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TestClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestClientClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        menuBar->setFont(font);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuMap = new QMenu(menuBar);
        menuMap->setObjectName(QString::fromUtf8("menuMap"));
        TestClientClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(TestClientClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestClientClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuMap->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionClose);
        menuMap->addAction(actionZoomIn);
        menuMap->addAction(actionZoomOut);
        menuMap->addAction(actionViewEntire);
        menuMap->addAction(actionPan);

        retranslateUi(TestClientClass);

        QMetaObject::connectSlotsByName(TestClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestClientClass)
    {
        TestClientClass->setWindowTitle(QApplication::translate("TestClientClass", "QT\350\214\203\344\276\213\347\250\213\345\272\217", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("TestClientClass", "Open", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("TestClientClass", "Save", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("TestClientClass", "Close", 0, QApplication::UnicodeUTF8));
        actionZoomIn->setText(QApplication::translate("TestClientClass", "ZoomIn", 0, QApplication::UnicodeUTF8));
        actionZoomOut->setText(QApplication::translate("TestClientClass", "ZoomOut", 0, QApplication::UnicodeUTF8));
        actionViewEntire->setText(QApplication::translate("TestClientClass", "ViewEntire", 0, QApplication::UnicodeUTF8));
        actionPan->setText(QApplication::translate("TestClientClass", "Pan", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("TestClientClass", "File", 0, QApplication::UnicodeUTF8));
        menuMap->setTitle(QApplication::translate("TestClientClass", "Map", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TestClientClass: public Ui_TestClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCLIENT_H
