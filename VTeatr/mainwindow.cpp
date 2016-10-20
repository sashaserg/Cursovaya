#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene * scen = new QGraphicsScene();
    QPixmap * pix = new QPixmap();
    pix->load("teatr1.png");
    scen->addPixmap(*pix);
    ui->graphicsView->setScene(scen);
}

MainWindow::~MainWindow()
{
    delete ui;
}
