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
    pix = new QPixmap();
    pix->load("scena");
    scen = new QGraphicsScene();
    scen->addPixmap(*pix);
    ui->label_2->setPixmap(*pix);

    QString fileName = "1";
    QPixmap pix1;
            if( pix1.load( fileName ) ) {
                pix1.scaled(QSize(200,200));
                QTableWidgetItem* item = new QTableWidgetItem( QFileInfo( fileName ).baseName() );

                item->setData( Qt::DecorationRole, pix1 );
                item->setFlags( item->flags() ^ Qt::ItemIsEditable );
              /*  ui->tableWidget->setItem( 0, 1, item );
                ui->tableWidget->setRowHeight( 0, 200 );
                ui->tableWidget->setColumnWidth(1, 200);*/


               /* QTableWidgetItem *ptw = new QTableWidgetItem;
                ptw->setBackground( QBrush( QPixmap( "1" ) ) );
                ui->tableWidget->setItem(0,0,ptw);*/
            }
   // ui->tableWidget->item(0,0)->setIcon(QIcon("1.jpg"));



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
