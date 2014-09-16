#include "mainwindow.h"
#include <QApplication>

#include <QMessageBox>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //w.size().setHeight(1600);
    //w.size().setWidth(1600);
    //w.showFullScreen();
    //w.show();
/*
    QPushButton *btn = new QPushButton("lol");
    //btn->resize(100, 100);
    btn->setText("Compute");
    btn->showFullScreen();
    */



    return a.exec();
}
