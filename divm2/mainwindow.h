#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"
#include "lagrange.h"
#include "newton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Graph *gr;
    int rowCount;
    float step;
    
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void on_pushButton_4_clicked();

private:
    void updateTable();
    int getMaxX();

    Ui::MainWindow *ui;

    QPolygonF values;


};

#endif // MAINWINDOW_H
