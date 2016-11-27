/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *informationAbout;
    QAction *action;
    QAction *action_exit;
    QAction *action_statistic_sale;
    QAction *options_room;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QTableWidget *tableInfo;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QDateEdit *dateEdit;
    QTableWidget *tableSeans;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(929, 620);
        MainWindow->setAcceptDrops(false);
        MainWindow->setStyleSheet(QLatin1String("background-color: #f1f2f8;\n"
""));
        informationAbout = new QAction(MainWindow);
        informationAbout->setObjectName(QStringLiteral("informationAbout"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_statistic_sale = new QAction(MainWindow);
        action_statistic_sale->setObjectName(QStringLiteral("action_statistic_sale"));
        options_room = new QAction(MainWindow);
        options_room->setObjectName(QStringLiteral("options_room"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 100, 611, 401));
        tableWidget->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-width: 5px;\n"
"border-radius: 10px;		\n"
"border-color: #d3bb9c;\n"
"\n"
"\n"
"					"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setShowGrid(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(61);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(27);
        tableWidget->verticalHeader()->setMinimumSectionSize(21);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 611, 31));
        tableInfo = new QTableWidget(centralWidget);
        if (tableInfo->columnCount() < 2)
            tableInfo->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableInfo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableInfo->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableInfo->rowCount() < 2)
            tableInfo->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableInfo->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableInfo->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableInfo->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableInfo->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableInfo->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableInfo->setItem(1, 1, __qtablewidgetitem7);
        tableInfo->setObjectName(QStringLiteral("tableInfo"));
        tableInfo->setGeometry(QRect(430, 10, 191, 41));
        QFont font;
        font.setPointSize(8);
        tableInfo->setFont(font);
        tableInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableInfo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableInfo->horizontalHeader()->setVisible(false);
        tableInfo->horizontalHeader()->setDefaultSectionSize(97);
        tableInfo->horizontalHeader()->setMinimumSectionSize(33);
        tableInfo->verticalHeader()->setVisible(false);
        tableInfo->verticalHeader()->setDefaultSectionSize(20);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(500, 510, 121, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Palatino Linotype"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("background-color: #b31e2c;\n"
"border-style: outset;\n"
"border-radius: 10px;	\n"
""));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 111, 41));
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QLatin1String("background-color: #d3bb9c;\n"
"border-style: outset;\n"
"	"));
        comboBox->setFrame(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(630, 10, 291, 551));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMinimumSize(QSize(256, 30));
        QFont font2;
        font2.setPointSize(12);
        dateEdit->setFont(font2);
        dateEdit->setDateTime(QDateTime(QDate(2016, 1, 1), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);

        verticalLayout->addWidget(dateEdit);

        tableSeans = new QTableWidget(layoutWidget);
        if (tableSeans->columnCount() < 2)
            tableSeans->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableSeans->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableSeans->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        tableSeans->setObjectName(QStringLiteral("tableSeans"));
        tableSeans->setEnabled(true);
        tableSeans->setMinimumSize(QSize(256, 473));
        tableSeans->setStyleSheet(QStringLiteral("background-color:rgb(239, 236, 253);"));

        verticalLayout->addWidget(tableSeans);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 510, 171, 51));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));
        QFont font3;
        font3.setFamily(QStringLiteral("MS Serif"));
        font3.setPointSize(9);
        label->setFont(font3);

        verticalLayout_2->addWidget(label);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font3);

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 10, 291, 41));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 510, 81, 21));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QLatin1String("background-color:#fada26;\n"
"border-style: outset;\n"
"border-radius: 10px;	\n"
""));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 540, 81, 21));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QLatin1String("background-color: #236c1b;\n"
"border-style: outset;\n"
"border-radius: 10px;	\n"
""));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(190, 541, 141, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 929, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(informationAbout);
        menu_2->addAction(action);
        menu_2->addSeparator();
        menu_2->addAction(action_exit);
        menu_3->addAction(action_statistic_sale);
        menu_4->addAction(options_room);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VTeatre", 0));
        informationAbout->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
        action->setText(QApplication::translate("MainWindow", "\320\236\320\272\320\275\320\276 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\217", 0));
        action_exit->setText(QApplication::translate("MainWindow", "&\320\222\321\213\321\205\320\276\320\264", 0));
        action_statistic_sale->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\260\320\266\320\260", 0));
        options_room->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\267\320\260\320\273\320\260", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\321\206\320\265\320\275\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem = tableInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableInfo->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableInfo->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260", 0));

        const bool __sortingEnabled = tableInfo->isSortingEnabled();
        tableInfo->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableInfo->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\222\321\201\320\265\320\263\320\276 \320\274\320\265\321\201\321\202:", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableInfo->item(0, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\260\320\275\320\276:", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableInfo->item(1, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\241\320\262\320\276\320\261\320\276\320\264\320\275\320\276:", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableInfo->item(1, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\221\321\200\320\276\320\275\321\214:", 0));
        tableInfo->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\273\320\260\321\202\320\270\321\202\321\214", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\237\320\260\321\200\321\202\320\265\321\200", 0)
         << QApplication::translate("MainWindow", "\320\221\320\265\320\275\321\203\320\260\321\200", 0)
         << QApplication::translate("MainWindow", "\320\221\320\265\320\273\321\214\321\215\321\202\320\260\320\266", 0)
        );
        QTableWidgetItem *___qtablewidgetitem8 = tableSeans->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\241\320\265\320\260\320\275\321\201", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableSeans->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        label->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\321\207\320\265\320\275\320\276:", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\232 \320\276\320\277\320\273\320\260\321\202\320\265:", 0));
        label_4->setText(QApplication::translate("MainWindow", "\321\202\321\203\321\202 \320\273\320\265\320\263\320\265\320\275\320\264\320\260", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\221\321\200\320\276\320\275\321\214", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214", 0));
        label_5->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "&\320\236 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\265", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", 0));
        menu_4->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
