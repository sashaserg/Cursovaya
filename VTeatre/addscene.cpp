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

AddScene::~AddScene()
{
    delete ui;
}

void AddScene::on_ButtonAdd_clicked()                               // Нажатие на кнопку "Добавить"
{
    Scene temp;
    temp.set_cost(ui->ParterPrice->value(), ui->BenuarPrice->value(), ui->BeletazPrice->value());
    temp.set_date(ui->dateEdit->text());
    temp.set_time(ui->timeEdit->text());
    temp.set_name(ui->NameLineEdit->text());

    Scenes.append(temp);

    qDebug()<< "Added";

    QList<Scene>::const_iterator it = Scenes.constBegin();
    for(; it != Scenes.constEnd(); ++it)
    {}//записать в базу данных все сцены с листа.


    QSqlQuery qry_insert("insert into Postanovka(name, time_seansa, date_seansa, cost_parter, cost_benuar, cost_beletaj) values('"+ui->NameLineEdit->text()+
                         "', '"+ui->timeEdit->text()+
                         "', '"+ui->dateEdit->text()+
                         "', "+QString::number(ui->ParterPrice->value())+
                         ", "+QString::number(ui->BenuarPrice->value())+
                         ", "+QString::number(ui->BeletazPrice->value())+")");

}
