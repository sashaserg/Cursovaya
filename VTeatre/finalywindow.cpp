#include "finalywindow.h"
#include "ui_finalywindow.h"

FinalyWindow::FinalyWindow(std::vector <short> SelectedPlacesRow, std::vector <short> SelectedPlacesCol, Scene *CurScene, QString CurHoll, int CurIndex, bool *verification, QWidget *parent) :         // конструктор с 2 параметрами
    QDialog(parent),
    ui(new Ui::FinalyWindow)
{
    ui->setupUi(this);
    verific = verification;
    Cost = 0;
    CreateTable(SelectedPlacesRow, SelectedPlacesCol, CurScene, CurHoll, CurIndex);
    ui->labelCost->setText("К оплате: " + QString::number(Cost) + "грн.");
    qDebug()<<verific;
}

FinalyWindow::~FinalyWindow()
{
    delete ui;
}

void FinalyWindow::CreateTable(std::vector <short> SelectedPlacesRow, std::vector <short> SelectedPlacesCol, Scene *CurScene, QString CurHoll, int CurIndex){
    ui->tableWidget->setRowCount(SelectedPlacesRow.size());

    for(int i = 0; i < SelectedPlacesRow.size(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem);
        }
    }

    for(int i = 0; i < SelectedPlacesRow.size(); i++){
        ui->tableWidget->item(i, 0)->setText(CurScene->name);
        ui->tableWidget->item(i, 1)->setText(CurHoll);
        ui->tableWidget->item(i, 2)->setText(CurScene->date);
        ui->tableWidget->item(i, 3)->setText(CurScene->time);
        ui->tableWidget->item(i, 4)->setText(QString::number(SelectedPlacesRow[i] + 1));
        ui->tableWidget->item(i, 5)->setText(QString::number(SelectedPlacesCol[i] + 1));
        ui->tableWidget->item(i, 6)->setText(QString::number(CurScene->Cost[CurIndex]));
        Cost += CurScene->Cost[CurIndex];
    }
}

void FinalyWindow::on_pushButtonOk_clicked()
{
    qDebug()<<verific;
    *verific = true;
    this->close();
    qDebug()<<verific;
}
