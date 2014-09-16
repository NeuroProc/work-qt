#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void incMatrix();
    int getMatrix(float ***, int *);
    void printMatrix(float **, int);
    void computeGauss();
    void exchange(float **, int, int, int);
    int getNoEmpty(float **, int, int);
    void computeHoleckii();
    float* holeckii(float **, int);
    int check(float **, int);
    
private slots:
    void on_pushButton_clicked();
    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
