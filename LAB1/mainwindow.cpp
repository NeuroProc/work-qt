#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showFullScreen();


    wgt = new QPaintWidget(this);
    wgt->resize(width(), height());
    wgt->show();


    qDebug() << "MAIN:" << width() << ":" << height();
    qDebug() << "WGT:" << wgt->width() << ":" << wgt->height();
    qDebug() << "CUST" << ui->centralWidget->width() << ":" << ui->centralWidget->height();


/*
    shape *a = new line(20, 50, 500, 50);
    QPaintWidget::current = a;

    shape *b = new rectangle(20, 60, 500, 120);
    QPaintWidget::current = b;
*/
    //shape *c = new ellipse(100, 100, 30, 20);

    wgt->mylist.push_back(new ellipse(500, 500, 300, 200));
    wgt->mylist.push_back(new line(0, 0, 800, 800));
    wgt->mylist.push_back(new rectangle(50,50, 500,500));

}

MainWindow::~MainWindow()
{
    wgt->deleteLater();
    delete ui;
}

