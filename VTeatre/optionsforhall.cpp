#include "optionsforhall.h"
#include "ui_optionsforhall.h"
#include <QtXml>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

OptionsForHall::OptionsForHall(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionsForHall)
{
    ui->setupUi(this);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //запрет редактирования всех ячеек в таблице tableWidget
    QString path = qApp->applicationDirPath() + "/Data.json";
    QString jsonFileName = "./Data.json";

    QString jsonText;
    QFile jsonFile(jsonFileName);

    try{
        if(jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)){
            jsonText = jsonFile.readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonText.toUtf8());
            parseJSON(jsonDoc);
            jsonFile.close();
        }
        else{
            throw "Error opening JSON file.";
        }
    }
    catch(const char*msg){
        QMessageBox::critical(this, "Ошибка", msg);
    }
}

OptionsForHall::~OptionsForHall()
{
    delete ui;
}

void OptionsForHall::on_spinBox_Row_valueChanged(int arg1)//при изменении количества рядов
{
    int temp = ui->ComboBoxType->currentIndex();
    dataJsonFile[temp][0]=arg1;
    DrawTable();
}

void OptionsForHall::on_spinBox_Column_valueChanged(int arg1)//при изменении количества мест в ряду
{
    int temp = ui->ComboBoxType->currentIndex();
    dataJsonFile[temp][1]=arg1;
    DrawTable();
}

void OptionsForHall::DrawTable()
{
    QTableWidgetItem *item;
    int temp = ui->ComboBoxType->currentIndex();
    ui->tableWidget->setRowCount(dataJsonFile[temp][0]);             //задаю таблице нужное количечство строк
    ui->tableWidget->setColumnCount(dataJsonFile[temp][1]);       //и столбцов

    for(int i=0; i < dataJsonFile[temp][0]; i++){                    //освобождаю для них память
        for(int j=0; j < dataJsonFile[temp][1]; j++){
            ui->tableWidget->setItem(i, j, new QTableWidgetItem);
        }
    }

    int row_height = (ui->tableWidget->height() - 10) / ui->tableWidget->rowCount();       //подсчитываю высоту строк
    int column_width = (ui->tableWidget->width() - 35) / ui->tableWidget->columnCount();   //и ширину столбцов

    if(row_height > 100)                                //задаю максимальные значения для высоты и ширины ячеек
        row_height = 100;
    if(column_width > 200)
        column_width = 200;

    QPixmap pix1;                                       //храню пиксмап с изображением зеленого овала
    pix1.load(":/image/image.png");
    pix1 = pix1.scaled(column_width, row_height);       //устанавливаю для него нужный размер

    for(int i = 0; i < ui->tableWidget->rowCount();i++)
    {
        ui->tableWidget->setRowHeight(i, row_height);   // высота строк
        for(int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            if(i == 0)
                ui->tableWidget->setColumnWidth(j, column_width);       // ширина столбцов
            item = new QTableWidgetItem;
            item->setBackground(QBrush(pix1));
            item->setText(QString::number(j + 1));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(item->flags() & (~Qt::ItemIsSelectable));    // устанавливаю флаг ItemIsSelectable в false
            item->setToolTip("Ряд " + QString::number(i+1));
            ui->tableWidget->setItem( i, j, item );     //вставляю в ячейку созданный Item
        }
    }
    ui->tableWidget->verticalHeader()->setFixedWidth(25);         // размер хидера
    ui->tableWidget->verticalHeader()->setStyleSheet("border-style: solid;"             // стиль для хидера
                                                     "border-width: 1px;"
                                                     "border-color: black;"
                                                     "border-radius: 0px;"
                                                     "color: black;");
    ui->tableWidget->setStyleSheet("QTableWidget{"                                      // стиль для таблицы и tooltip-a
                                   "border-style: solid;"
                                   "border-width: 5px;"
                                   "border-radius: 1px;"
                                   "border-color: #d3bb9c;"
                                   "}"
                                   "QTableWidget QToolTip{"
                                   "color:red;"
                                   "border-style: solid;"
                                   "border-width: 1px;"
                                   "border-color: green;"
                                   "border-radius: 0px;"
                                   "}");
}
void OptionsForHall::parseJSON(QJsonDocument& jsonDoc)
{
    QJsonObject jsonObject = jsonDoc.object();
    QJsonArray optionsArray = jsonObject["options"].toArray();

    for(int i=0; i<3; i++)
    {
        dataJsonFile[i][0] = optionsArray[i].toObject()["row"].toDouble();
        dataJsonFile[i][1] = optionsArray[i].toObject()["column"].toDouble();
        type_placeJsonFile[i] = optionsArray[i].toObject()["type_place"].toString();
    }
    int temp = ui->ComboBoxType->currentIndex();
    ui->spinBox_Row->setValue(dataJsonFile[temp][0]);
    ui->spinBox_Column->setValue(dataJsonFile[temp][1]);
}

void OptionsForHall::on_ComboBoxType_currentIndexChanged(int index)
{
    ui->spinBox_Row->setValue(dataJsonFile[index][0]);
    ui->spinBox_Column->setValue(dataJsonFile[index][1]);
}

void OptionsForHall::on_pushButtonOK_clicked()          //при нажатии на "ОК" изменяю БД
{
    QString path = qApp->applicationDirPath() + "./Data.json";
    QString jsonFileName = "./Data.json";
    if(jsonFileName != NULL)
    {
            QFile jsonFile(jsonFileName);

            if(jsonFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
            {
                QJsonObject json, json1;
                QJsonArray data;
                for(int i = 0; i < 3; i++)
                {
                json1["row"]=dataJsonFile[i][0];
                json1["column"]=dataJsonFile[i][1];
                json1["type_place"]=type_placeJsonFile[i];
                data.append(json1);
                }
                json["options"]=data;
                QJsonDocument saveDoc(json);
                jsonFile.write(saveDoc.toJson());
                jsonFile.close();
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Error");
                msgBox.setText("Error writing JSON file.");
                msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
                msgBox.exec();
            }
    }
}

void OptionsForHall::on_pushButtonCancel_clicked()
{

}
