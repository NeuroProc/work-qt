#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "draw.h"
#include "line.h"


#include <qjson/parser.h>
#include <qjson/serializer.h>
#include <qjson/qobjecthelper.h>
#include <qjson/qjson_export.h>
#include <qjson/serializerrunnable.h>

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

private:
    Ui::MainWindow *ui;
    QPaintWidget *wgt;
};

#endif // MAINWINDOW_H
