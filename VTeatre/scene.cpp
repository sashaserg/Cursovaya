#include "scene.h"

Scene::Scene(int temp)
{
    name = date = time = "";
    cost_parter = cost_benuar = cost_beletaj = 0;
    CountOfTypesPlaces = temp;
    nameofplace[0] = "Партер";
    nameofplace[1] = "Бенуар";
    nameofplace[2] = "Бельэтаж";
}

Scene::Scene()
{
    name = date = time = "";
    cost_parter = cost_benuar = cost_beletaj = 0;
}

void Scene::set_name(QString arg){
    name = arg;
}

void Scene::set_time(QString arg){
    time = arg;
}

void Scene::set_cost(double parter, double benuar, double beletaj){
    cost_parter = parter;
    cost_benuar = benuar;
    cost_beletaj = beletaj;
}

void Scene::set_date(QString arg){
    date = arg;
}

void Scene::SetArrayCountPlaces(){
    QSqlQuery qry("select * from Options");

    for(int i = 0; i < 3; i++){
        qry.next();
        ArrayCountPlaces[i][0] = qry.value(1).toInt();
        ArrayCountPlaces[i][1] = qry.value(2).toInt();
    }
}

void Scene::SetDataToTables(){

    TablesPlaces = new int ** [CountOfTypesPlaces];
    for(int i = 0; i < CountOfTypesPlaces; i++){
        TablesPlaces[i] = new int * [ArrayCountPlaces[i][0]];
        for(int j = 0; j < ArrayCountPlaces[i][0]; j++)
            TablesPlaces[i][j] = new int [ArrayCountPlaces[i][1]];
    }
//
    QString nameofplace[3];
    nameofplace[0] = "Партер";
    nameofplace[1] = "Бенуар";
    nameofplace[2] = "Бельэтаж";
    for(int k = 0; k < CountOfTypesPlaces; k++){
        QSqlQuery qry("select * from Employed_place where type_place='" + nameofplace[k] + "' and time_seansa='" + time +"' and date_seansa='" + date + "' and name_seansa='" + name +"'" );
        for(int i = 0; i < ArrayCountPlaces[k][0]; i++){
            for(int j = 0; j < ArrayCountPlaces[k][1]; j++){
                TablesPlaces[k][i][j] = 0;
            }
        }
        while(qry.next()){
            if(qry.value(7).toString() == "Куплено"){
                TablesPlaces[k][qry.value(5).toInt()][qry.value(6).toInt()] = 1;
            }

            if(qry.value(7).toString() == "Забронировано"){
                TablesPlaces[k][qry.value(5).toInt()][qry.value(6).toInt()] = 2;
            }
        }
    }
}

void Scene::DeleteTables(){
    for(int k = 0; k < CountOfTypesPlaces; k++){
        for(int i = 0; i < ArrayCountPlaces[k][0]; i++){
            delete []TablesPlaces[k][i];
        }
        delete [] TablesPlaces[k];
    }
    delete [] TablesPlaces;
}

void Scene::InsertTablesToDataBase(std::vector<short> SelectedPlaces, int Index, int operation){
    for(int i = 0; i < SelectedPlaces.size(); i++){
        qDebug()<<SelectedPlaces[i];
    }
    for(int i = 0; i < SelectedPlaces.size(); i++){
        if(operation == 1){//Купить
            int row = SelectedPlaces[i] / ArrayCountPlaces[Index][1];
            int column = SelectedPlaces[i] % ArrayCountPlaces[Index][1] - 1;
            QSqlQuery qry("insert into Employed_place (place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values (" + QString::number(SelectedPlaces[i]) +", '" + nameofplace[Index] + "', '" + date + "', '" + time + "', '" + name + "', " + QString::number(row) + ", " + QString::number(column) + ", 'Куплено')");
        }
        else if(operation == 2){//Забронировать
            int row = SelectedPlaces[i] / ArrayCountPlaces[Index][1];
            int column = SelectedPlaces[i] % ArrayCountPlaces[Index][1] - 1;
            QSqlQuery qry("insert into Employed_place (place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values (" + QString::number(SelectedPlaces[i]) +", '" + nameofplace[Index] + "', '" + date + "', '" + time + "', '" + name + "', " + QString::number(row) + ", " + QString::number(column) + ", 'Забронировано')");
        }
        else{//Вернуть
            int row = SelectedPlaces[i] / ArrayCountPlaces[Index][1];
            int column = SelectedPlaces[i] % ArrayCountPlaces[Index][1] - 1;
            QSqlQuery qry("delete from Employed_place where place=" + QString::number(SelectedPlaces[i]) + "and type_place = '" + nameofplace[Index] +"' and date_seansa = '" + date + "' and time_seansa='" + time + "' and name_seansa='" + name + "' and row=" + QString::number(row) + " and column=" + QString::number(column));
        }
    }
}
