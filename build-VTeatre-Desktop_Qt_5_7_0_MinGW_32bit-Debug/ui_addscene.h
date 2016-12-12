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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddScene
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labeName;
    QLineEdit *NameLineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelDateTime;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBoxPrice;
    QDoubleSpinBox *ParterPrice;
    QDoubleSpinBox *BenuarPrice;
    QDoubleSpinBox *BeletazPrice;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *ButtonAdd;

    void setupUi(QDialog *AddScene)
    {
        if (AddScene->objectName().isEmpty())
            AddScene->setObjectName(QStringLiteral("AddScene"));
        AddScene->resize(497, 180);
        gridLayout = new QGridLayout(AddScene);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labeName = new QLabel(AddScene);
        labeName->setObjectName(QStringLiteral("labeName"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labeName->sizePolicy().hasHeightForWidth());
        labeName->setSizePolicy(sizePolicy);
        labeName->setMinimumSize(QSize(61, 16));

        verticalLayout->addWidget(labeName);

        NameLineEdit = new QLineEdit(AddScene);
        NameLineEdit->setObjectName(QStringLiteral("NameLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(NameLineEdit->sizePolicy().hasHeightForWidth());
        NameLineEdit->setSizePolicy(sizePolicy1);
        NameLineEdit->setMinimumSize(QSize(251, 31));

        verticalLayout->addWidget(NameLineEdit);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        labelDateTime = new QLabel(AddScene);
        labelDateTime->setObjectName(QStringLiteral("labelDateTime"));
        sizePolicy.setHeightForWidth(labelDateTime->sizePolicy().hasHeightForWidth());
        labelDateTime->setSizePolicy(sizePolicy);
        labelDateTime->setMinimumSize(QSize(81, 16));

        verticalLayout_2->addWidget(labelDateTime);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dateEdit = new QDateEdit(AddScene);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy2);
        dateEdit->setMinimumSize(QSize(101, 31));
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(2016, 1, 1));

        horizontalLayout->addWidget(dateEdit);

        timeEdit = new QTimeEdit(AddScene);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        sizePolicy2.setHeightForWidth(timeEdit->sizePolicy().hasHeightForWidth());
        timeEdit->setSizePolicy(sizePolicy2);
        timeEdit->setMinimumSize(QSize(101, 31));
        timeEdit->setCurrentSection(QDateTimeEdit::HourSection);
        timeEdit->setCalendarPopup(false);

        horizontalLayout->addWidget(timeEdit);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBoxPrice = new QGroupBox(AddScene);
        groupBoxPrice->setObjectName(QStringLiteral("groupBoxPrice"));
        groupBoxPrice->setMinimumSize(QSize(361, 91));
        groupBoxPrice->setStyleSheet(QStringLiteral(""));
        ParterPrice = new QDoubleSpinBox(groupBoxPrice);
        ParterPrice->setObjectName(QStringLiteral("ParterPrice"));
        ParterPrice->setGeometry(QRect(10, 50, 101, 31));
        QFont font;
        font.setPointSize(10);
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

        horizontalLayout_3->addWidget(groupBoxPrice);

        ButtonAdd = new QPushButton(AddScene);
        ButtonAdd->setObjectName(QStringLiteral("ButtonAdd"));
        ButtonAdd->setMinimumSize(QSize(101, 51));
        ButtonAdd->setMaximumSize(QSize(101, 51));
        ButtonAdd->setFont(font);

        horizontalLayout_3->addWidget(ButtonAdd);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(AddScene);

        QMetaObject::connectSlotsByName(AddScene);
    } // setupUi

    void retranslateUi(QDialog *AddScene)
    {
        AddScene->setWindowTitle(QApplication::translate("AddScene", "\320\237\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260", 0));
        labeName->setText(QApplication::translate("AddScene", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0));
        labelDateTime->setText(QApplication::translate("AddScene", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217", 0));
        dateEdit->setDisplayFormat(QApplication::translate("AddScene", "dd.MM.yyyy", 0));
        timeEdit->setDisplayFormat(QApplication::translate("AddScene", "HH:mm", 0));
        groupBoxPrice->setTitle(QApplication::translate("AddScene", "\320\246\320\265\320\275\320\260, \320\263\321\200\320\275", 0));
        label->setText(QApplication::translate("AddScene", "\320\237\320\260\321\200\321\202\320\265\321\200", 0));
        label_2->setText(QApplication::translate("AddScene", "\320\221\320\265\320\275\321\203\320\260\321\200", 0));
        label_3->setText(QApplication::translate("AddScene", "\320\221\320\265\320\273\321\214\321\215\321\202\320\260\320\266", 0));
        ButtonAdd->setText(QApplication::translate("AddScene", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class AddScene: public Ui_AddScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSCENE_H
