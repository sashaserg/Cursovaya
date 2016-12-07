#ifndef SCENE_H
#define SCENE_H
#include <QString>
#include<optionsforhall.h>


class Scene
{

   QString name,
           date,
           time;
   double
           cost_parter,
           cost_benuar,
           cost_beletaj;

public:
    Scene();
    void set_name(QString arg);
    void set_date(QString arg);
    void set_time(QString arg);
    void set_cost(double parter, double benuar, double beletaj);

};

#endif // SCENE_H
