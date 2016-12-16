#include "addscene.h"
#include "ui_addscene.h"

AddScene::AddScene(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScene)
{
    ui->setupUi(this);
    mydb = QSqlDatabase::addDatabase("QSQLITE");            // Подключение базы данных
    QString path = qApp->applicationDirPath() + "/VTeatre.sqlite";
    mydb.setDatabaseName("./VTeatre.sqlite");
    mydb.open();
    Editing = false;                                        //Флаг редактирования
}

AddScene::AddScene(bool Edit,Scene *temp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScene)
{
    ui->setupUi(this);

    Editing = Edit;                                         //Флаг редактирования
    PriviosName= temp->name;                                //Предыдущее имя
    PriviosDate = temp->date;                               //Предыдущая дата
    PriviosTime = temp->time;                               //Предыдущее время
    ui->NameLineEdit->setText(temp->name);                  //Устанавливаем необходимое название постановки в поле
    ui->timeEdit->setTime(QTime::fromString(temp->time));   //а так же дату и время и цены
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
        QSqlQuery qry_select;
        if(!qry_select.exec("select * from Postanovka where date_seansa='" +ui->dateEdit->text()+ "' and time_seansa='"+ui->timeEdit->text()+"'"))
        {
            qDebug()<<qry_select.lastError().databaseText();
        }
        qry_select.first();
        QSqlQuery qry_insert;
        if(qry_select.value(2).toString()!=ui->dateEdit->text() && qry_select.value(1).toString()!=ui->timeEdit->text())
        {
            qry_insert.exec("insert into Postanovka(name, time_seansa, date_seansa, cost_parter, cost_benuar, cost_beletaj) values('" + ui->NameLineEdit->text()+
                         "', '" + ui->timeEdit->text()+
                         "', '"+ui->dateEdit->text()+
                         "', "+QString::number(ui->ParterPrice->value())+
                         ", "+QString::number(ui->BenuarPrice->value())+
                         ", "+QString::number(ui->BeletazPrice->value())+")");
        }
        else {qDebug()<<"1";}
        //QSqlQuery qry_insert1;
        QSqlQuery qry_select1;
        if(!qry_select1.exec("select * from DataforStatistic where date='" +ui->dateEdit->text()+ "'"))
        {
            qDebug()<<qry_select1.lastError().databaseText();
        }
        qry_select1.first();
        if(qry_select1.value(3).toString()!=ui->dateEdit->text())
        {
            if(!qry_insert.exec("insert into DataforStatistic(type_place, date, count_income, count_place) values ('Партер', '" +ui->dateEdit->text()+ "', 0, 0)"))
                qDebug()<<qry_insert.lastError().databaseText();
            if(!qry_insert.exec("insert into DataforStatistic(type_place, date, count_income, count_place) values ('Бенуар', '" +ui->dateEdit->text()+ "', 0, 0)"))
                qDebug()<<qry_insert.lastError().databaseText();
            if(!qry_insert.exec("insert into DataforStatistic(type_place, date, count_income, count_place) values ('Бельэтаж', '" +ui->dateEdit->text()+ "', 0, 0)"))
                qDebug()<<qry_insert.lastError().databaseText();
        }
        }
}
