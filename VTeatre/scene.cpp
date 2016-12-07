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
