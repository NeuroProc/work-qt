#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "draw.h"
#include "line.h"
#include "rectangle.h"
#include "ellipse.h"

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

    bool setCurrentAction(QAction *);
    QAction *current;

private slots:
    void on_actionLine_changed();
    void on_actionRect_changed();
    void on_actionEllipse_changed();

private:
    Ui::MainWindow *ui;
    QPaintWidget *wgt;
};

#endif // MAINWINDOW_H
