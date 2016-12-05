#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mydb= QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/Kyrs/VTeatre.sqlite");

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
    QPixmap pix_close;
    pix_close.load(":/image/image_close.png");
    pix_close = pix_close.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix_close));
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
    for(int i=0;i<CountRow;i++)
    {
        for(int j=0;j<CountColumn;j++)
        {
            QPixmap pix;
            pix.load(":/image/image.png");
            pix = pix.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
            ui->tableWidget->item(i, j)->setBackground(QBrush(pix));
        }
    }
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
    count_place_purchased=0;
    QSqlQuery qry("select * from Employed_place");
        while(qry.next())
        {
            for(int i=0; i < CountRow; i++)
            {
                for(int j=0; j < CountColumn; j++)
                {
                    if(qry.value(0) == ui->tableWidget->item(i,j)->text() &&
                       qry.value(1) == ui->comboBox->currentText() &&
                       qry.value(2) == ui->dateEdit->text() &&
                       qry.value(3) == ui->tableSeans->item(quantity_prodactions,0)->text()&&
                       qry.value(4) == ui->tableSeans->item(quantity_prodactions,1)->text()&&
                       qry.value(7) == "Куплено" )
                    {
                            count_place_purchased++;
                            pix_close(i, j);
                    }
                    if(qry.value(0) == ui->tableWidget->item(i,j)->text() &&
                       qry.value(1) == ui->comboBox->currentText() &&
                       qry.value(2) == ui->dateEdit->text() &&
                       qry.value(3) == ui->tableSeans->item(quantity_prodactions,0)->text()&&
                       qry.value(4) == ui->tableSeans->item(quantity_prodactions,1)->text()&&
                       qry.value(7) == "Забронировано" )
                    {
                            count_place_purchased++;
                            QPixmap pix_reserv;
                            pix_reserv.load(":/image/image_reserv.png");
                            pix_reserv = pix_reserv.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
                            ui->tableWidget->item(i, j)->setBackground(QBrush(pix_reserv));
                    }
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
        QString place=ui->tableWidget->item(row,column)->text(),
                type_place = ui->comboBox->currentText(),
                date_seansa = ui->dateEdit->text(),
                time_seansa = ui->tableSeans->item(quantity_prodactions,0)->text(),
                name_seansa = ui->tableSeans->item(quantity_prodactions,1)->text();
        QSqlQuery qry("select * from Employed_place where place="+place+" and type_place='"+type_place+"' and date_seansa='"+date_seansa+"' and time_seansa='"+time_seansa+"' and name_seansa='"+name_seansa+"'");
        qry.first();
        if(qry.value(0) == place &&
           qry.value(1) == type_place &&
           qry.value(2) == date_seansa &&
           qry.value(3) == time_seansa &&
           qry.value(4) == name_seansa &&
           qry.value(7) == "Куплено")
        {
            pix_close(row,column);
            coordinates_of_places[row][column]=false;
        }
        else if(qry.value(0) == place &&
                qry.value(1) == type_place &&
                qry.value(2) == date_seansa &&
                qry.value(3) == time_seansa &&
                qry.value(4) == name_seansa &&
                qry.value(7) == "Забронировано")
        {
            pix_reserv(row,column);
            coordinates_of_places[row][column]=false;
        }
        else
        {
            pix_standart(row,column);
            coordinates_of_places[row][column]=false;
        }
    }
    else
    {
        coordinates_of_places[row][column]=true;
        qDebug()<<CountColumn*row+column+1<<"\t"<<coordinates_of_places[row][column]<<coordinates_of_places[row][column+1];
        pix_checking(row,column);

    }

}

void MainWindow::on_comboBox_currentIndexChanged(int index) // по изменению пункта в combobox менять таблицу
{

}


void MainWindow::on_tableSeans_cellClicked(int row, int column) // по нажатию на название изменить таблицу с местами
{
    if(column == 1)
    {
        ui->comboBox->setEnabled(true);
        quantity_prodactions=row;

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
    QString type_place = ui->comboBox->currentText(),
            date_seansa = ui->dateEdit->text(),
            time_seansa = ui->tableSeans->item(quantity_prodactions,0)->text(),
            name_seansa = ui->tableSeans->item(quantity_prodactions,1)->text();
    int row=0, column=0;

    for(int i=0; i<CountRow; i++)
        for(int j=0; j<CountColumn; j++)
            if(coordinates_of_places[i][j])
            {
                row=i;
                column=j;
                        places_overwrite(row,column);
                QSqlQuery qry_insert("insert into Employed_place(place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values ("+
                               ui->tableWidget->item(row,column)->text()+
                        ", '"+
                        type_place+
                        "', '"+
                        date_seansa+
                        "', '"+
                        time_seansa+
                        "', '"+
                        name_seansa+
                        "', "+
                        QString::number(row)+
                        ", "+
                        QString::number(column)+
                        ", 'Куплено')");
                        pix_close(row, column);
             }

    coordinates_of_places_cleaning();
    customizeTableInf();
}

void MainWindow::on_pushButton_2_clicked() // забронировать
{
    QString type_place = ui->comboBox->currentText(),
            date_seansa = ui->dateEdit->text(),
            time_seansa = ui->tableSeans->item(quantity_prodactions,0)->text(),
            name_seansa = ui->tableSeans->item(quantity_prodactions,1)->text();
    int row=0, column=0;

    for(int i=0; i<CountRow; i++)
        for(int j=0; j<CountColumn; j++)
            if(coordinates_of_places[i][j])
            {
                places_overwrite(i,j);
                row=i;
                column=j;
                QSqlQuery qry1("insert into Employed_place(place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values ("+
                               ui->tableWidget->item(row,column)->text()+
                        ", '"+
                        type_place+
                        "', '"+
                        date_seansa+
                        "', '"+
                        time_seansa+
                        "', '"+
                        name_seansa+
                        "', "+
                        QString::number(row)+
                        ", "+
                        QString::number(column)+
                        ", 'Забронировано')");
               pix_reserv(row, column);
             }

    coordinates_of_places_cleaning();
    customizeTableInf();
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
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
    QString type_place = ui->comboBox->currentText(),
            date_seansa = ui->dateEdit->text(),
            time_seansa = ui->tableSeans->item(quantity_prodactions,0)->text(),
            name_seansa = ui->tableSeans->item(quantity_prodactions,1)->text();
    QSqlQuery qry;
    int row,column;
    QSqlQuery qry1("select * from Employed_place");
    for(int i=0; i < CountRow; i++)
        for(int j=0; j < CountColumn; j++)
            if(coordinates_of_places[i][j])
            {
                row=i;
                column=j;
                qry.exec("delete from Employed_place where row="+
                         QString::number(row)+" and column="+
                         QString::number(column)+" and type_place='"+
                         type_place+"' and date_seansa='"+
                         date_seansa+"' and name_seansa='"+
                         name_seansa+"' and time_seansa='"+
                         time_seansa+"'");
                pix_standart(row,column);
            }
    coordinates_of_places_cleaning();
    customizeTableInf();
}

void MainWindow::create_a_MainTable()
{//создаю таблицу с местами
    QSqlQuery qry("select * from Options");

    ui->tableWidget->setRowCount(CountRow);
    ui->tableWidget->setColumnCount(CountColumn);

    for(int i=0; i < ui->tableWidget->rowCount(); i++){
        for(int j=0; j < ui->tableWidget->colorCount(); j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem);
        }
    }

    QPixmap pix1;
    pix1.load(":/image/image.png");

    QTableWidgetItem *item;

    row_height = ui->tableWidget->height() / ui->tableWidget->rowCount();
    column_width = ui->tableWidget->width() / ui->tableWidget->columnCount();

    pix1 = pix1.scaled(column_width, row_height);
    for(int i = 0; i < ui->tableWidget->rowCount();i++)
    {
        ui->tableWidget->setRowHeight(i, row_height); // высота строк
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            if(i == 0)
                ui->tableWidget->setColumnWidth(j, column_width); // ширина столбцов
            item = new QTableWidgetItem;
            item->setBackground(QBrush(pix1));
            item->setText(QString::number(i*ui->tableWidget->columnCount() + j + 1));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(item->flags() & (~Qt::ItemIsSelectable)); // устанавливаю флаг ItemIsSelectable в false
            ui->tableWidget->setItem( i, j, item );
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

    QSqlQuery qry("select * from Employed_place");
    while(qry.next())
    {
        for(int i=0; i < CountRow; i++)
        {
            for(int j=0; j < CountColumn; j++)
            {
                if(qry.value(0) == ui->tableWidget->item(i,j)->text() &&
                   qry.value(1) == ui->comboBox->currentText() &&
                   qry.value(2) == ui->dateEdit->text() &&
                   qry.value(3) == ui->tableSeans->item(quantity_prodactions,0)->text()&&
                   qry.value(4) == ui->tableSeans->item(quantity_prodactions,1)->text())
                {
                    if(qry.value(7) == "Куплено")
                        CountPurchased++;
                    if(qry.value(7) == "Забронировано")
                        CountBooked++;
                }
            }
        }
    }
    int CountOfPlaces = CountColumn * CountRow;
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
