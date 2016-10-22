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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *informationAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QDateEdit *dateEdit;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(770, 475);
        MainWindow->setAcceptDrops(false);
        informationAbout = new QAction(MainWindow);
        informationAbout->setObjectName(QStringLiteral("informationAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 2, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font);

        gridLayout->addWidget(comboBox, 2, 0, 1, 2);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem18);
        QBrush brush(QColor(170, 170, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setBackground(brush);
        tableWidget->setItem(0, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setBackground(brush);
        tableWidget->setItem(0, 1, __qtablewidgetitem20);
        QBrush brush1(QColor(0, 255, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem21->setBackground(brush1);
        tableWidget->setItem(0, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem22->setBackground(brush1);
        tableWidget->setItem(0, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(0, 5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(0, 6, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setBackground(brush);
        tableWidget->setItem(1, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem27->setBackground(brush1);
        tableWidget->setItem(1, 1, __qtablewidgetitem27);
        QBrush brush2(QColor(255, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem28->setBackground(brush2);
        tableWidget->setItem(1, 2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        __qtablewidgetitem29->setBackground(brush2);
        tableWidget->setItem(1, 3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setItem(1, 5, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setItem(1, 6, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setItem(1, 7, __qtablewidgetitem33);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(61);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(27);
        tableWidget->verticalHeader()->setMinimumSectionSize(21);

        gridLayout->addWidget(tableWidget, 2, 2, 4, 1);

        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setFont(font);
        dateEdit->setDateTime(QDateTime(QDate(2016, 1, 1), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 3, 0, 1, 2);

        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setFont(font);

        gridLayout->addWidget(comboBox_2, 4, 0, 1, 2);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 5, 0, 1, 2);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 6, 0, 1, 3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 770, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(informationAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        informationAbout->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\320\237\320\276\320\270\321\201\320\272:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\321\206\320\265\320\275\320\260", 0));
        pushButton->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\242\320\265\320\260\321\202\321\2001", 0)
         << QApplication::translate("MainWindow", "\320\242\320\265\320\260\321\202\321\2002", 0)
         << QApplication::translate("MainWindow", "\320\242\320\265\320\260\321\202\321\2003", 0)
        );
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(0, 2);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(0, 3);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(0, 4);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(0, 5);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(0, 6);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(1, 1);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "6", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(1, 2);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "7", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(1, 3);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "8", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(1, 4);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "9", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(1, 5);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "10", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->item(1, 6);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "11", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->item(1, 7);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "12", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\241\320\277\320\265\320\272\321\202\320\260\320\272\320\273\321\2141", 0)
         << QApplication::translate("MainWindow", "\320\241\320\277\320\265\320\272\321\202\320\260\320\272\320\273\321\2142", 0)
        );
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0));
        menu->setTitle(QApplication::translate("MainWindow", "&\320\236 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\265", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
