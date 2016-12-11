#include "addscene.h"
#include "ui_addscene.h"

AddScene::AddScene(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScene)
{
    ui->setupUi(this);
    mydb= QSqlDatabase::addDatabase("QSQLITE");                     // Подключение базы данных
    mydb.setDatabaseName("D:/Cursovaya/Cursovaya/VTeatre.sqlite");


    if(!mydb.open())
        qDebug()<<mydb.lastError().text();
    else
        qDebug()<<"Connected Compled";
}

AddScene::AddScene(bool Edit,Scene *temp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScene)
{
    ui->setupUi(this);
    Editing = Edit;
    PriviosName= temp->name;
    PriviosDate = temp->date;
    PriviosTime = temp->time;
    ui->NameLineEdit->setText(temp->name);
    ui->timeEdit->setTime(QTime::fromString(temp->time));
    ui->dateEdit->setDate(QDate::fromString(temp->date, "dd.MM.yyyy"));
    ui->ParterPrice->setValue(temp->cost_parter);
    ui->BenuarPrice->setValue(temp->cost_benuar);
    ui->BeletazPrice->setValue(temp->cost_beletaj);
    ui->ButtonAdd->setText("Редактировать");
}
AddScene::~AddScene()
{
    delete ui;
}

void AddScene::on_ButtonAdd_clicked()                               // Нажатие на кнопку "Добавить"
{
    Scene temp;
    /*temp.set_cost();
    temp.set_date(ui->dateEdit->text());
    temp.set_time(ui->timeEdit->text());
    temp.set_name(ui->NameLineEdit->text());*/

    Scenes.append(temp);
    int IndexLastScene = Scenes.count() - 1;
    qDebug()<< "Added";

    if(Editing)
    {
        QString name = ui->NameLineEdit->text(),
                time = ui->timeEdit->text(),
                date = ui->dateEdit->text();
        double cost_parter = ui->ParterPrice->value(),
               cost_benuar = ui->BenuarPrice->value(),
               cost_beletaj = ui->BeletazPrice->value();
        QSqlQuery qry_update("update Postanovka set name='" +name+ "', time_seansa='" + time + "', date_seansa='" +date+ "', cost_parter = "+QString::number(cost_parter)+", cost_benuar = "+QString::number(cost_benuar)+ ", cost_beletaj = " +QString::number(cost_beletaj)+ " where name='" +PriviosName+ "' and time_seansa='" +PriviosTime+ "' and date_seansa='" +PriviosDate+ "'");
        Editing = false;
     }
    else if(IndexLastScene >= 0){
        /*
        QSqlQuery qry_insert("insert into Postanovka(name, time_seansa, date_seansa, cost_parter, cost_benuar, cost_beletaj) values('"+Scenes.at(IndexLastScene).name+
                             "', '"+Scenes.at(IndexLastScene).time+
                             "', '"+Scenes.at(IndexLastScene).date+
                             "', "+QString::number(Scenes.at(IndexLastScene).cost_parter)+
                             ", "+QString::number(Scenes.at(IndexLastScene).cost_benuar)+
                             ", "+QString::number(Scenes.at(IndexLastScene).cost_beletaj+")");*/
        QSqlQuery qry_insert("insert into Postanovka(name, time_seansa, date_seansa, cost_parter, cost_benuar, cost_beletaj) values('"+ui->NameLineEdit->text()+
                             "', '"+ui->timeEdit->text()+
                             "', '"+ui->dateEdit->text()+
                             "', "+QString::number(ui->ParterPrice->value())+
                             ", "+QString::number(ui->BenuarPrice->value())+
                             ", "+QString::number(ui->BeletazPrice->value())+")");
    }
}
