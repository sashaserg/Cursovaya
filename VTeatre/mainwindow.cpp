﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/Cursovaya/Cursovaya/VTeatre.sqlite");


    CurScene = new Scene(3);

    if(!mydb.open())
        qDebug()<<mydb.lastError().text();
    else
        qDebug()<<"Connected Compled";

    QSqlQuery qry("select * from Options where type_place = '" + ui->comboBox->currentText() + "'");
    qry.next();
    CountRow = qry.value(1).toInt();
    CountColumn = qry.value(2).toInt();

    CountPurchased = 0;
    CountBooked = 0;
    /*
    for(int i = 0; qry.next(); i++)                     //загрузить значения из БД
    {
        Array[i][0] = qry.value(1).toInt();             //row
        Array[i][1] = qry.value(2).toInt();             //column
    }

    CountColumn = Array[0][1];                          //количество колонок и строк в таблице
    CountRow = Array[0][0];
    */

    // устанавливаю картинки
    // QGraphicsScene * scen = new QGraphicsScene();
    QPixmap  pix;
    pix.load(":/image/scena.png");
    pix = pix.scaled(ui->label_2->size());
    ui->label_2->setPixmap(pix);

    QPixmap pix_Legend(":/image/Legend.png");
    pix_Legend = pix_Legend.scaled(ui->label_4->size(), Qt::KeepAspectRatio);
    ui->label_4->setPixmap(pix_Legend);


    /* for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
            ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);*/ // Нужно поставить текст ячейки по центру.

// -----------------------------------------------
// Работа с таблицей информации о местах------------------

    ui->tableInfo->item(0,0)->setText("Всего мест: " + QString::number(count_places_all=ui->tableWidget->rowCount()*ui->tableWidget->columnCount()));

//----------------------------------------------------
    //dateEdit.DateTime выставляется в текущую дату
    dt = QDateTime::currentDateTime();
    ui->dateEdit->setDateTime(dt);
    ui->dateEdit->setMinimumDateTime(dt); // минимальная дата выставляется по текущей дате

    ui->tableSeans->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрет редактирования всех ячеек в таблице tableSeans
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрет редактирования всех ячеек в таблице tableWidget
/*
    ui->tableWidget->setMinimumSize(ui->tableWidget->size());
    ui->tableInfo->setMinimumSize(ui->tableInfo->size());
    ui->pushButton->setMinimumSize(ui->pushButton->size());
    ui->pushButton_2->setMinimumSize(ui->pushButton_2->size());
    ui->pushButton_3->setMinimumSize(ui->pushButton_3->size());
    ui->label->setMinimumSize(ui->label->size());
    ui->label_2->setMinimumSize(ui->label_2->size());
    ui->label_3->setMinimumSize(ui->label_3->size());
    ui->label_4->setMinimumSize(ui->label_4->size());
    ui->comboBox->setMinimumSize(ui->comboBox->size());
*/
    coordinates_of_places = new bool*[CountRow];
    for(int i = 0; i < CountRow; i++)
        coordinates_of_places[i] = new bool [CountColumn];
    for(int i=0; i < CountRow; i++)
      for(int j = 0; j < CountColumn; j++)
      {
           coordinates_of_places[i][j]=false;
      }

    ui->comboBox->setEnabled(false);
}
void MainWindow::pix_close(int row, int column)
{
    QPixmap pix_close1;
    pix_close1.load(":/image/image_close.png");
    pix_close1 = pix_close1.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_close1));
}

void MainWindow::pix_reserv(int row, int column)
{
    QPixmap pix_reserv;
    pix_reserv.load(":/image/image_reserv.png");
    pix_reserv = pix_reserv.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_reserv));
}

void MainWindow::pix_checking(int row, int column)
{
    QPixmap pix_checking;
    pix_checking.load(":/image/image_checking.png");
    pix_checking = pix_checking.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_checking));
}

void MainWindow::pix_standart(int row, int column)
{
    QPixmap pix_standart;
    pix_standart.load(":/image/image.png");
    pix_standart = pix_standart.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_standart));
}

void MainWindow::cleasing_places()//очистка мест
{
    /*for(int i=0;i<CountRow;i++)
    {
        for(int j=0;j<CountColumn;j++)
        {
            QPixmap pix;
            pix.load(":/image/image.png");
            pix = pix.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
            ui->tableWidget->item(i, j)->setBackground(QBrush(pix));
        }
    }*/
}

