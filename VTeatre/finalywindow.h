#ifndef FINALYWINDOW_H
#define FINALYWINDOW_H

#include <QDialog>
#include <scene.h>
namespace Ui {
class FinalyWindow;
}

class FinalyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FinalyWindow(std::vector <short> SelectedPlacesRow, std::vector <short> SelectedPlacesCol, Scene *CurScene, QString CurHoll, int CurIndex, bool *verification, QWidget *parent = 0);
    ~FinalyWindow();

private slots:
    void on_pushButtonOk_clicked();

private:
    Ui::FinalyWindow *ui;
    void CreateTable(std::vector <short> SelectedPlacesRow, std::vector <short> SelectedPlacesCol, Scene *CurScene, QString CurHoll, int CurIndex);
    double Cost;
    bool *verific;
};

#endif // FINALYWINDOW_H
