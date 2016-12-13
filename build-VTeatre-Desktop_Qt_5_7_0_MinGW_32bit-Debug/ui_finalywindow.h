/********************************************************************************
** Form generated from reading UI file 'finalywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALYWINDOW_H
#define UI_FINALYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_FinalyWindow
{
public:
    QPushButton *pushButtonOk;
    QTableWidget *tableWidget;
    QLabel *labelCode;
    QLabel *labelCost;

    void setupUi(QDialog *FinalyWindow)
    {
        if (FinalyWindow->objectName().isEmpty())
            FinalyWindow->setObjectName(QStringLiteral("FinalyWindow"));
        FinalyWindow->resize(531, 300);
        pushButtonOk = new QPushButton(FinalyWindow);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(390, 250, 131, 41));
        tableWidget = new QTableWidget(FinalyWindow);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 511, 181));
        labelCode = new QLabel(FinalyWindow);
        labelCode->setObjectName(QStringLiteral("labelCode"));
        labelCode->setGeometry(QRect(20, 200, 501, 41));
        QFont font;
        font.setPointSize(14);
        labelCode->setFont(font);
        labelCost = new QLabel(FinalyWindow);
        labelCost->setObjectName(QStringLiteral("labelCost"));
        labelCost->setGeometry(QRect(20, 260, 160, 22));
        labelCost->setMinimumSize(QSize(160, 22));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        labelCost->setFont(font1);

        retranslateUi(FinalyWindow);

        QMetaObject::connectSlotsByName(FinalyWindow);
    } // setupUi

    void retranslateUi(QDialog *FinalyWindow)
    {
        FinalyWindow->setWindowTitle(QApplication::translate("FinalyWindow", "Dialog", 0));
        pushButtonOk->setText(QApplication::translate("FinalyWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FinalyWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FinalyWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FinalyWindow", "\320\242\320\270\320\277 \320\274\320\265\321\201\321\202\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FinalyWindow", "\320\224\320\260\321\202\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("FinalyWindow", "\320\222\321\200\320\265\320\274\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("FinalyWindow", "\320\240\321\217\320\264", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("FinalyWindow", "\320\246\320\265\320\275\320\260", 0));
        labelCode->setText(QApplication::translate("FinalyWindow", "\320\232\320\276\320\264 \320\264\320\273\321\217 \320\261\321\200\320\276\320\275\320\270, \321\201\320\272\321\200\321\213\321\202 \320\264\320\273\321\217 \320\277\320\276\320\272\321\203\320\277\320\272\320\270", 0));
        labelCost->setText(QApplication::translate("FinalyWindow", "\320\232 \320\276\320\277\320\273\320\260\321\202\320\265: 0", 0));
    } // retranslateUi

};

namespace Ui {
    class FinalyWindow: public Ui_FinalyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALYWINDOW_H
