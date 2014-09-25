#include "mainwindow.h"
#include "ui_mainwindow.h"


//#include <QMetaClassInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();

    wgt = new QPaintWidget(this);

    setCentralWidget(wgt);
    ui->frame->setParent(wgt);

    current = ui->actionLine;
    wgt->current = "Line";

    connect(ui->menuDraw, SIGNAL(triggered(QAction*)), this, SLOT(setCurrentAction(QAction*)));
}

MainWindow::~MainWindow()
{
    wgt->deleteLater();
    delete ui;
}

void MainWindow::setCurrentAction(QAction *newAction)
{
    qDebug() << newAction->text();


    current->setChecked(false);
    newAction->setChecked(true);
    current = newAction;

    wgt->current = current->text();
}

void MainWindow::on_pushButton_clicked()
{
    Shape::extraNum = ui->lineEdit->text().toInt();
}

void MainWindow::on_actionSave_triggered()
{
    QVector<QString> stream;

    //stream << "LOL";
    foreach(Shape *s, wgt->mylist)
    {
        stream.push_back(s->Serialize());
    }

    foreach(QString a, stream)
        qDebug() << a;

}
