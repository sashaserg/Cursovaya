#include "addscene.h"
#include "ui_addscene.h"

AddScene::AddScene(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScene)
{
    ui->setupUi(this);
    mydb= QSqlDatabase::addDatabase("QSQLITE");                     // Подключение базы данных
    mydb.setDatabaseName("C:/Cursovaya/VTeatre.sqlite");
    Editing = false;

    if(!mydb.open())
        qDebug()<<mydb.lastError().text();
    else
        qDebug()<<"Connected Compled";
}

AddScene::AddScene(bool Edit,Scene *temp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScene)
{
    qDebug()<<"Zashlo V constr0";
    ui->setupUi(this);
    Editing = Edit;
    PriviosName= temp->name;
    PriviosDate = temp->date;
    PriviosTime = temp->time;
    ui->NameLineEdit->setText(temp->name);
    ui->timeEdit->setTime(QTime::fromString(temp->time));
    ui->dateEdit->setDate(QDate::fromString(temp->date, "dd.MM.yyyy"));
    ui->ParterPrice->setValue(temp->Cost[0]);
    ui->BenuarPrice->setValue(temp->Cost[1]);
    ui->BeletazPrice->setValue(temp->Cost[2]);
    ui->ButtonAdd->setText("Редактировать");
}
AddScene::~AddScene()
{
    delete ui;
}

void AddScene::on_ButtonAdd_clicked()                               // Нажатие на кнопку "Добавить"
{
    if(Editing)
    {
        QString name = ui->NameLineEdit->text(),
                time = ui->timeEdit->text(),
                date = ui->dateEdit->text();
        double cost_parter = ui->ParterPrice->value(),
               cost_benuar = ui->BenuarPrice->value(),
               cost_beletaj = ui->BeletazPrice->value();
        QSqlQuery qry_update1("update Postanovka set name='" +name+ "', time_seansa='" + time + "', date_seansa='" +date+ "', cost_parter = "+QString::number(cost_parter)+", cost_benuar = "+QString::number(cost_benuar)+ ", cost_beletaj = " +QString::number(cost_beletaj)+ " where name='" +PriviosName+ "' and time_seansa='" +PriviosTime+ "' and date_seansa='" +PriviosDate+ "'");
        QSqlQuery qry_update2("update Employed_place set name_seansa='" +name+ "', time_seansa='" + time + "', date_seansa='" +date+ "' where name_seansa='" +PriviosName+ "' and time_seansa='" +PriviosTime+ "' and date_seansa='" +PriviosDate+ "'");

        Editing = false;
    }
    else {
        QSqlQuery qry_insert("insert into Postanovka(name, time_seansa, date_seansa, cost_parter, cost_benuar, cost_beletaj) values('" + ui->NameLineEdit->text()+
                             "', '" + ui->timeEdit->text()+
                             "', '"+ui->dateEdit->text()+
                             "', "+QString::number(ui->ParterPrice->value())+
                             ", "+QString::number(ui->BenuarPrice->value())+
                             ", "+QString::number(ui->BeletazPrice->value())+")");
        QSqlQuery qry_insert1;
        QSqlQuery qry_select;
        if(!qry_select.exec("select distinct date from DataforStatistic where date='" +ui->dateEdit->text()+ "'"))
        {
                qDebug()<<qry_select.lastError().databaseText();
        }
        qry_select.first();
        if(qry_select.value("date")!=ui->dateEdit->text())
        {
            if(!qry_insert1.exec("insert into DataforStatistic(type_place, date, count_income, count_place) values ('Партер', '" +ui->dateEdit->text()+ "', 0, 0)"))
                qDebug()<<qry_insert1.lastError().databaseText();
            if(!qry_insert1.exec("insert into DataforStatistic(type_place, date, count_income, count_place) values ('Бенуар', '" +ui->dateEdit->text()+ "', 0, 0)"))
                qDebug()<<qry_insert1.lastError().databaseText();
            if(!qry_insert1.exec("insert into DataforStatistic(type_place, date, count_income, count_place) values ('Бельэтаж', '" +ui->dateEdit->text()+ "', 0, 0)"))
                qDebug()<<qry_insert1.lastError().databaseText();
        }
        }
}
