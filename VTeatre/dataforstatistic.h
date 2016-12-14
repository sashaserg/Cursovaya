#ifndef DATAFORSTATISTIC_H
#define DATAFORSTATISTIC_H
#include <QDate>
#include <QtSql>


class DataforStatistic
{
    int count_place;
    QString date;
    double count_income;
    QString type_place;
public:
    DataforStatistic();
    void set_count_place()
    {
        QSqlQuery qry(select);
    }
    void set_date();
    void set_count_place();
    void set_type_place();
};

#endif // DATAFORSTATISTIC_H
