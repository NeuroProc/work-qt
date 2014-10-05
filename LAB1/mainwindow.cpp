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

    QLibrary lib;
    lib.metaObject()->className();
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

    QFile stream(QFileDialog::getSaveFileName(this, "Save file", "", ""));
    Serializer seria;

    stream.open(QIODevice::WriteOnly);
    foreach(Shape *s, wgt->mylist)
    {
        seria.serialize(s);
    }
    seria.save(&stream);
    stream.close();

}

void MainWindow::on_actionOpen_triggered()
{
    QFile stream(QFileDialog::getOpenFileName(this, "Open file", "", ""));
    Serializer seria;

    stream.open(QIODevice::ReadOnly);
    QDomDocument doc;

    doc.setContent(&stream);
    QDomNodeList nList = doc.documentElement().childNodes();

    for (int i = 0; i < nList.count(); i++)
    {
        Shape *tmp = NULL;

        if (!seria._deserialize(nList.item(i).toElement(), (QObject **)&tmp))
            continue;

        tmp->initDefault();
        wgt->mylist.push_back(tmp);
    }
    stream.close();

    wgt->update();
}

void MainWindow::on_actionLoad_triggered()
{
    QLibrary lib(QFileDialog::getOpenFileName(this, "Open file", "", ""));

    if (!lib.load())
        qDebug() << lib.errorString();

    typedef int (*myid)();
    myid avg = (myid)lib.resolve("getId");
    if (avg)
        qDebug() << avg();
    else
        qDebug() << lib.errorString();

    ui->menuDraw->addAction(QMetaType::typeName(avg()));


}
