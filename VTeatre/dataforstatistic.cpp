#include "dataforstatistic.h"

DataforStatistic::DataforStatistic(int Days)
{
    CountDays = Days;                               //Устанавливаем количество дней

    qDebug()<<"qweqweqweqweqweqweqweqwe";
    DataOfPlaces = new QString **[Days];            //Выделяем память для хранения даты и
    for(int i = 0; i < CountDays; i++){             //количества купленных мест за определенный
        DataOfPlaces[i] = new QString * [3];        //промежуток времени
        for(int j = 0; j < 3; j++)
            DataOfPlaces[i][j] = new QString [3];
    }


    qDebug()<<"qweqweqweqweqweqweqweqwe";
}

void DataforStatistic::InsertData(){
    QSqlQuery qry("select * from DataforStatistic order by date desc"); //Подключаю БД

    qDebug()<<"qweqweqweqweqweqweqweqwe";
    for(int i = 0; i < CountDays; i++){                                 //Заполняю массив значениями из БД
        for(int j = 0 ; j < 3 && qry.next(); j++){

            DataOfPlaces[i][j][0] = qry.value(1).toString();            //Здесь количество мест в этот день
            DataOfPlaces[i][j][1] = qry.value("date").toString();       //Здесь дата
            DataOfPlaces[i][j][2] = qry.value(2).toString();
        }
    }
    qDebug()<<"qweqweqweqweqweqweqweqwe";
}


