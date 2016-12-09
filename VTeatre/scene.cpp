#include "scene.h"

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
    TableParter = new int * [ArrayCountPlaces[0][0]];
    TableBenuar = new int * [ArrayCountPlaces[1][0]];
    TableBelietaj = new int * [ArrayCountPlaces[2][0]];

    for(int i = 0; i < ArrayCountPlaces[0][0]; i++){
        TableParter[i] = new int [ArrayCountPlaces[0][1]];
    }
    for(int i = 0; i < ArrayCountPlaces[1][0]; i++){
        TableBenuar[i] = new int [ArrayCountPlaces[1][1]];
    }
    for(int i = 0; i < ArrayCountPlaces[2][0]; i++){
        TableBelietaj[i] = new int [ArrayCountPlaces[2][1]];
    }

    QSqlQuery qryPar("select * from Employed_place where type_place='Партер' and time_seansa='" + time +"' and date_seansa='" + date + "' and name_seansa='" + name +"'" );
    for(int i = 0; i < ArrayCountPlaces[0][0]; i++){
        for(int j = 0; j < ArrayCountPlaces[0][1]; j++){
            TableParter[i][j] = 0;
        }
    }
    while(qryPar.next()){
        if(qryPar.value(7).toString() == "Куплено"){
            TableParter[qryPar.value(5).toInt()][qryPar.value(6).toInt()] = 1;
        }

        if(qryPar.value(7).toString() == "Забронировано"){
            TableParter[qryPar.value(5).toInt()][qryPar.value(6).toInt()] = 2;
        }
    }

    QSqlQuery qryBen("select * from Employed_place where type_place='Бенуар' and time_seansa='" + time +"' and date_seansa='" + date + "' and name_seansa='" + name +"'" );
    for(int i = 0; i < ArrayCountPlaces[1][0]; i++){
        for(int j = 0; j < ArrayCountPlaces[1][1]; j++){
            TableBenuar[i][j] = 0;
        }
    }
    while(qryBen.next()){
        if(qryBen.value(7).toString() == "Куплено"){
            TableBenuar[qryBen.value(5).toInt()][qryBen.value(6).toInt()] = 1;
        }

        if(qryBen.value(7).toString() == "Забронировано"){
            TableBenuar[qryBen.value(5).toInt()][qryBen.value(6).toInt()] = 2;
        }
    }

    QSqlQuery qryBel("select * from Employed_place where type_place='Бельэтаж' and time_seansa='" + time +"' and date_seansa='" + date + "' and name_seansa='" + name +"'" );
    for(int i = 0; i < ArrayCountPlaces[2][0]; i++){
        for(int j = 0; j < ArrayCountPlaces[2][1]; j++){
            TableBelietaj[i][j] = 0;
        }
    }
    while(qryBel.next()){
        if(qryBel.value(7).toString() == "Куплено"){
            TableBelietaj[qryBel.value(5).toInt()][qryBel.value(6).toInt()] = 1;
        }

        if(qryBel.value(7).toString() == "Забронировано"){
            TableBelietaj[qryBel.value(5).toInt()][qryBel.value(6).toInt()] = 2;
        }
    }
}

void Scene::DeleteTables(){
    for(int i = 0; i < ArrayCountPlaces[0][0]; i++){
        delete []TableParter[i];
    }
    delete []TableParter;

    for(int i = 0; i < ArrayCountPlaces[1][0]; i++){
        delete []TableBenuar[i];
    }
    delete []TableBenuar;

    for(int i = 0; i < ArrayCountPlaces[2][0]; i++){
        delete []TableBelietaj[i];
    }
    delete []TableBelietaj;
}

void Scene::InsertTablesToDataBase(){
    QSqlQuery qry("delete from Employed_place where name_seansa='" + name + "' and time_seansa='" + time + "' and date_seansa='" + date +"'");
    for(int i = 0; i < ArrayCountPlaces[0][0]; i++){
        for(int j = 0; j < ArrayCountPlaces[0][1]; j++){
            if(TableParter[i][j] == 1){
                QSqlQuery qry_insert("insert into Employed_place(place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values (" +QString::number(ArrayCountPlaces[0][1]*i+j+1) +", 'Партер', '" + date + "', '" + time + "', '" + name + "', " + QString::number(i) + ", " + QString::number(j) + ", 'Куплено')");
            }
            if(TableParter[i][j] == 2){
                QSqlQuery qry_insert("insert into Employed_place(place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values (" +QString::number(ArrayCountPlaces[0][1]*i+j+1) + ", 'Партер', '" + date + "', '" + time + "', '" + name + "', " + QString::number(i) + ", " + QString::number(j) + ", 'Забронировано')");
            }
        }
    }
    for(int i = 0; i < ArrayCountPlaces[1][0]; i++){
        for(int j = 0; j < ArrayCountPlaces[1][1]; j++){
            if(TableBenuar[i][j] == 1){
                QSqlQuery qry_insert("insert into Employed_place(place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values (" +QString::number(ArrayCountPlaces[1][1]*i+j+1) +", 'Бенуар', '" + date + "', '" + time + "', '" + name + "', " + QString::number(i) + ", " + QString::number(j) + ", 'Куплено')");
            }
            if(TableBenuar[i][j] == 2){
                QSqlQuery qry_insert("insert into Employed_place(place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values (" +QString::number(ArrayCountPlaces[1][1]*i+j+1) + ", 'Бенуар', '" + date + "', '" + time + "', '" + name + "', " + QString::number(i) + ", " + QString::number(j) + ", 'Забронировано')");
            }
        }
    }
    for(int i = 0; i < ArrayCountPlaces[2][0]; i++){
        for(int j = 0; j < ArrayCountPlaces[2][1]; j++){
            if(TableBelietaj[i][j] == 1){
                QSqlQuery qry_insert("insert into Employed_place(place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values (" +QString::number(ArrayCountPlaces[2][1]*i+j+1) +", 'Бельэтаж', '" + date + "', '" + time + "', '" + name + "', " + QString::number(i) + ", " + QString::number(j) + ", 'Куплено')");
            }
            if(TableBelietaj[i][j] == 2){
                QSqlQuery qry_insert("insert into Employed_place(place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values (" +QString::number(ArrayCountPlaces[2][1]*i+j+1) + ", 'Бельэтаж', '" + date + "', '" + time + "', '" + name + "', " + QString::number(i) + ", " + QString::number(j) + ", 'Забронировано')");
            }
        }
    }
}
