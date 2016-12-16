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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Statistic
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QCustomPlot *widget;

    void setupUi(QDialog *Statistic)
    {
        if (Statistic->objectName().isEmpty())
            Statistic->setObjectName(QStringLiteral("Statistic"));
        Statistic->resize(734, 386);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/trends.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Statistic->setWindowIcon(icon);
        gridLayout = new QGridLayout(Statistic);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Statistic);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(161, 20));

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(Statistic);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(201, 31));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Statistic);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(201, 31));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Statistic);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(201, 31));

        verticalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 218, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(Statistic);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(501, 361));
        widget = new QCustomPlot(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 481, 331));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(groupBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Statistic);

        QMetaObject::connectSlotsByName(Statistic);
    } // setupUi

    void retranslateUi(QDialog *Statistic)
    {
        Statistic->setWindowTitle(QApplication::translate("Statistic", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", 0));
        label->setText(QApplication::translate("Statistic", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260:", 0));
        pushButton->setText(QApplication::translate("Statistic", "\320\227\320\260 \320\275\320\265\320\264\320\265\320\273\321\216", 0));
        pushButton_2->setText(QApplication::translate("Statistic", "\320\227\320\260 \320\274\320\265\321\201\321\217\321\206", 0));
        pushButton_3->setText(QApplication::translate("Statistic", "\320\227\320\260 \320\262\321\201\321\221 \320\262\321\200\320\265\320\274\321\217", 0));
        groupBox->setTitle(QApplication::translate("Statistic", "\320\223\321\200\320\260\321\204\320\270\320\272", 0));
    } // retranslateUi

};

namespace Ui {
    class Statistic: public Ui_Statistic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIC_H
