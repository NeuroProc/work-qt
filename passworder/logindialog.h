#ifndef REGDIALOG_H
#define REGDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginDialog(QWidget *parent = 0, QString hash = "");
    ~LoginDialog();

    QString getAnswer();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginDialog *ui;
    QString answer;
    QString _hash;
};

#endif // REGDIALOG_H
