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
}

MainWindow::~MainWindow()
{
    delete ui;
}
