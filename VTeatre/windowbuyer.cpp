#include "windowbuyer.h"
#include "ui_windowbuyer.h"

WindowBuyer::WindowBuyer(QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::WindowBuyer)
{
    ui->setupUi(this);
}

WindowBuyer::~WindowBuyer()
{
    delete ui;
}