void MainWindow::coordinates_of_places_cleaning()
{
    for(int i = 0; i < CountRow; i++)
        delete [] coordinates_of_places[i];
    delete []coordinates_of_places;

    coordinates_of_places = new bool*[CountRow];
    for(int i = 0; i < CountRow; i++)
        coordinates_of_places[i] = new bool [CountColumn];
    for(int i=0; i < CountRow; i++)
      for(int j = 0; j < CountColumn; j++)
      {
           coordinates_of_places[i][j]=false;
      }
}

void MainWindow::places_fill()//заполнение мест
{
    int temp = ui->comboBox->currentIndex();

    for(int i=0; i < CurScene->ArrayCountPlaces[temp][0]; i++)
    {
        for(int j=0; j < CurScene->ArrayCountPlaces[temp][1]; j++)
        {
            if(CurScene->TablesPlaces[temp][i][j] == 0){
                pix_standart(i, j);
                continue;
            }
            if(CurScene->TablesPlaces[temp][i][j] == 1){
                pix_close(i, j);
                continue;
            }
            if(CurScene->TablesPlaces[temp][i][j] == 2){
                pix_reserv(i, j);
                continue;
            }
        }
    }
}

void MainWindow::places_overwrite(int row, int column)
{
    QString type_place = ui->comboBox->currentText(),
            date_seansa = ui->dateEdit->text(),
            time_seansa = ui->tableSeans->item(quantity_prodactions,0)->text(),
            name_seansa = ui->tableSeans->item(quantity_prodactions,1)->text();
    QSqlQuery qry;
    qry.exec("delete from Employed_place where row="+
             QString::number(row)+" and column="+
             QString::number(column)+" and type_place='"+
             type_place+"' and date_seansa='"+
             date_seansa+"' and name_seansa='"+
             name_seansa+"' and time_seansa='"+
             time_seansa+"'");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_informationAbout_triggered()
{
    About *window = new About(this);
    window->show();
}

void MainWindow::on_action_triggered()
{
  // открытие окна покупателя, класс WindowBuyer
}

void MainWindow::on_tableWidget_cellClicked(int row, int column) // по нажатию на ячейку она меняет цвет
{
    if(coordinates_of_places[row][column])//проверяет активно ли нажатое место
    {
        int temp = ui->comboBox->currentIndex();

        if(CurScene->TablesPlaces[temp][row][column] == 0)
            pix_standart(row,column);
        if(CurScene->TablesPlaces[temp][row][column] == 1)
            pix_close(row,column);
        if(CurScene->TablesPlaces[temp][row][column] == 2)
            pix_reserv(row,column);

        coordinates_of_places[row][column]=false;

        for(int i = 0; i < SelectedPlaces.size(); i ++){
            if(SelectedPlaces[i] == CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1] * row + column + 1){
                SelectedPlaces.erase(SelectedPlaces.begin() + i - 1);
            }
            qDebug()<<SelectedPlaces[i];
        }
    }
    else
    {
        coordinates_of_places[row][column]=true;
        pix_checking(row,column);
        SelectedPlaces.push_back(CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1] * row + column + 1);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index) // по изменению пункта в combobox менять таблицу
{
    qDebug()<<1;
    coordinates_of_places_cleaning();
    qDebug()<<2;
    create_a_MainTable();
    qDebug()<<3;
    places_fill();
    qDebug()<<4;
    customizeTableInf();
    qDebug()<<5;
    SelectedPlaces.clear();
    qDebug()<<6;
}


