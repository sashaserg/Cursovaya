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
    mydb.setDatabaseName("D:/Cursovaya/VTeatre.sqlite");

    if(!mydb.open())
        qDebug()<<mydb.lastError().text();
    else
        qDebug()<<"Connected Compled";

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






    /*QSqlQuery qry("select * from Employed_place");
    while(qry.next())
    {
        for(int i=0;i<13;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(qry.value(0)==ui->tableWidget->item(i,j)->text() &&
                    qry.value(1)==ui->comboBox->currentText() &&
                    qry.value(2)==ui->dateEdit->text() &&
                    qry.value(3)== ui->tableSeans->item(quantity_prodactions,0)->text()&&
                    qry.value(4)== ui->tableSeans->item(quantity_prodactions,1)->text())
                {
                    kol_sovpadeniy++;
                }
            }
        }
    }

    for(int i= 0 ; i<kol_sovpadeniy;i++){
        mesto[i][0] = chislo_s_BD/13;
        mesto[i][1] = chislo_s_BD%13;
    }
    qDebug()<<kol_sovpadeniy;*/



}
void MainWindow::cleasing_places()//очистка мест
{

    /*for(int i=0;i<13;i++)
    {
        for(int j=0;j<9;j++)
        {
            QPixmap pix;
            pix.load(":/image/image.png");
            pix = pix.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
            ui->tableWidget->item(i, j)->setBackground(QBrush(pix));
        }
    }*/
}

void MainWindow::places_fill()//заполнение мест
{
    count_place_purchased=0;
    QSqlQuery qry("select * from Employed_place");
        while(qry.next())
        {
            for(int i=0;i<13;i++)
            {
                for(int j=0;j<9;j++)
                {
                    if(qry.value(0)==ui->tableWidget->item(i,j)->text() &&
                       qry.value(1)==ui->comboBox->currentText() &&
                       qry.value(2) == ui->dateEdit->text() &&
                       qry.value(3)== ui->tableSeans->item(quantity_prodactions,0)->text()&&
                       qry.value(4)== ui->tableSeans->item(quantity_prodactions,1)->text())
                    {
                        count_place_purchased++;
                        //ui->tableInfo->item(0,1)->setText("Продано: "+QString::number(count_place_purchased));
qDebug()<<"нашел совпадение";
                        QPixmap pix_close;
                        pix_close.load(":/image/image_close.png");
                        pix_close = pix_close.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
                        ui->tableWidget->item(i, j)->setBackground(QBrush(pix_close));
qDebug()<<"установил красный цвет ячейке";
                    }
                }
            }
        }
qDebug()<<"вышел из цикла";
        ui->tableInfo->item(0,1)->setText("Продано: "+QString::number(count_place_purchased));//продано мест
        ui->tableInfo->item(1,0)->setText("Свободно: "+QString::number(count_places_all-count_place_purchased));//свободно мест

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
    QPixmap pix2;
    pix2.load(":/image/image_checking.png");
    pix2 = pix2.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    bool stat = false;
    for(int i=0;i<117;i++){
        if(mesto[i][0] == row && mesto[i][1] == column){
            stat = true;
        }
    }
    if(!stat){
        mesto[index_mesta][0]=row;//записываю строку
        mesto[index_mesta][1]=column;//записываю столбик
        index_mesta++;//записываю индекс количества выбраных мест
        ui->tableWidget->item(row, column)->setBackground(QBrush(pix2));
    }
    stat = false;
}

void MainWindow::on_comboBox_currentIndexChanged(int index) // по изменению пункта в combobox менять таблицу
{
    switch(index)
    {
    case 0:
        break;

    case 1:
        break;

    case 2:
        break;
    }
}


void MainWindow::on_tableSeans_cellClicked(int row, int column) // по нажатию на название изменить таблицу с местами
{
create_a_MainTable();
qDebug()<<"196";
    if(column == 1)
    {
         quantity_prodactions=row;
         cleasing_places();
         places_fill();
    }
}

void MainWindow::on_dateEdit_dateChanged(const QDate &date)//Выводит сеансы по дате
{
        cleasing_places();
        QString date_seansa=ui->dateEdit->text();
        QString query = "select * from Postanovka where date_seansa='"+date_seansa+"'";
        QSqlQuery qry1;
        qry1.exec(query);
        int i = 0;
        QString Postanovka[255][2];
        while(qry1.next())
        {
                for(int j=0; j<2;++j)
                {
                    Postanovka[i][j]=qry1.value(2-j).toString();//записывает данные спектакля в массив
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

    for(int i=0; i<index_mesta; i++)
    {
        QSqlQuery qry1("insert into Employed_place(place, type_place, date_seansa, time_seansa, name_seansa, row, column, state) values ("+
                       ui->tableWidget->item(mesto[i][0],mesto[i][1])->text()+
                ", '"+
                type_place+
                "', '"+
                date_seansa+
                "', '"+
                time_seansa+
                "', '"+
                name_seansa+
                "')");
    }
    QPixmap pix_close;
    pix_close.load(":/image/image_close.png");
    pix_close = pix_close.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    for(int i=0; i<index_mesta;i++)
    {
        ui->tableWidget->item(mesto[i][0], mesto[i][1])->setBackground(QBrush(pix_close));
    }
    ui->tableInfo->item(0,1)->setText("Продано: "+QString::number(count_place_purchased+=index_mesta));//продано мест
    ui->tableInfo->item(1,0)->setText("Свободно: "+QString::number(count_place_free=count_places_all-count_place_purchased));//свободно мест
    index_mesta=0;

}

void MainWindow::on_pushButton_2_clicked() // забронировать
{
    QPixmap pix_reserv;
    pix_reserv.load(":/image/image_reserv.png");
    pix_reserv = pix_reserv.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    for(int i=0; i<index_mesta;i++)
    {
        ui->tableWidget->item(mesto[i][0], mesto[i][1])->setBackground(QBrush(pix_reserv));
    }

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    cleasing_places();
    places_fill();
}

void MainWindow::on_action_exit_triggered() // пункт Выход
{
}

void MainWindow::on_action_statistic_sale_triggered() // окно статистики
{
    Statistic *wind = new Statistic(this);
    wind->show();
}

void MainWindow::on_pushButton_3_clicked()//вернуть
{
    QSqlQuery qry;
    int place;
    QPixmap pix;
    pix.load(":/image/image.png");
    pix = pix.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    QSqlQuery qry1("select * from Employed_place");
    for(int k=0;k<index_mesta;k++)
    {
        place=ui->tableWidget->item(mesto[k][0], mesto[k][1])->text().toInt();
        qry.exec("delete from Employed_place where place="+QString::number(place));
        ui->tableWidget->item(mesto[k][0], mesto[k][1])->setBackground(QBrush(pix));
    }


    ui->tableInfo->item(0,1)->setText("Продано: "+QString::number(count_place_purchased-=index_mesta));
    ui->tableInfo->item(1,0)->setText("Свободно: "+QString::number(count_place_free+index_mesta));
    index_mesta=0;

}

void MainWindow::create_a_MainTable(){//создаю таблицу с местами
    ui->tableWidget->setRowCount(13);
    ui->tableWidget->setColumnCount(9);

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
    wind->show();
}
