#include "addscene.h"
#include "ui_addscene.h"

AddScene::AddScene(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScene)
{
    ui->setupUi(this);
    mydb= QSqlDatabase::addDatabase("QSQLITE");                     // Подключение базы данных
    mydb.setDatabaseName("I:/Soft/Curs/Cursovaya/VTeatre.sqlite");

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

}
