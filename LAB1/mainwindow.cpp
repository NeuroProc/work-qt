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
    QFile stream("lol.xml");
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
    QFile stream("lol.xml");
    Serializer seria;

    stream.open(QIODevice::ReadOnly);
    QDomDocument doc;

    doc.setContent(&stream);
    QDomNodeList nList = doc.documentElement().childNodes();

    for (int i = 0; i < nList.count(); i++)
    {
        Shape *tmp = NULL;

        qDebug() << "TEST:" << nList.item(i).childNodes().count();
        seria._deserialize(nList.item(i).toElement(), (QObject **)&tmp);
        tmp->initDefault();

        wgt->mylist.push_back(tmp);
    }
    stream.close();

    wgt->update();
}
