#ifndef WINDOWBUYER_H
#define WINDOWBUYER_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class WindowBuyer;
}

class WindowBuyer : public QDialog
{
    Q_OBJECT

    
public:
    explicit WindowBuyer(QWidget *parent = 0);
    ~WindowBuyer();
    
private:
    Ui::WindowBuyer *ui;
};

#endif // WINDOWBUYER_H
