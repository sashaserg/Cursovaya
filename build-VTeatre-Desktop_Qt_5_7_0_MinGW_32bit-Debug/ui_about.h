/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(468, 322);
        gridLayout = new QGridLayout(About);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(About);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 20, 81, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 151, 21));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 100, 320, 68));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setPointSize(11);
        label_3->setFont(font2);

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(190, 230, 97, 40));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font3;
        font3.setPointSize(10);
        label_6->setFont(font3);

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font3);

        verticalLayout_2->addWidget(label_7);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(About);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "\320\236 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\265", 0));
        groupBox->setTitle(QApplication::translate("About", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", 0));
        label->setText(QApplication::translate("About", "VTeatre", 0));
        label_2->setText(QApplication::translate("About", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\321\207\320\270\320\272\320\270:", 0));
        label_3->setText(QApplication::translate("About", "\320\240\321\217\320\267\320\260\320\275\320\276\320\262 \320\224\320\260\320\275\320\270\320\273 - \320\262\320\267\320\260\320\270\320\274\320\276\320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265 \321\201 \320\264\320\260\320\275\320\275\321\213\320\274\320\270", 0));
        label_4->setText(QApplication::translate("About", "\320\241\320\265\321\200\320\263\320\265\320\265\320\262 \320\220\320\273\320\265\320\272\321\201\320\260\320\275\320\264\321\200 - \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\260 \320\270\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201\320\260", 0));
        label_5->setText(QApplication::translate("About", "\320\221\320\270\321\200\321\216\320\272\320\276\320\262 \320\220\320\273\320\265\320\272\321\201\320\260\320\275\320\264\321\200 - \321\200\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\260 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\276\320\262 ", 0));
        label_6->setText(QApplication::translate("About", "\320\232\320\235\320\242 - 415, \320\227\320\235\320\242\320\243", 0));
        label_7->setText(QApplication::translate("About", "        2016", 0));
        pushButton->setText(QApplication::translate("About", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