void MainWindow::on_tableSeans_cellClicked(int row, int column) // по нажатию на название изменить таблицу с местами
{
    qDebug()<<1;
    if(column == 1)
    {
        ui->comboBox->setEnabled(true);

        delete CurScene;
        CurScene = new Scene(3);

        //1 - найти имя, время, дата
        CurScene->set_name(ui->tableSeans->item(row, 1)->text());
        CurScene->set_time(ui->tableSeans->item(row, 0)->text());
        CurScene->set_date(ui->dateEdit->text());

        qDebug()<<CurScene->name;
        qDebug()<<CurScene->time;
        qDebug()<<CurScene->date;

        //2 - найти количество мест в каждом типе
        CurScene->SetArrayCountPlaces();

        qDebug()<<CurScene->ArrayCountPlaces[0][0];
        qDebug()<<CurScene->ArrayCountPlaces[0][1];
        qDebug()<<CurScene->ArrayCountPlaces[1][0];
        qDebug()<<CurScene->ArrayCountPlaces[1][1];
        qDebug()<<CurScene->ArrayCountPlaces[2][0];
        qDebug()<<CurScene->ArrayCountPlaces[2][1];

        //3 - найти инф. о каждом месте
        CurScene->SetDataToTables();

        coordinates_of_places_cleaning();
        create_a_MainTable();
        places_fill();
        customizeTableInf();

        SelectedPlaces.clear();
        ui->comboBox->setCurrentIndex(0);
    }
}

void MainWindow::on_dateEdit_dateChanged(const QDate &date)//Выводит сеансы по дате
{
        //cleasing_places();
        QString date_seansa=ui->dateEdit->text();
        QString query = "select * from Postanovka where date_seansa='"+date_seansa+"'";
        QSqlQuery qry1;
        qry1.exec(query);
        int i = 0;
        QString Postanovka[255][2];
        while(qry1.next())
        {
                for(int j=0; j < 2 ;++j)
                {
                    Postanovka[i][j]=qry1.value(1-j).toString();//записывает данные спектакля в массив
                }

                ++i;
         }

        // работа с таблицей сеансов-------------------------------

            ui->tableSeans->setRowCount(i); // указываем количество строк, вместо 10 нужно подставлять количество спектаклей на какое-то число
            for(int row = 0; row < ui->tableSeans->rowCount(); row++)
              for(int column = 0; column < ui->tableSeans->columnCount(); column++)
              {
                  QTableWidgetItem *item = new QTableWidgetItem(); // выделяем память под ячейку
                  //item->setText(QString::number(row + column)); // вставляем текст
                  ui->tableSeans->setItem(row, column, item); // вставляем ячейку
              }
            ui->tableSeans->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents); // Ширина столбца с датой по размеру контента
            ui->tableSeans->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // Ширина столбца с названиями всё остальное пространство
            for(int k=0;k<i;++k)
            {
                for(int j =0;j<2;++j)
                {
                    ui->tableSeans->item(k,j)->setText(Postanovka[k][j]);
                }
            }
        i=0;
}




void MainWindow::on_pushButton_clicked() // купить
{
    int temp = ui->comboBox->currentIndex();

    for(int i = 0; i < SelectedPlaces.size(); i++){

        int row = SelectedPlaces[i] / CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1];
        int column  = SelectedPlaces[i] % CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1]-1;

        if(CurScene->TablesPlaces[temp][row][column] == 1){
            SelectedPlaces.erase(SelectedPlaces.begin() + i - 1);
        }
        else
            CurScene->TablesPlaces[temp][row][column] = 1;
    }
    for(int i = 0; i < SelectedPlaces.size(); i++){
        qDebug()<<SelectedPlaces[i];
    }
    CurScene->InsertTablesToDataBase(SelectedPlaces, ui->comboBox->currentIndex(), 1);
    places_fill();
    coordinates_of_places_cleaning();
    customizeTableInf();
    SelectedPlaces.clear();
}

void MainWindow::on_pushButton_2_clicked() // забронировать
{
    int temp = ui->comboBox->currentIndex();

    for(int i = 0; i < SelectedPlaces.size(); i++){

        int row = SelectedPlaces[i] / CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1];
        int column  = SelectedPlaces[i] % CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1]-1;

        if(CurScene->TablesPlaces[temp][row][column] == 2){
            SelectedPlaces.erase(SelectedPlaces.begin() + i - 1);
        }
        else
            CurScene->TablesPlaces[temp][row][column] = 2;
    }
    for(int i = 0; i < SelectedPlaces.size(); i++){
        qDebug()<<SelectedPlaces[i];
    }
    CurScene->InsertTablesToDataBase(SelectedPlaces, ui->comboBox->currentIndex(), 2);
    places_fill();
    coordinates_of_places_cleaning();
    customizeTableInf();
    SelectedPlaces.clear();
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

}

void MainWindow::on_action_exit_triggered() // пункт Выход
{
}

void MainWindow::on_action_statistic_sale_triggered() // окно статистики
{
    Statistic *wind = new Statistic(dt, this);
    wind->show();
}

