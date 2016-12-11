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
#include "addscene.h"
#include "scene.h"
#include <vector>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Scene *CurScene;

    QDateTime dt; // переменная для записи текущей даты
    int row_height; // высота строки
    int column_width; // ширина столбца
    bool **coordinates_of_places;//запоминаю координаты столбика и строчки
    void coordinates_of_places_cleaning(int temp);
    //***ПЕРЕМЕННЫЕ ОТ САНИ***
    std::vector <short> SelectedPlacesRow;
    std::vector <short> SelectedPlacesCol;
    int PreviousIndex;
    int CountRow;               //Количество строк
    int CountColumn;            //Количество столбцов
    int CountPurchased;         //количество купленных
    int CountBooked;            //количество забронированных
    //***ВОТ НА ЭТОМ МОИ ПЕРЕМЕННЫЕ ВСЬО***

private slots:
    void on_informationAbout_triggered();

    void on_action_triggered();

    void on_tableWidget_cellClicked(int row, int column);

    void on_comboBox_currentIndexChanged(int index);

    void on_tableSeans_cellClicked(int row, int column);

    void on_dateEdit_dateChanged(const QDate &date);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_action_exit_triggered();

    void on_action_statistic_sale_triggered();

    void on_pushButton_3_clicked();

    void on_options_room_triggered();

    void on_action_addScene_triggered();

    void on_action_hovered();

    void on_tableSeans_customContextMenuRequested(const QPoint &pos);

    void slotEditRecord();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    void places_fill();//заполняет места
    void cleasing_places();//очищает места
    void create_a_MainTable();
    void places_overwrite(int row, int column);//удаляет дубликаты в базе
    void pix_close(int row, int column);//красит в красный
    void pix_checking(int row, int column);//красит в синий
    void pix_reserv(int row, int column);//красит в желтый
    void pix_standart(int row, int column);//красит в зелёный
    void customizeTableInf();

};


#endif // MAINWINDOW_H
