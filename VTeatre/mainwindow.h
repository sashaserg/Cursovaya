#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
#include <QMainWindow>
#include <QDate>
#include <QPixmap>
#include <QGraphicsScene>
#include "about.h"
#include "windowbuyer.h"
#include "vector"
#include "string"
#include <QtDebug>
#include <QFileInfo>
#include <QTableView>
#include "statistic.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QDateTime dt; // переменная для записи текущей даты
    int row_height; // высота строки
    int column_width; // ширина столбца
    int quantity_prodactions=0;//запоминает выбраную строку
    int mesto[117][2];//запоминаю столбик и строчку
    int index_mesta=0;//индекс количества выбраных мест

private slots:
    void on_informationAbout_triggered();

    void on_action_triggered();

    void on_tableWidget_cellClicked(int row, int column);

    void on_comboBox_currentIndexChanged(int index);

    void on_tableSeans_cellClicked(int row, int column);

    void on_dateEdit_dateChanged(const QDate &date);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_action_exit_triggered();

    void on_action_statistic_sale_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    void places_fill();
    void cleasing_places();

};

#endif // MAINWINDOW_H
