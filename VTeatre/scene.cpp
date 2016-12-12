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

void Scene::set_cost(){
    QSqlQuery qry("select cost_parter, cost_benuar, cost_beletaj from Postanovka where name = '" + name + "' and time_seansa='" + time + "' and date_seansa='" + date + "'");
    qry.next();
    cost_parter = qry.value(0).toDouble();
    cost_benuar = qry.value(1).toDouble();
    cost_beletaj = qry.value(2).toDouble();
}

void Scene::set_date(QString arg){
    date = arg;
}

void Scene::SetArrayCountPlaces(){

    OptionsForHall options;
    for(int i = 0; i < 3; i++){
        ArrayCountPlaces[i][0] = options.dataJsonFile[i][0];
        ArrayCountPlaces[i][1] = options.dataJsonFile[i][1];
    }
}

void Scene::SetDataToTables(){

    TablesPlaces = new int ** [CountOfTypesPlaces];
    for(int i = 0; i < CountOfTypesPlaces; i++){
        TablesPlaces[i] = new int * [ArrayCountPlaces[i][0]];
        for(int j = 0; j < ArrayCountPlaces[i][0]; j++)
            TablesPlaces[i][j] = new int [ArrayCountPlaces[i][1]];
    }
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
            if(qry.value(5).toInt() < ArrayCountPlaces[k][0] && qry.value(6).toInt() < ArrayCountPlaces[k][1]){
                if(qry.value(7).toString() == "Куплено"){
                    TablesPlaces[k][qry.value(5).toInt()][qry.value(6).toInt()] = 1;
                }
                if(qry.value(7).toString() == "Забронировано"){
                    TablesPlaces[k][qry.value(5).toInt()][qry.value(6).toInt()] = 2;
                }
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

void Scene::InsertTablesToDataBase(std::vector<short> SelectedPlacesRow, std::vector<short> SelectedPlacesCol, int Index, int operation){
    for(int i = 0; i < SelectedPlacesRow.size(); i++){

        int row = SelectedPlacesRow[i];
        int column = SelectedPlacesCol[i];

        if(operation == 0){//Вернуть
            QSqlQuery qry("delete from Employed_place where type_place = '" + nameofplace[Index] +"' and date_seansa = '" + date + "' and time_seansa='" + time + "' and name_seansa='" + name + "' and row=" + QString::number(row) + " and column=" + QString::number(column));
        }
        if(operation == 1 ){//Купить
            QSqlQuery qry("insert into Employed_place (type_place, date_seansa, time_seansa, name_seansa, row, column, state) values ('" + nameofplace[Index] + "', '" + date + "', '" + time + "', '" + name + "', " + QString::number(row) + ", " + QString::number(column) + ", 'Куплено')");
        }
        if(operation == 2){//Забронировать
            QSqlQuery qry("insert into Employed_place (type_place, date_seansa, time_seansa, name_seansa, row, column, state) values ('" + nameofplace[Index] + "', '" + date + "', '" + time + "', '" + name + "', " + QString::number(row) + ", " + QString::number(column) + ", 'Забронировано')");
        }
    }
}
