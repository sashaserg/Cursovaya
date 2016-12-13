#ifndef FINALYWINDOW_H
#define FINALYWINDOW_H

#include <QDialog>

namespace Ui {
class FinalyWindow;
}

class FinalyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FinalyWindow(bool Buy, QWidget *parent = 0);
    ~FinalyWindow();

private:
    Ui::FinalyWindow *ui;
    bool Buying; // если тру - покупаем, фолс - бронируем
};

#endif // FINALYWINDOW_H
