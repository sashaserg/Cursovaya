#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //dateEdit.DateTime выставляется в текущую дату
    dt = QDateTime::currentDateTime();
    ui->dateEdit->setDateTime(dt);
    ui->dateEdit->setMinimumDateTime(dt); // минимальная дата выставляется по текущей дате

    // устанавливаю картинки
    QGraphicsScene * scen = new QGraphicsScene();
    QPixmap * pix = new QPixmap();
    pix->load("scena");
    scen = new QGraphicsScene();
    scen->addPixmap(*pix);
    ui->label_2->setPixmap(*pix);

    /* for(int i = 0; i < ui->tableWidget->rowCount(); i++)
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
            ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignCenter);*/ // Нужно поставить текст ячейки по центру.

// вставляю картинку и текст в ячейку------------------
    QPixmap pix1;
    pix1.load(":/image/image.png");
    pix1 = pix1.scaled(ui->tableWidget->columnWidth(0), ui->tableWidget->rowHeight(0));
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setBackground(QBrush(pix1));
    for(int i = 0; i < ui->tableWidget->rowCount();i++)
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            item = new QTableWidgetItem;
            item->setBackground(QBrush(pix1));
            item->setText(QString::number(i*ui->tableWidget->columnCount() + j + 1));
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem( i, j, item );

        }

// -----------------------------------------------

               /* item->setData( Qt::DecorationRole, *pix );
                item->setFlags( item->flags() ^ Qt::ItemIsEditable );
                ui->tableWidget->setItem( 0, 1, item );*/
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
