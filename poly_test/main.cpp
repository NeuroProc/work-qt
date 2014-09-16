#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    ////////////////////////////////
    A *ab = new A;
    A *bb = new B;

    ab->foo();
    bb->foo();
    ////////////////////////////////
    
    return a.exec();
}
