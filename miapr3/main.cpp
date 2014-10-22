#include "mainwindow.h"
#include <QApplication>
#include "draw.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  //Draw w;
  w.show();

  return a.exec();
}
