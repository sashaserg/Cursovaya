#ifndef DATAFORSTATISTIC_H
#define DATAFORSTATISTIC_H
#include <QDate>
#include <QtSql>
#include <vector>



class DataforStatistic
{
    QString **DataOfPlaces;

public:
    DataforStatistic(int CountDays);
    void InsertData();
};

#endif // DATAFORSTATISTIC_H
