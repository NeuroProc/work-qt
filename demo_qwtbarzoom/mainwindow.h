#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <qwt6/qwt_plot_canvas.h>
#include <qwt6/qwt_legend.h>
#include <qwt6/qwt_plot_grid.h>
#include <qwt6/qwt_plot_curve.h>
#include <qwt6/qwt_symbol.h>

#include <qwt6/qwt_plot.h>
#include <qwt6/qwt_plot_grid.h>

#include <qwt6/qwt_legend.h>

#include <qwt6/qwt_plot_curve.h>
#include <qwt6/qwt_symbol.h>

#include <qwt6/qwt_plot_magnifier.h>

#include <qwt6/qwt_plot_panner.h>

#include <qwt6/qwt_plot_picker.h>
#include <qwt6/qwt_picker_machine.h>

#include "scrollzoomer.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QwtLegend *leg;             // легенда
    QwtPlotGrid *grid;          // координатная сетка
    QwtPlotCurve *curv1,*curv2; // кривые, отображаемые на графике

    ScrollZoomer *zoom;         // менеджер масштабирования и перемещения графика
};

#endif // MAINWINDOW_H
