#include "mainwindow.h"
#include "ui_mainwindow.h"


//#include <QMetaClassInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();


    //shape *s = new shape();
    //s->setParent(this);
   Shape *l = new Line(QPoint(0,0));
    //l->setParent(this);

    qDebug() << QMetaType::type("Line");
    qDebug() << Line::id;
    qDebug() << Line::staticMetaObject.superClass()->className();
    //qDebug() << l->parent();
/*
    QObjectList a = QWidget::children();

    for (int i = 0; i < a.size(); i++)
        qDebug() << a[i];
    qDebug() << "END";

*/

    wgt = new QPaintWidget(this);
    setCentralWidget(wgt);

    current = ui->actionLine;
    wgt->current = 'L';

    //wgt->mylist.push_back(new ellipse(500, 500, 300, 200));
    //wgt->mylist.push_back(new line(0, 0, 800, 800));
    //wgt->mylist.push_back(new rectangle(50,50, 500,500));

    //shape *l = new line(QPoint(0,0));
  
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
    else
    {
        //newAction->setChecked(true);
        return false;
    }
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
