#include "mainwindow.h"
#include <QApplication>
#include <String>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    string str;
    getline(cin, str);
    cout << "Size of str: " << str;

   return a.exec();
}
