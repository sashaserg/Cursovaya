#ifndef OPTIONSFORHALL_H
#define OPTIONSFORHALL_H

#include <QDialog>
#include <QtDebug>
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
private slots:
    void on_spinBox_Row_valueChanged(int arg1);

    void on_spinBox_Column_valueChanged(int arg1);

    void on_ComboBoxType_currentIndexChanged(int index);

private:
    Ui::OptionsForHall *ui;
    void DrawTable();
};

#endif // OPTIONSFORHALL_H
