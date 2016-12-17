#ifndef OPTIONSFORHALL_H
#define OPTIONSFORHALL_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QTableView>
#include <QtXml>

namespace Ui {
class OptionsForHall;
}

class OptionsForHall : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsForHall(QWidget *parent = 0);
    ~OptionsForHall();
    double dataJsonFile[3][2];
    QString type_placeJsonFile[3];
    /*int CountRow;
    int CountColumn;
    int TypeOfPlace; // 1 - Партер 2 - Бенуар 3 - Бельэтаж
    int Array[3][2];*/
private slots:
    void on_spinBox_Row_valueChanged(int arg1);

    void on_spinBox_Column_valueChanged(int arg1); 

    void on_ComboBoxType_currentIndexChanged(int index);

    void on_pushButtonOK_clicked();

    void on_pushButtonCancel_clicked();

private:
    void parseJSON(QJsonDocument& jsonDoc);
    Ui::OptionsForHall *ui;
    QSqlDatabase mydb;
    void DrawTable();
};

#endif // OPTIONSFORHALL_H