void MainWindow::on_pushButton_3_clicked()//вернуть
{
    int temp = ui->comboBox->currentIndex();

    for(int i = 0; i < SelectedPlaces.size(); i++){

        int row = SelectedPlaces[i] / CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1];
        int column  = SelectedPlaces[i] % CurScene->ArrayCountPlaces[ui->comboBox->currentIndex()][1]-1;

        if(CurScene->TablesPlaces[temp][row][column] == 0){
            SelectedPlaces.erase(SelectedPlaces.begin() + i - 1);
        }
        else
            CurScene->TablesPlaces[temp][row][column] = 0;
    }
    for(int i = 0; i < SelectedPlaces.size(); i++){
        qDebug()<<SelectedPlaces[i];
    }
    CurScene->InsertTablesToDataBase(SelectedPlaces, ui->comboBox->currentIndex(), 0);
    places_fill();
    coordinates_of_places_cleaning();
    customizeTableInf();
    SelectedPlaces.clear();
}

void MainWindow::create_a_MainTable()
{//создаю таблицу с местами
    int temp = ui->comboBox->currentIndex();
    ui->tableWidget->setRowCount(CurScene->ArrayCountPlaces[temp][0]);
    ui->tableWidget->setColumnCount(CurScene->ArrayCountPlaces[temp][1]);

    for(int i=0; i < ui->tableWidget->rowCount(); i++){
        for(int j=0; j < ui->tableWidget->colorCount(); j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem);
        }
    }

    QPixmap pix1;
    pix1.load(":/image/image.png");
    pix1 = pix1.scaled(column_width, row_height);

    QTableWidgetItem *item;

    row_height = ui->tableWidget->height() / ui->tableWidget->rowCount();
    column_width = ui->tableWidget->width() / ui->tableWidget->columnCount();

    for(int i = 0; i < ui->tableWidget->rowCount();i++)
    {
        ui->tableWidget->setRowHeight(i, row_height); // высота строк
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            item = new QTableWidgetItem;
            item->setText(QString::number(i*ui->tableWidget->columnCount() + j + 1));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(item->flags() & (~Qt::ItemIsSelectable)); // устанавливаю флаг ItemIsSelectable в false
            ui->tableWidget->setItem( i, j, item );

            if(i == 0)
                ui->tableWidget->setColumnWidth(j, column_width); // ширина столбцов
        }
    }
    //places_fill();
}

void MainWindow::on_options_room_triggered()
{
    OptionsForHall *wind = new OptionsForHall(this);
    wind->exec();

    QSqlQuery qry("select * from Options where type_place = '" + ui->comboBox->currentText() + "'");

    qry.first();
    CountRow = qry.value(1).toInt();
    CountColumn = qry.value(2).toInt();
    coordinates_of_places_cleaning();
    create_a_MainTable();
    cleasing_places();
    places_fill();
    customizeTableInf();
}

void MainWindow::on_action_addScene_triggered()                 // нажатие на "Добавить постановку"
{
    AddScene *window = new AddScene(this);
    window->show();
}

void MainWindow::customizeTableInf()
{
    CountPurchased = 0;
    CountBooked = 0;

    int temp = ui->comboBox->currentIndex();
        for(int i=0; i < CurScene->ArrayCountPlaces[temp][0] ; i++)
        {
            for(int j=0; j < CurScene->ArrayCountPlaces[temp][1]; j++)
            {
                if(CurScene->TablesPlaces[temp][i][j] == 1)
                    CountPurchased++;
                if(CurScene->TablesPlaces[temp][i][j] == 2)
                    CountBooked++;
            }
        }

    int CountOfPlaces = CurScene->ArrayCountPlaces[temp][0] * CurScene->ArrayCountPlaces[temp][1];
    ui->tableInfo->item(0,0)->setText("Всего мест: " + QString::number(CountOfPlaces));
    ui->tableInfo->item(0,1)->setText("Продано: " + QString::number(CountPurchased));
    ui->tableInfo->item(1,1)->setText("Бронь: " + QString::number(CountBooked));
    ui->tableInfo->item(1,0)->setText("Свободно: " + QString::number(CountOfPlaces - CountPurchased - CountBooked));
}

void MainWindow::on_action_hovered()
{

}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{

}
