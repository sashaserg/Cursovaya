/********************************************************************************
** Form generated from reading UI file 'statistic.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIC_H
#define UI_STATISTIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Statistic
{
public:
    QGroupBox *groupBox;
    QCustomPlot *widget;
    QDateEdit *dateEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Statistic)
    {
        if (Statistic->objectName().isEmpty())
            Statistic->setObjectName(QStringLiteral("Statistic"));
        Statistic->resize(734, 386);
        groupBox = new QGroupBox(Statistic);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(220, 10, 501, 361));
        widget = new QCustomPlot(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 481, 331));
        dateEdit = new QDateEdit(Statistic);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(10, 40, 201, 30));
        dateEdit->setMinimumSize(QSize(1, 1));
        QFont font;
        font.setPointSize(12);
        dateEdit->setFont(font);
        dateEdit->setDateTime(QDateTime(QDate(2016, 1, 1), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);
        label = new QLabel(Statistic);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 161, 20));
        pushButton = new QPushButton(Statistic);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 80, 201, 31));
        pushButton_2 = new QPushButton(Statistic);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 120, 201, 31));
        pushButton_3 = new QPushButton(Statistic);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 160, 201, 31));

        retranslateUi(Statistic);

        QMetaObject::connectSlotsByName(Statistic);
    } // setupUi

    void retranslateUi(QDialog *Statistic)
    {
        Statistic->setWindowTitle(QApplication::translate("Statistic", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("Statistic", "\320\223\321\200\320\260\321\204\320\270\320\272", 0));
        label->setText(QApplication::translate("Statistic", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \320\267\320\260 \320\264\320\260\321\202\320\276\320\271:", 0));
        pushButton->setText(QApplication::translate("Statistic", "\320\227\320\260 \320\275\320\265\320\264\320\265\320\273\321\216", 0));
        pushButton_2->setText(QApplication::translate("Statistic", "\320\227\320\260 \320\274\320\265\321\201\321\217\321\206", 0));
        pushButton_3->setText(QApplication::translate("Statistic", "\320\227\320\260 \320\262\321\201\321\221 \320\262\321\200\320\265\320\274\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class Statistic: public Ui_Statistic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIC_H
