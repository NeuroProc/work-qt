#include "mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->showFullScreen();

    QMessageBox msg;
    msg.setText(QString("window: %1:%2").arg(this->size().width()).arg(this->size().height()));
    //msg.showFullScreen();
    msg.exec();

}

MainWindow::~MainWindow()
{
    
}
