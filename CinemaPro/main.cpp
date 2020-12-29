#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    Database db;
    db.createconnect();
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
