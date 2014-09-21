#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();

    rowCount = 20;
    step = 0.1;

    gr = new Graph(this);
    ui->horizontalLayout->addWidget(gr->d_plot);
    ui->tableWidget->setRowCount(rowCount);

    values << QPointF(1, 2.02) << QPointF(2, 1.98) << QPointF(3, 1.67) << QPointF(4, 1.65) << QPointF(5, 1.57) << QPointF(6, 1.42) << QPointF(7, 1.37) <<
                  QPointF(8, 1.07) << QPointF(9, 0.85) << QPointF(10, 0.48) << QPointF(11, 0.35) << QPointF(12, -0.30) << QPointF(13, -0.61) << QPointF(14, -1.20) <<
                  QPointF(15, -1.39) << QPointF(16, -1.76) << QPointF(17, -2.28) << QPointF(18, -2.81) << QPointF(19, -3.57) << QPointF(20, -4.06);


    for (int i = 0; i < rowCount; i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem( QString("%1").arg( values[i].x() )));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem( QString("%1").arg( values[i].y() )));
    }

/*
    int i = 0;
    for (float x = -5; x < 5; x += 0.1, i++)
    {
        gr->points << QPointF(x, sin(x));
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem( QString("%1").arg(x) ));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem( QString("%1").arg( sin(x) ) ));
    }
*/



    //gr->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    gr->points.clear();

    for (float x = 1; x <= rowCount; x += step)
    {
        gr->points << QPointF(x, Lagrange::interpolate(x, values, rowCount));
    }

    gr->update();
}

void MainWindow::on_pushButton_2_clicked()
{
    gr->points.clear();

    for (float x = 1; x <= rowCount; x += step)
    {
        gr->points << QPointF(x, Newton::interpolate(x, values, rowCount));
    }

    gr->update();

}
