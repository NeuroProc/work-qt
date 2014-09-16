#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};


//////////////////////////////////////

class A
{
public:
    virtual void foo();
};

class B : public A
{
public:
    void foo();
};

////////////////////////////////////

#endif // MAINWINDOW_H
