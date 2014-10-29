#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    crypt = new Crypter();

    current = ui->actionAES;
    connect(ui->menuCrypt, SIGNAL(triggered(QAction *)), this, SLOT(setCipher(QAction *)));
}

MainWindow::~MainWindow()
{
    delete crypt;
    delete ui;
}


void MainWindow::setCipher(QAction *action)
{
    current->setChecked(false);
    current = action;
    crypt->setCipher(action->text());

    qDebug() << action->text();
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit_2->setText(crypt->crypt(ui->textEdit->toPlainText(), QString("lol")));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit_2->setText(crypt->deCrypt(ui->textEdit->toPlainText(), QString("lol")));
}
