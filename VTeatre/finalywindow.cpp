#include "finalywindow.h"
#include "ui_finalywindow.h"

FinalyWindow::FinalyWindow(bool Buy, QWidget *parent) :         // конструктор с 2 параметрами
    QDialog(parent),
    ui(new Ui::FinalyWindow)
{
    ui->setupUi(this);
    Buying = Buy;
    if(Buy)                                                     // если покупаем - прячем лэйбл с кодом
        ui->labelCode->setVisible(false);
    else                                                        // если бронируем - заполняем код из 8 символов (не проверял)
    {
        QString code;
        for(int i = 0; i < 8; ++i)
            code[i] = char(rand() % 90 + 48);
        ui->labelCode->setText(code);


    }
}

FinalyWindow::~FinalyWindow()
{
    delete ui;
}
