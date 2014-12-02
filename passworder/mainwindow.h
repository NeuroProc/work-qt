#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

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
    void edit(bool state);
    void save();

    void showPasswords();

public:
    Crypter *crypt;
    Parser *parse;

private slots:
    void on_buttonAdd_clicked();
    void on_listWidget_currentRowChanged(int currentRow);
    void on_buttonSave_clicked();
    void on_buttonEdit_clicked();
    void on_buttonDelete_clicked();

private:
    Ui::MainWindow *ui;
    QString dataBase;
    QString sessionKey;
    int currentIndex;
    bool isAdd;

};

#endif // MAINWINDOW_H
