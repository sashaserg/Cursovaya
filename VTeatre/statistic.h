#ifndef STATISTIC_H
#define STATISTIC_H

#include <QDialog>
#include "dataforstatistic.h"
namespace Ui {
class Statistic;
}

class Statistic : public QDialog
{
    Q_OBJECT
    
public:
    explicit Statistic(QWidget *parent = 0);
    ~Statistic();
    
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Statistic *ui;
    void CreateGraphPlaces(DataforStatistic *data, int CountDays);
    void CreateGraphMon(DataforStatistic *data, int CountDays);
};

#endif // STATISTIC_H
