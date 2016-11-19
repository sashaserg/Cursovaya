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

private slots:
    void on_informationAbout_triggered();

    void on_action_triggered();

    void on_tableWidget_cellClicked(int row, int column);

    void on_comboBox_currentIndexChanged(int index);

    void on_tableSeans_cellClicked(int row, int column);

    void on_dateEdit_dateChanged(const QDate &date);

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
};

#endif // MAINWINDOW_H
