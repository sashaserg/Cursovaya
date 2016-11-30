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
#include "optionsforhall.h"

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
    int count_places=0;//индекс количества выбраных мест
    unsigned int count_place_purchased = 0;//счетчик купленых мест
    int count_places_all =0;//всего мест
    int count_place_free = 0;//счетчик свободных
    bool is_Already = false;//переменная для проверки наличия выбраного места в массиве mesto[][]

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

    void on_pushButton_3_clicked();

    void on_options_room_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    void places_fill();
    void cleasing_places();
    void create_a_MainTable();
    void places_overwrite(int i);//если место которое раньше бронировали или покупали попробуют купить опять то эта фция перезапишет старую запись
};

#endif // MAINWINDOW_H
