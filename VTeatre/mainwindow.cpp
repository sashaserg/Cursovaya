#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    pix->load("1");
    scen->addPixmap(*pix);
    ui->graphicsView->setScene(scen);
    pix = new QPixmap();
    pix->load("scena");
    scen = new QGraphicsScene();
    scen->addPixmap(*pix);
    ui->label_2->setPixmap(*pix);

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

void MainWindow::on_informationAbout_triggered()
{
    About *window = new About(this);
    window->show();
}
