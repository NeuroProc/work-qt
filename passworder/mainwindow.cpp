#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QBitmap>

#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->widgetRight->setVisible(false);
    ui->labelHello->setVisible(true);

    dataBase = "base.dat";
    currentIndex = 0;
    ui->buttonSave->setVisible(false);
    ui->comboBoxAlg->setVisible(false);
    isAdd = false;

    //QPixmap maskDelete("recycle50.png");
    //ui->buttonDelete->setMask(maskDelete.mask());

    crypt = new Crypter();
    parse = new Parser(dataBase);

    if (!QFile::exists(dataBase))
        registration();
    else
        login();

    showPasswords();
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
        //qDebug() << sessionKey;
    } else {
        qDebug() << "EE: dialog failure!";
        exit(0);
    }

    parse->initialize("passworder");

    QDomElement passphrase = parse->createElement("passphrase");
    parse->createTextNode(crypt->md5(crypt->md5(sessionKey)), &passphrase);
    parse->save();
}

void MainWindow::login()
{
    LoginDialog log(this, parse->getElement("passphrase").text());

    if (log.exec())
    {
        sessionKey = log.getAnswer();
        //qDebug() << sessionKey;
    } else {
        qDebug() << "EE: dialog failure!";
        exit(0);
    }
}

void MainWindow::edit(bool state)
{
    ui->buttonSave->setVisible(state);
    ui->comboBoxAlg->setVisible(state);

    ui->editAlg->setVisible(!state);

    ui->editUsername->setReadOnly(!state);
    ui->editPassword->setReadOnly(!state);
    ui->editInfo->setReadOnly(!state);
    ui->editModify->setPlainText(QLocale("en_EN").toString(QDateTime::currentDateTime()));
}

void MainWindow::showPasswords()
{
    QDomElement elem;

    ui->listWidget->clear();

    for (int i = 0; !(elem = parse->getElement("password", i)).isNull(); i++) //get elements until NULL was returned
    {
        QDomNode name = elem.firstChild();

        crypt->setCipher(elem.lastChild().firstChild().nodeValue());

        QListWidgetItem *item = new QListWidgetItem();
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        item->setText(crypt->deCrypt(name.firstChild().nodeValue(), sessionKey));
        ui->listWidget->addItem(item);
    }
}

void MainWindow::on_buttonAdd_clicked()
{
    if (isAdd)
        return;

    ui->labelHello->setVisible(false);
    ui->widgetRight->setVisible(true);

    isAdd = true;

    QListWidgetItem *item = new QListWidgetItem();

    item->setFlags(item->flags() | Qt::ItemIsEditable);

    ui->listWidget->addItem(item);
    ui->listWidget->setCurrentItem(item);
    ui->listWidget->editItem(item);

    ui->editUsername->clear();
    ui->editPassword->clear();
    ui->editInfo->clear();

    edit(true);
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    ui->labelHello->setVisible(false);
    ui->widgetRight->setVisible(true);

    if (ui->buttonSave->isVisible()) //if editing/adding NOW reset changes
    {
        edit(false);
        showPasswords();
    }

    if (currentRow == -1)
        return;

    isAdd = false;
    currentIndex = currentRow;
    //qDebug() << currentRow;

    /* get info for current item */
    QDomElement current = parse->getElement("password", currentRow);   

    if (current.isNull())
        return;

    QDomNodeList nodes = current.childNodes();

    crypt->setCipher(nodes.at(5).firstChild().nodeValue());  //set ALG NAME to decrypt

    /* decrypt all data */
    ui->editUsername->setPlainText( crypt->deCrypt(nodes.at(1).firstChild().nodeValue(), sessionKey) );
    ui->editPassword->setPlainText( crypt->deCrypt(nodes.at(2).firstChild().nodeValue(), sessionKey) );
    ui->editInfo->setPlainText    ( crypt->deCrypt(nodes.at(3).firstChild().nodeValue(), sessionKey) );
    ui->editModify->setPlainText  ( crypt->deCrypt(nodes.at(4).firstChild().nodeValue(), sessionKey) );
    ui->editAlg->setPlainText     ( nodes.at(5).firstChild().nodeValue()                             );
}

void MainWindow::on_buttonSave_clicked()
{
    QDomElement newPassword;

    newPassword = parse->createElement("password");

    crypt->setCipher(ui->comboBoxAlg->currentText());  //set ALG NAME to crypt

    /* crypt and save data */
    QDomElement node;
    node = parse->createElement("name", &newPassword);
    parse->createTextNode( crypt->crypt(ui->listWidget->item(currentIndex)->text(), sessionKey), &node);

    node = parse->createElement("username", &newPassword);
    parse->createTextNode( crypt->crypt(ui->editUsername->toPlainText(), sessionKey), &node);

    node = parse->createElement("pass", &newPassword);
    parse->createTextNode( crypt->crypt(ui->editPassword->toPlainText(), sessionKey), &node);

    node = parse->createElement("info", &newPassword);
    parse->createTextNode( crypt->crypt(ui->editInfo->toPlainText(), sessionKey), &node);

    node = parse->createElement("lastmodify", &newPassword);
    parse->createTextNode( crypt->crypt(ui->editModify->toPlainText(), sessionKey), &node);

    node = parse->createElement("algorithm", &newPassword);
    parse->createTextNode( ui->comboBoxAlg->currentText(), &node);
    ui->editAlg->setPlainText(ui->comboBoxAlg->currentText());

    if (!isAdd)  //if not adding then replace exist item
    {
        QDomElement oldElement = parse->getElement("password", currentIndex);
        parse->replaceElement(newPassword, oldElement);
    }
    isAdd = false;

    parse->save();
    edit(false);
}

void MainWindow::on_buttonEdit_clicked()
{
    ui->listWidget->editItem(ui->listWidget->item(currentIndex));
    edit(true);
}

void MainWindow::on_buttonDelete_clicked()
{
    QDomElement oldElement = parse->getElement("password", currentIndex);
    parse->deteleElement(oldElement);
    parse->save();

    isAdd = false;
    showPasswords();
}
