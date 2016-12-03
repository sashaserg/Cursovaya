#include "statistic.h"
#include "ui_statistic.h"

Statistic::Statistic(QDateTime datenow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);

    ui->dateEdit->setDateTime(datenow);                                // Устанавливаю дату в dateEdit в текущую дату
}

Statistic::~Statistic()
{
    delete ui;
}
