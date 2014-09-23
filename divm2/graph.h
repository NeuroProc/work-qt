#ifndef GRAPH_H
#define GRAPH_H

/*  QWT6  */
#include <qwt6/qwt_plot.h>
#include <qwt6/qwt_plot_grid.h>

#include <qwt6/qwt_legend.h>

#include <qwt6/qwt_plot_curve.h>
#include <qwt6/qwt_symbol.h>

#include <qwt6/qwt_plot_magnifier.h>

#include <qwt6/qwt_plot_panner.h>

#include <qwt6/qwt_plot_picker.h>
#include <qwt6/qwt_picker_machine.h>


class Graph
{
public:
    Graph(QWidget *parent = 0);
    ~Graph();

    void update();
    void setCurveColor(Qt::GlobalColor);

    QPolygonF points;
    QwtPlot *d_plot;

private:

    void addPlot(QWidget *);
    void addPlotGrid();
    void addCurve();
    void enableMagnifier();
    void enableMovingOnPlot();
    void enablePicker();

    QwtPlotCurve *curve;
};

#endif // GRAPH_H
