/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBoxOption;
    QComboBox *comboBoxTheaterChoice;
    QLabel *labelTheaterName;
    QLabel *label;
    QCalendarWidget *calendarWidget;
    QGroupBox *groupBoxMainSpace;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 698);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBoxOption = new QGroupBox(centralWidget);
        groupBoxOption->setObjectName(QStringLiteral("groupBoxOption"));
        groupBoxOption->setGeometry(QRect(10, 100, 251, 371));
        comboBoxTheaterChoice = new QComboBox(groupBoxOption);
        comboBoxTheaterChoice->setObjectName(QStringLiteral("comboBoxTheaterChoice"));
        comboBoxTheaterChoice->setGeometry(QRect(10, 40, 111, 31));
        comboBoxTheaterChoice->setEditable(false);
        labelTheaterName = new QLabel(groupBoxOption);
        labelTheaterName->setObjectName(QStringLiteral("labelTheaterName"));
        labelTheaterName->setGeometry(QRect(10, 20, 111, 21));
        label = new QLabel(groupBoxOption);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 80, 46, 13));
        calendarWidget = new QCalendarWidget(groupBoxOption);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 94, 221, 171));
        groupBoxMainSpace = new QGroupBox(centralWidget);
        groupBoxMainSpace->setObjectName(QStringLiteral("groupBoxMainSpace"));
        groupBoxMainSpace->setGeometry(QRect(270, 100, 361, 371));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 70, 121, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 70, 41, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\222\320\242\320\265\320\260\321\202\321\200", 0));
        groupBoxOption->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\260\321\202\321\200", 0));
        comboBoxTheaterChoice->clear();
        comboBoxTheaterChoice->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\242\320\265\320\260\321\202\321\2001", 0)
         << QApplication::translate("MainWindow", "\320\242\320\265\320\260\321\202\321\2002", 0)
         << QApplication::translate("MainWindow", "\320\242\320\265\320\260\321\202\321\2003", 0)
         << QApplication::translate("MainWindow", "\320\242\320\265\320\260\321\202\321\2004", 0)
        );
        comboBoxTheaterChoice->setCurrentText(QApplication::translate("MainWindow", "\320\242\320\265\320\260\321\202\321\2001", 0));
        labelTheaterName->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\320\265\320\260\321\202\321\200\320\260:", 0));
        label->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260:", 0));
        groupBoxMainSpace->setTitle(QApplication::translate("MainWindow", "\320\221\320\270\320\273\320\265\321\202", 0));
        lineEdit->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272...", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
