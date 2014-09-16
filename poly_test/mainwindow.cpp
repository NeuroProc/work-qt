#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//////////////////////////////////
void A::foo()
{
    QMessageBox msg;

    msg.setText("A::foo()");
    msg.exec();
}

void B::foo()
{
    QMessageBox msg;

    msg.setText("B::foo()");
    msg.exec();
}
//////////////////////////////////

void MainWindow::on_pushButton_clicked()
{
    QMessageBox msg;
    QString str;



    msg.setText("lol");
    msg.exec();
}
