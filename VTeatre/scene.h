﻿#ifndef SCENE_H
#define SCENE_H
#include <QString>
#include<optionsforhall.h>
#include <QtSql>
#include <vector>

class Scene
{
    int CountOfTypesPlaces;
    QString name,
            date,
            time;
    std::vector<double>Cost;

public:
    Scene();

    void set_name(QString arg);
    void set_date(QString arg);
    void set_time(QString arg);
    void set_cost();
    void set_cost(int par, int ben, int bel);
    void SetArrayCountPlaces();
    void SetDataToTables();
    void DeleteTables();
    void InsertTablesToDataBase(std::vector<short> SelectedPlacesRow, std::vector<short> SelectedPlacesCol, int Index, int operation, QString Code = ""); // Обновляем базу данных

    QString get_name();
    QString get_date();
    QString get_time();
    std::vector<double>get_Cost();

    int ArrayCountPlaces[3][2]; // Хранит количество мест для каждого типа зала
    int ***TablesPlaces;
    QString nameofplace[3];
};

#endif // SCENE_H
