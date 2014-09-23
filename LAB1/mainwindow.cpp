#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();

    wgt = new QPaintWidget(this);
    setCentralWidget(wgt);

    current = ui->actionLine;
    wgt->current = 'L';

    //wgt->show();
    //wgt->mousePressEvent();


    //qDebug() << "MAIN:" << width() << ":" << height();
    //qDebug() << "WGT:" << wgt->width() << ":" << wgt->height();
    //qDebug() << "CUST" << ui->centralWidget->width() << ":" << ui->centralWidget->height();

    //wgt->mylist.push_back(new ellipse(500, 500, 300, 200));
    //wgt->mylist.push_back(new line(0, 0, 800, 800));
    //wgt->mylist.push_back(new rectangle(50,50, 500,500));
  
}

MainWindow::~MainWindow()
{
    wgt->deleteLater();
    delete ui;
}

bool MainWindow::setCurrentAction(QAction *newAction)
{
    if (current != newAction)
    {
        current->setChecked(false);
        newAction->setChecked(true);
        current = newAction;

        return true;
    }
    return false;
}


void MainWindow::on_actionLine_changed()
{
    if (setCurrentAction(ui->actionLine))
        wgt->current = 'L';
}

void MainWindow::on_actionRect_changed()
{
    if (setCurrentAction(ui->actionRect))
        wgt->current = 'R';
}

void MainWindow::on_actionEllipse_changed()
{
    if (setCurrentAction(ui->actionEllipse))
        wgt->current = 'E';
}
