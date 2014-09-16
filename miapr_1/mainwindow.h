#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "classifier.h"
#include <QTime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Draw *dr;
    QPaintWidget *wgt;
    void delay(int);
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Classifier *obj;

};

#endif // MAINWINDOW_H
