#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dt = QDateTime::currentDateTime(); //dateedit.DateTime выставляется в текущую дату
    ui->dateEdit->setDateTime(dt);
    ui->dateEdit->setMinimumDateTime(dt); // минимальная дата выставляется по текущей дате

    QGraphicsScene * scen = new QGraphicsScene();
    QPixmap * pix = new QPixmap();
    pix->load("1");
    scen->addPixmap(*pix);
    ui->graphicsView->setScene(scen);

    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // прячу вертикальный скрол бар

   /* this->setStyleSheet( "QTableWidget { gridline-color: green; }" );
    this->setStyleSheet( "QTableWidget { border-collapse: separate; }" );
    this->setStyleSheet( "QTableWidget { border-spacing: 7px 11px; }" );
    ui->tableWidget->setStyleSheet("border-collapse: separate;"
                                   "border-spacing: 7px 11px;");*/
}



MainWindow::~MainWindow()
{
    delete ui;
}
