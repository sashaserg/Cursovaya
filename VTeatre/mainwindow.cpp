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

    //dateEdit.DateTime выставляется в текущую дату
    dt = QDateTime::currentDateTime();
    ui->dateEdit->setDateTime(dt);
    ui->dateEdit->setMinimumDateTime(dt); // минимальная дата выставляется по текущей дате

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

// вставляю картинку и текст в ячейку------------------
    QPixmap pix1;
    pix1.load(":/image/image.png");

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setBackground(QBrush(pix1));

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
// -----------------------------------------------
// Работа с таблицей информации о местах------------------

    QString buff = ui->tableInfo->item(0,0)->text(); // Всего мест
    buff += " " + QString::number(ui->tableWidget->rowCount()*ui->tableWidget->columnCount());
    ui->tableInfo->item(0,0)->setText(buff);


//----------------------------------------------------

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

int mesto[117][2];//запоминаю столбик и строчку
int index_mesta=0;//индекс количества выбраных мест

void MainWindow::on_tableWidget_cellClicked(int row, int column) // по нажатию на ячейку она меняет цвет
{
    QPixmap pix2;
    pix2.load(":/image/image_checking.png");
    pix2 = pix2.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));

    mesto[index_mesta][0]=row;//записываю строку
    mesto[index_mesta][1]=column;//записываю столбик
    index_mesta++;//записываю индекс количества выбраных мест
    ui->tableWidget->item(row, column)->setBackground(QBrush(pix2));

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
    if(column == 1)
    {


    }
}

void MainWindow::on_dateEdit_dateChanged(const QDate &date)//Выводит сеансы по дате
{
        QString a=ui->dateEdit->text();
        int b=2;
        QString query = "select * from Postanovka where date_seansa='"+a+"'";
        QSqlQuery qry1;
        qry1.exec(query);
        QString date_seansa;
        QString Name_seansa;
        QString Time_seansa;
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

        // ---------------------------------------------------
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
            time_seansa = ui->tableSeans->item(0,1)->text(),
            name_seansa = ui->tableSeans->item(0,0)->text();

    for(int i=0; i<index_mesta; i++)
    {
        QSqlQuery qry1("insert into Employed_place(place, type_place, date_seansa, time_seansa, name_seansa) values ("+
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
    index_mesta=0;
}
