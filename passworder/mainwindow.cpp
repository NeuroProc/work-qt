#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dataBase = "base.dat";

    crypt = new Crypter();
    parse = new Parser(dataBase);

    if (!QFile::exists(dataBase))
        registration();
    else
        login();

    current = ui->actionAES;
    connect(ui->menuCrypt, SIGNAL(triggered(QAction *)), this, SLOT(setCipher(QAction *)));
}

MainWindow::~MainWindow()
{
    delete crypt;
    delete parse;
    delete ui;
}

void MainWindow::registration()
{
    LoginDialog reg(this);

    if (reg.exec())
    {
        sessionKey = reg.getAnswer();
        qDebug() << sessionKey;
    } else {
        qDebug() << "EE: dialog failure!";
        exit(0);
    }

    parse->initialize("passworder");
    parse->createElement("passphrase", crypt->md5(crypt->md5(sessionKey)));
}

void MainWindow::login()
{
    LoginDialog log(this, "lol");

    if (log.exec())
    {
        sessionKey = log.getAnswer();
        qDebug() << sessionKey;
    } else {
        qDebug() << "EE: dialog failure!";
        exit(0);
    }

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
    qDebug() << crypt->md5(QString("lol"));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit_2->setText(crypt->deCrypt(ui->textEdit->toPlainText(), QString("lol")));
}
