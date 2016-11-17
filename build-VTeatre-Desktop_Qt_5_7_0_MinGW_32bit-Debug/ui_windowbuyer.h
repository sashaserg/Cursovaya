/********************************************************************************
** Form generated from reading UI file 'windowbuyer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWBUYER_H
#define UI_WINDOWBUYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowBuyer
{
public:
    QTableWidget *tableWidget;

    void setupUi(QDialog *WindowBuyer)
    {
        if (WindowBuyer->objectName().isEmpty())
            WindowBuyer->setObjectName(QStringLiteral("WindowBuyer"));
        WindowBuyer->resize(537, 406);
        tableWidget = new QTableWidget(WindowBuyer);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 511, 381));

        retranslateUi(WindowBuyer);

        QMetaObject::connectSlotsByName(WindowBuyer);
    } // setupUi

    void retranslateUi(QDialog *WindowBuyer)
    {
        WindowBuyer->setWindowTitle(QApplication::translate("WindowBuyer", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class WindowBuyer: public Ui_WindowBuyer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWBUYER_H
