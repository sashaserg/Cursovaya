#ifndef SCENE_H
#define SCENE_H
#include <QString>
#include<optionsforhall.h>
#include <QtSql>

class Scene
{



public:
    Scene();

    void set_name(QString arg);
    void set_date(QString arg);
    void set_time(QString arg);
    void set_cost(double parter, double benuar, double beletaj);
    void SetArrayCountPlaces();
    void SetDataToTables();
    void DeleteTables();
    void InsertTablesToDataBase(); // Обновляем базу данных

    int ArrayCountPlaces[3][2]; // Хранит количество мест для каждого типа зала
    int **TableParter,
        **TableBenuar,
        **TableBelietaj;
    QString name,
            date,
            time;
    double  cost_parter,
            cost_benuar,
            cost_beletaj;
    QSqlDatabase mydb;
};

#endif // SCENE_H
