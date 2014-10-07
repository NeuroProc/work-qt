#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qsrand(QTime::currentTime().msec());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int numP, numC;
    QMessageBox a;

    try
    {
        numP = ui->lineEdit_2->text().toInt();
        numC = ui->lineEdit_3->text().toInt();

    }
    catch (...)
    {
        return;
    }

    //if (numP < 0 || numC < 0)
    //    return;

    qDebug() << numP << ":" << numC;

    dr = new Draw(width(), height(), this);
    obj = new Classifier(numP, numC, this, dr);


    obj->setRandomCore();
    obj->classify();
    delay(1);

    int newCore;
    while (obj->maximin(&newCore) > (obj->getAverageDistance() / 2))
    {
        obj->pushCore(newCore);

        dr->eraseImage();
        obj->classify();
        delay(1);
    }

    obj->drawCores();
    qDebug() << "maximin has ended!";
    dr->wgt->update();
    delay(5);

    a.setText("MAXIMIN HAS FINISHED. run Kmeans?");
    a.exec();

    delay(5);

    while (obj->reCompute())
    {
        dr->eraseImage();
        obj->classify();
        delay(1);
        qDebug("REDRAW!");

        obj->drawCores();
        dr->wgt->update();
        delay(1);

    }
    qDebug("FINISH!");

    a.setText("FINISHED");
    a.exec();

}

void MainWindow::delay(int N)
{
    //QTime dieTime= QTime::currentTime().addSecs(N);
    QTime dieTime= QTime::currentTime().addMSecs(N);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


