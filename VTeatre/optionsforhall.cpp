#include "optionsforhall.h"
#include "ui_optionsforhall.h"

OptionsForHall::OptionsForHall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsForHall)
{
    ui->setupUi(this);

    TypeOfPlace = 1;
    for(int i = 0; i < 3; i++)
        Array[i][0] = Array[i][1] = -1;

    mydb= QSqlDatabase::addDatabase("QSQLITE");         //ПОдключаю БД
    mydb.setDatabaseName("D:/Kyrs/VTeatre.sqlite");

    if(!mydb.open())
        qDebug()<<mydb.lastError().text();
    else
        qDebug()<<"Connected Compled";

    QSqlQuery qry("select * from Options");

    for(int i = 0; qry.next(); i++)        //загрузить значения из БД
    {
        Array[i][0] = qry.value(1).toInt();//row
        Array[i][1] = qry.value(2).toInt();//column
    }

    for(int i = 0; i<3; i++)
        qDebug()<<Array[i][0]<<"\t"<<Array[i][1];

    CountColumn = Array[0][1];//количество колонок и строк в таблице
    CountRow = Array[0][0];

    ui->spinBox_Column->setValue(CountColumn);//изменить чекбоксы
    ui->spinBox_Row->setValue(CountRow);

}

OptionsForHall::~OptionsForHall()
{
    delete ui;
}

void OptionsForHall::on_spinBox_Row_valueChanged(int arg1)//при изменении количества рядов
{
    CountRow = arg1;
    DrawTable();    //перерисовываю таблицу
    //после перерисовки таблицы необходимо сохранить значения в массив
    Array[TypeOfPlace][0] = CountRow;
    Array[TypeOfPlace][1] = CountColumn;
}

void OptionsForHall::on_spinBox_Column_valueChanged(int arg1)//при изменении количества мест в ряду
{
    CountColumn = arg1;
    DrawTable();    //перерисовываю таблицу
    //после перерисовки таблицы необходимо сохранить значения в массив
    Array[TypeOfPlace][0] = CountRow;
    Array[TypeOfPlace][1] = CountColumn;
}

void OptionsForHall::DrawTable()
{
    QTableWidgetItem *item;

    ui->tableWidget->setRowCount(CountRow);         //задаю таблице нужное количечство строк
    ui->tableWidget->setColumnCount(CountColumn);   //и столбцов

    for(int i=0; i < CountRow; i++){                //освобождаю для них память
        for(int j=0; j < CountColumn; j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem);
        }
    }

    int row_height = ui->tableWidget->height() / ui->tableWidget->rowCount();   //подсчитываю высоту строк
    int column_width = ui->tableWidget->width() / ui->tableWidget->columnCount(); // и ширину столбцов

    if(row_height > 100)    //задаю максимальные значения для высоты и ширины ячеек
        row_height = 100;
    if(column_width > 200)
        column_width = 200;

    QPixmap pix1;                       //храню пиксмап с изображением зеленого овала
    pix1.load(":/image/image.png");
    pix1 = pix1.scaled(column_width, row_height);//устанавливаю для него нужный размер

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
            ui->tableWidget->setItem( i, j, item );//вставляю в ячейку созданный Item
        }
    }
}

void OptionsForHall::on_ComboBoxType_currentIndexChanged(int index)
{
    TypeOfPlace = index;

    CountColumn = Array[TypeOfPlace][1];//количество колонок и строк в таблице
    CountRow = Array[TypeOfPlace][0];

    ui->spinBox_Column->setValue(CountColumn);//изменить чекбоксы
    ui->spinBox_Row->setValue(CountRow);
    //затем присвоить
    //перерисовать таблицу
    //изменить значения комбобокса
}

void OptionsForHall::on_pushButtonOK_clicked()
{
    if(Array[0][0] != -1)
        QSqlQuery qry1("update options set kol_rows=" + QString::number(Array[0][0]) + ", kol_column=" + QString::number(Array[0][1]) + " where type_place = 'Партер'");
    if(Array[1][0] != -1)
        QSqlQuery qry1("update options set kol_rows=" + QString::number(Array[1][0]) + ", kol_column=" + QString::number(Array[1][1]) + " where type_place = 'Бенуар'");
    if(Array[2][0] != -1)
        QSqlQuery qry1("update options set kol_rows=" + QString::number(Array[2][0]) + ", kol_column=" + QString::number(Array[2][1]) + " where type_place = 'Бельэтаж'");
for(int i = 0; i<3; i++)
    qDebug()<<Array[i][0]<<"\t"<<Array[i][1];

}
