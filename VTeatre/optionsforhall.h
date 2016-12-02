#ifndef OPTIONSFORHALL_H
#define OPTIONSFORHALL_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QTableView>
namespace Ui {
class OptionsForHall;
}

class OptionsForHall : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsForHall(QWidget *parent = 0);
    ~OptionsForHall();
    int CountRow;
    int CountColumn;
    int TypeOfPlace; // 1 - Партер 2 - Бенуар 3 - Бельэтаж
    int Array[3][2];
private slots:
    void on_spinBox_Row_valueChanged(int arg1);

    void on_spinBox_Column_valueChanged(int arg1);

    void on_ComboBoxType_currentIndexChanged(int index);

    void on_pushButtonOK_clicked();

private:
    Ui::OptionsForHall *ui;
    QSqlDatabase mydb;
    void DrawTable();
};

#endif // OPTIONSFORHALL_H
