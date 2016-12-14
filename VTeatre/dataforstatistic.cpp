#include "dataforstatistic.h"

DataforStatistic::DataforStatistic(int CountDays)
{
    DataOfPlaces = new QString *[CountDays];
    for(int i = 0; i < CountDays; i++){
        DataOfPlaces[i] = new QString [3];
    }
}

void DataforStatistic::InsertData(){

}

