#include "dataforstatistic.h"

DataforStatistic::DataforStatistic(int Days)
{
    CountDays = Days;

    DataOfPlaces = new QString **[Days];
    for(int i = 0; i < CountDays; i++){
        DataOfPlaces[i] = new QString * [3];
        for(int j = 0; j < 3; j++)
            DataOfPlaces[i][j] = new QString [2];
    }
}

void DataforStatistic::InsertData(){
    QSqlQuery qry;
    if(!qry.exec("select * from DataforStatistic order by date desc"))
    {
        qDebug()<<qry.lastError().databaseText();
    }
    //
    for(int i = 0; i < CountDays; i++){
        for(int j = 0 ; j < 3 && qry.next(); j++){

            DataOfPlaces[i][j][0] = qry.value(1).toString();//Здесь количество мест в этот день
            DataOfPlaces[i][j][1] = qry.value("date").toString();//Здесь дата
            qDebug()<<DataOfPlaces[i][j][0]<<" "<<DataOfPlaces[i][j][1];
        }
    }
}

