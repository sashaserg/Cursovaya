/********************************************************************************
** Form generated from reading UI file 'optionsforhall.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSFORHALL_H
#define UI_OPTIONSFORHALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionsForHall
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QSpinBox *spinBox_Row;
    QSpinBox *spinBox_Column;
    QLabel *label;
    QLabel *label_2;
    QComboBox *ComboBoxType;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QTableWidget *tableWidget;

    void setupUi(QDialog *OptionsForHall)
    {
        if (OptionsForHall->objectName().isEmpty())
            OptionsForHall->setObjectName(QStringLiteral("OptionsForHall"));
        OptionsForHall->resize(633, 529);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/tools.ico"), QSize(), QIcon::Normal, QIcon::Off);
        OptionsForHall->setWindowIcon(icon);
        gridLayout = new QGridLayout(OptionsForHall);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(OptionsForHall);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(341, 101));
        spinBox_Row = new QSpinBox(groupBox);
        spinBox_Row->setObjectName(QStringLiteral("spinBox_Row"));
        spinBox_Row->setGeometry(QRect(270, 20, 61, 31));
        spinBox_Row->setMinimumSize(QSize(61, 31));
        spinBox_Row->setMinimum(1);
        spinBox_Column = new QSpinBox(groupBox);
        spinBox_Column->setObjectName(QStringLiteral("spinBox_Column"));
        spinBox_Column->setGeometry(QRect(270, 60, 61, 31));
        spinBox_Column->setMinimumSize(QSize(61, 31));
        spinBox_Column->setMinimum(1);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 20, 101, 31));
        label->setMinimumSize(QSize(101, 31));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 60, 101, 31));
        label_2->setMinimumSize(QSize(101, 31));
        label_2->setAlignment(Qt::AlignCenter);
        ComboBoxType = new QComboBox(groupBox);
        ComboBoxType->setObjectName(QStringLiteral("ComboBoxType"));
        ComboBoxType->setGeometry(QRect(10, 20, 131, 41));
        ComboBoxType->setMinimumSize(QSize(131, 41));
        ComboBoxType->setStyleSheet(QLatin1String("background-color: #d3bb9c;\n"
"border-style: outset;\n"
"	"));

        horizontalLayout->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButtonOK = new QPushButton(OptionsForHall);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setMinimumSize(QSize(81, 31));

        verticalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(OptionsForHall);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMinimumSize(QSize(81, 31));

        verticalLayout->addWidget(pushButtonCancel);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(OptionsForHall);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMinimumSize(QSize(611, 401));
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setShowGrid(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(61);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(27);
        tableWidget->verticalHeader()->setMinimumSectionSize(21);

        verticalLayout_2->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(OptionsForHall);

        QMetaObject::connectSlotsByName(OptionsForHall);
    } // setupUi

    void retranslateUi(QDialog *OptionsForHall)
    {
        OptionsForHall->setWindowTitle(QApplication::translate("OptionsForHall", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\267\320\260\320\273\320\260", 0));
        groupBox->setTitle(QApplication::translate("OptionsForHall", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\267\320\260\320\273\320\260", 0));
        label->setText(QApplication::translate("OptionsForHall", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\321\217\320\264\320\276\320\262:", 0));
        label_2->setText(QApplication::translate("OptionsForHall", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\274\320\265\321\201\321\202\n"
" \320\262 \321\200\321\217\320\264\321\203", 0));
        ComboBoxType->clear();
        ComboBoxType->insertItems(0, QStringList()
         << QApplication::translate("OptionsForHall", "\320\237\320\260\321\200\321\202\320\265\321\200", 0)
         << QApplication::translate("OptionsForHall", "\320\221\320\265\320\275\321\203\320\260\321\200", 0)
         << QApplication::translate("OptionsForHall", "\320\221\320\265\320\273\321\214\321\215\321\202\320\260\320\266", 0)
        );
        pushButtonOK->setText(QApplication::translate("OptionsForHall", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", 0));
        pushButtonCancel->setText(QApplication::translate("OptionsForHall", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class OptionsForHall: public Ui_OptionsForHall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSFORHALL_H
