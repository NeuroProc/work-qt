#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QLibrary>
#include "draw.h"
#include "line.h"
#include "serial.h"

#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QAction *current;

private slots:
    void setCurrentAction(QAction *);
    void on_pushButton_clicked();
    void on_actionSave_triggered();

    void on_actionOpen_triggered();

    void on_actionLoad_triggered();

private:
    Ui::MainWindow *ui;
    QPaintWidget *wgt;
};

#endif // MAINWINDOW_H
