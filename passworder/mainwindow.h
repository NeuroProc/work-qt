#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "crypter.h"
#include "parser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void registration();
    void login();

private slots:
    void setCipher(QAction *action);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public:
    Crypter *crypt;
    Parser *parse;

private:
    Ui::MainWindow *ui;
    QAction *current;
    QString dataBase;
    QString sessionKey;
};

#endif // MAINWINDOW_H
