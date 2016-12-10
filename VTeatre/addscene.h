#ifndef ADDSCENE_H
#define ADDSCENE_H

#include <QDialog>
#include <QtSql>
#include <QList>
#include <scene.h>
namespace Ui {
class AddScene;
}

class AddScene : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddScene(QWidget *parent = 0);
    explicit AddScene(Scene *temp, QWidget *parent = 0);
    ~AddScene();
    QList <Scene> Scenes;
private slots:
    void on_ButtonAdd_clicked();

private:
    Ui::AddScene *ui;
    QSqlDatabase mydb;
};

#endif // ADDSCENE_H
