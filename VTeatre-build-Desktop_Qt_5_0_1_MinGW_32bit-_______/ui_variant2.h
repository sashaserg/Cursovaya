/********************************************************************************
** Form generated from reading UI file 'variant2.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VARIANT2_H
#define UI_VARIANT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGraphicsView *graphicsView;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QGraphicsView *graphicsView_2;
    QComboBox *comboBox_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(561, 505);
        graphicsView = new QGraphicsView(Dialog);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 321, 231));
        comboBox = new QComboBox(Dialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(350, 10, 201, 41));
        dateEdit = new QDateEdit(Dialog);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(350, 60, 201, 41));
        QFont font;
        font.setPointSize(12);
        dateEdit->setFont(font);
        dateEdit->setDateTime(QDateTime(QDate(2016, 1, 1), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);
        graphicsView_2 = new QGraphicsView(Dialog);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(10, 260, 321, 231));
        comboBox_2 = new QComboBox(Dialog);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(350, 260, 201, 41));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(464, 462, 91, 31));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\320\242\320\265\320\260\321\202\321\2001", 0)
         << QApplication::translate("Dialog", "\320\242\320\265\320\260\321\202\321\2002", 0)
         << QApplication::translate("Dialog", "\320\242\320\265\320\260\321\202\321\2003", 0)
        );
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "\320\241\320\277\320\265\320\272\321\202\320\260\320\272\320\273\321\2141", 0)
        );
        pushButton->setText(QApplication::translate("Dialog", "\320\222\321\213\320\261\320\276\321\200 \320\274\320\265\321\201\321\202", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIANT2_H
