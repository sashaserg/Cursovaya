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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
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
    QAction *action_addScene;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *tableInfo;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LabelCountSel;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_3;
    QDateEdit *dateEdit;
    QTableWidget *tableSeans;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(925, 591);
        MainWindow->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/theater.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("background-color: #f1f2f8;\n"
"background-color: #dde2e3;\n"
""));
        informationAbout = new QAction(MainWindow);
        informationAbout->setObjectName(QStringLiteral("informationAbout"));
        informationAbout->setMenuRole(QAction::TextHeuristicRole);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_exit->setCheckable(false);
        action_exit->setChecked(false);
        action_exit->setMenuRole(QAction::QuitRole);
        action_statistic_sale = new QAction(MainWindow);
        action_statistic_sale->setObjectName(QStringLiteral("action_statistic_sale"));
        options_room = new QAction(MainWindow);
        options_room->setObjectName(QStringLiteral("options_room"));
        action_addScene = new QAction(MainWindow);
        action_addScene->setObjectName(QStringLiteral("action_addScene"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(101, 41));
        comboBox->setMaximumSize(QSize(101, 41));
        QFont font;
        font.setFamily(QStringLiteral("Palatino Linotype"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        comboBox->setFont(font);
        comboBox->setStyleSheet(QLatin1String("background-color: #d3bb9c;\n"
"border-style: outset;\n"
"	"));
        comboBox->setFrame(true);

        horizontalLayout_3->addWidget(comboBox);

        horizontalSpacer_4 = new QSpacerItem(13, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(291, 41));
        label_4->setMaximumSize(QSize(291, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("High Tower Text"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_5 = new QSpacerItem(13, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

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
        tableInfo->setMinimumSize(QSize(191, 41));
        tableInfo->setMaximumSize(QSize(191, 41));
        QFont font2;
        font2.setPointSize(8);
        tableInfo->setFont(font2);
        tableInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableInfo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableInfo->horizontalHeader()->setVisible(false);
        tableInfo->horizontalHeader()->setDefaultSectionSize(97);
        tableInfo->horizontalHeader()->setMinimumSectionSize(33);
        tableInfo->verticalHeader()->setVisible(false);
        tableInfo->verticalHeader()->setDefaultSectionSize(20);

        horizontalLayout_3->addWidget(tableInfo);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(639, 31));

        horizontalLayout_4->addWidget(label_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setMinimumSize(QSize(605, 400));
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setAutoFillBackground(false);
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setShowGrid(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(61);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(27);
        tableWidget->verticalHeader()->setMinimumSectionSize(21);

        verticalLayout_5->addWidget(tableWidget);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LabelCountSel = new QLabel(centralWidget);
        LabelCountSel->setObjectName(QStringLiteral("LabelCountSel"));
        LabelCountSel->setMinimumSize(QSize(50, 20));

        horizontalLayout_2->addWidget(LabelCountSel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(160, 22));
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        label_3->setFont(font3);

        verticalLayout_2->addWidget(label_3);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 15));

        verticalLayout_4->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(150, 30));
        QFont font4;
        font4.setPointSize(10);
        lineEdit->setFont(font4);

        verticalLayout_4->addWidget(lineEdit);


        horizontalLayout_5->addLayout(verticalLayout_4);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy2);
        pushButton_4->setMinimumSize(QSize(60, 45));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: rgb(176, 181, 255);\n"
"border-style: outset;\n"
"border-radius: 10px;	\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: #376bbf\n"
"}\n"
""));

        horizontalLayout_5->addWidget(pushButton_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(80, 20));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color:#fada26;\n"
"border-style: outset;\n"
"border-radius: 5px;	\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: #376bbf\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(80, 20));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: #236c1b;\n"
"border-style: outset;\n"
"border-radius: 5px;	\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: #376bbf\n"
"}"));

        verticalLayout->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(120, 50));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: #b31e2c;\n"
"border-style: outset;\n"
"border-radius: 10px;	\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: #376bbf\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_5->addLayout(horizontalLayout);


        verticalLayout_5->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        dateEdit = new QDateEdit(centralWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMinimumSize(QSize(256, 30));
        QFont font5;
        font5.setPointSize(12);
        dateEdit->setFont(font5);
        dateEdit->setFocusPolicy(Qt::WheelFocus);
        dateEdit->setDateTime(QDateTime(QDate(2016, 1, 1), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);

        verticalLayout_3->addWidget(dateEdit);

        tableSeans = new QTableWidget(centralWidget);
        if (tableSeans->columnCount() < 2)
            tableSeans->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableSeans->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableSeans->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        tableSeans->setObjectName(QStringLiteral("tableSeans"));
        tableSeans->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableSeans->sizePolicy().hasHeightForWidth());
        tableSeans->setSizePolicy(sizePolicy3);
        tableSeans->setMinimumSize(QSize(256, 505));
        tableSeans->setContextMenuPolicy(Qt::CustomContextMenu);
        tableSeans->setStyleSheet(QLatin1String("background-color: #e5efe9;\n"
"background-color: #dde2e3;\n"
""));

        verticalLayout_3->addWidget(tableSeans);


        horizontalLayout_6->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 925, 21));
        menuBar->setStyleSheet(QLatin1String("QMenu::item:selected{ \n"
"background-color: #d3bb9c;\n"
"}"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_5->menuAction());
        menuBar->addAction(menu->menuAction());
        menu->addAction(informationAbout);
        menu_5->addAction(action_addScene);
        menu_5->addAction(options_room);
        menu_5->addAction(action);
        menu_5->addAction(action_statistic_sale);
        menu_5->addAction(action_exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VTeatre", 0));
        informationAbout->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
        action->setText(QApplication::translate("MainWindow", "\320\236\320\272\320\275\320\276 \320\277\320\276\320\272\321\203\320\277\320\260\321\202\320\265\320\273\321\217", 0));
        action_exit->setText(QApplication::translate("MainWindow", "&\320\222\321\213\321\205\320\276\320\264", 0));
        action_statistic_sale->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260 \320\277\321\200\320\276\320\264\320\260\320\266", 0));
        options_room->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\267\320\260\320\273\320\260", 0));
        action_addScene->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\321\203", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\237\320\260\321\200\321\202\320\265\321\200", 0)
         << QApplication::translate("MainWindow", "\320\221\320\265\320\275\321\203\320\260\321\200", 0)
         << QApplication::translate("MainWindow", "\320\221\320\265\320\273\321\214\321\215\321\202\320\260\320\266", 0)
        );
        label_4->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
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

        label_2->setText(QApplication::translate("MainWindow", "\320\241\321\206\320\265\320\275\320\260", 0));
        LabelCountSel->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\320\275\320\276: 0", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\232 \320\276\320\277\320\273\320\260\321\202\320\265: 0", 0));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\264 \320\261\321\200\320\276\320\275\320\270:", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\221\321\200\320\276\320\275\321\214", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\320\277\320\273\320\260\321\202\320\270\321\202\321\214", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableSeans->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\241\320\265\320\260\320\275\321\201", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableSeans->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        menu->setTitle(QApplication::translate("MainWindow", "&\320\236 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\265", 0));
        menu_5->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\260\321\202\321\200", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
