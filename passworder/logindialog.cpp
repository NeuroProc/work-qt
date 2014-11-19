#include "logindialog.h"
#include "ui_logindialog.h"

#include "crypter.h"

LoginDialog::LoginDialog(QWidget *parent, QString hash) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    answer.clear();
    ui->label_2->hide();
    _hash = hash;


    if (hash.isEmpty())
    {
        ui->label_3->setText("This is first launch.\nSet the passphrase.");
        ui->label_2->setText("passphrase shouldn't be less than 6 symbols!");
    } else {
        ui->label_3->setText("Welcome. Again.\nEnter the passphrase.");
        ui->label_2->setText("passphrase is incorrect!");
    }


}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QString LoginDialog::getAnswer()
{
    return answer;
}

void LoginDialog::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();

    if (text.isEmpty() || text.length() < 6)
    {
        ui->label_2->show();
        return;
    }

    if (!_hash.isEmpty() && Crypter::md5(Crypter::md5(text)) != _hash)
    {
        ui->label_2->show();
        return;
    }

    answer = text;
    accept();
}
