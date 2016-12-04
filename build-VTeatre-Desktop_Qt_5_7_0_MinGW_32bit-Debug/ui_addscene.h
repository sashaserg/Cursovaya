/********************************************************************************
** Form generated from reading UI file 'addscene.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSCENE_H
#define UI_ADDSCENE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_AddScene
{
public:
    QPushButton *ButtonAdd;
    QTextEdit *textEditName;
    QLabel *labeName;
    QLabel *labelDateTime;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QGroupBox *groupBoxPrice;
    QDoubleSpinBox *ParterPrice;
    QDoubleSpinBox *BenuarPrice;
    QDoubleSpinBox *BeletazPrice;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AddScene)
    {
        if (AddScene->objectName().isEmpty())
            AddScene->setObjectName(QStringLiteral("AddScene"));
        AddScene->resize(497, 180);
        ButtonAdd = new QPushButton(AddScene);
        ButtonAdd->setObjectName(QStringLiteral("ButtonAdd"));
        ButtonAdd->setGeometry(QRect(380, 110, 101, 51));
        QFont font;
        font.setPointSize(10);
        ButtonAdd->setFont(font);
        textEditName = new QTextEdit(AddScene);
        textEditName->setObjectName(QStringLiteral("textEditName"));
        textEditName->setGeometry(QRect(10, 30, 251, 31));
        textEditName->setFont(font);
        labeName = new QLabel(AddScene);
        labeName->setObjectName(QStringLiteral("labeName"));
        labeName->setGeometry(QRect(10, 10, 61, 16));
        labelDateTime = new QLabel(AddScene);
        labelDateTime->setObjectName(QStringLiteral("labelDateTime"));
        labelDateTime->setGeometry(QRect(270, 10, 81, 16));
        dateEdit = new QDateEdit(AddScene);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(270, 30, 101, 31));
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(2016, 1, 1));
        timeEdit = new QTimeEdit(AddScene);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(380, 30, 101, 31));
        timeEdit->setCurrentSection(QDateTimeEdit::HourSection);
        timeEdit->setCalendarPopup(false);
        groupBoxPrice = new QGroupBox(AddScene);
        groupBoxPrice->setObjectName(QStringLiteral("groupBoxPrice"));
        groupBoxPrice->setGeometry(QRect(10, 70, 361, 91));
        groupBoxPrice->setStyleSheet(QStringLiteral(""));
        ParterPrice = new QDoubleSpinBox(groupBoxPrice);
        ParterPrice->setObjectName(QStringLiteral("ParterPrice"));
        ParterPrice->setGeometry(QRect(10, 50, 101, 31));
        ParterPrice->setFont(font);
        BenuarPrice = new QDoubleSpinBox(groupBoxPrice);
        BenuarPrice->setObjectName(QStringLiteral("BenuarPrice"));
        BenuarPrice->setGeometry(QRect(130, 50, 101, 31));
        BenuarPrice->setFont(font);
        BeletazPrice = new QDoubleSpinBox(groupBoxPrice);
        BeletazPrice->setObjectName(QStringLiteral("BeletazPrice"));
        BeletazPrice->setGeometry(QRect(250, 50, 101, 31));
        BeletazPrice->setFont(font);
        label = new QLabel(groupBoxPrice);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 101, 16));
        label_2 = new QLabel(groupBoxPrice);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 30, 101, 16));
        label_3 = new QLabel(groupBoxPrice);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 30, 101, 16));

        retranslateUi(AddScene);

        QMetaObject::connectSlotsByName(AddScene);
    } // setupUi

    void retranslateUi(QDialog *AddScene)
    {
        AddScene->setWindowTitle(QApplication::translate("AddScene", "Dialog", 0));
        ButtonAdd->setText(QApplication::translate("AddScene", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        labeName->setText(QApplication::translate("AddScene", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        labelDateTime->setText(QApplication::translate("AddScene", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", 0));
        dateEdit->setDisplayFormat(QApplication::translate("AddScene", "dd.MM.yy", 0));
        timeEdit->setDisplayFormat(QApplication::translate("AddScene", "HH:mm", 0));
        groupBoxPrice->setTitle(QApplication::translate("AddScene", "\320\246\320\265\320\275\320\260, \320\263\321\200\320\275", 0));
        label->setText(QApplication::translate("AddScene", "\320\237\320\260\321\200\321\202\320\265\321\200", 0));
        label_2->setText(QApplication::translate("AddScene", "\320\221\320\265\320\275\321\203\320\260\321\200", 0));
        label_3->setText(QApplication::translate("AddScene", "\320\221\320\265\320\273\321\214\321\215\321\202\320\260\320\266", 0));
    } // retranslateUi

};

namespace Ui {
    class AddScene: public Ui_AddScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSCENE_H
