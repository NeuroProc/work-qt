#include "graph.h"

Graph::Graph(QWidget *parent)
{
    // Создать поле со шкалами для отображения графика
    addPlot(parent);
    // Включить масштабную сетку
    addPlotGrid();
    // Кривая
    addCurve();
    // Включить возможность приближения/удаления графика
    enableMagnifier();
    // Включить возможность перемещения по графику
    enableMovingOnPlot();
    // Включить отображение координат курсора и двух перпендикулярных
    // линий в месте его отображения
    enablePicker();
}

Graph::~Graph()
{
    delete d_plot;
    delete curve;
}

void Graph::addPlot(QWidget *obj)
{
    // #include <qwt_plot.h>
    d_plot = new QwtPlot( obj );

    d_plot->setTitle( "Data view" );
    d_plot->setCanvasBackground( Qt::white );

    // Параметры осей координат
    d_plot->setAxisTitle(QwtPlot::yLeft, "Y");
    d_plot->setAxisTitle(QwtPlot::xBottom, "X");
    //d_plot->insertLegend( new QwtLegend() );

}

void Graph::addPlotGrid()
{
    // #include <qwt_plot_grid.h>
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setMajorPen(QPen( Qt::gray, 1 )); // цвет линий и толщина
    grid->attach( d_plot );
}

void Graph::addCurve()
{
    //#include <qwt_plot_curve.h>
    curve = new QwtPlotCurve();
    curve->setTitle( "Curve" );
    curve->setPen( Qt::blue, 2, Qt::SolidLine ); // цвет и толщина кривой

    // Маркеры кривой
    // #include <qwt_symbol.h>
    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::yellow ), QPen( Qt::red, 2, Qt::SolidLine ), QSize( 4, 4 ) );
    //curve->setSymbol( symbol );
}

void Graph::update()
{
    curve->setSamples( points ); // ассоциировать набор точек с кривой
    curve->attach( d_plot ); // отобразить кривую на графике
    d_plot->replot();
}

void Graph::enableMagnifier()
{
    // #include <qwt_plot_magnifier.h>
    QwtPlotMagnifier *magnifier =
            new QwtPlotMagnifier(d_plot->canvas());
    // клавиша, активирующая приближение/удаление
    magnifier->setMouseButton(Qt::MidButton);
}

void Graph::enableMovingOnPlot()
{
    // #include <qwt_plot_panner.h>
    QwtPlotPanner *d_panner = new QwtPlotPanner( d_plot->canvas() );
    // клавиша, активирующая перемещение
    d_panner->setMouseButton( Qt::RightButton );
}

void Graph::enablePicker()
{
    // #include <qwt_plot_picker.h>
    // настройка функций
    QwtPlotPicker *d_picker =
            new QwtPlotPicker(
                QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
    QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
    QwtPicker::AlwaysOn, // всегда включен
    d_plot->canvas() ); // ассоциация с полем

    // Цвет перпендикулярных линий
    d_picker->setRubberBandPen( QColor( Qt::red ) );

    // цвет координат положения указателя
    d_picker->setTrackerPen( QColor( Qt::black ) );

    // непосредственное включение вышеописанных функций
    d_picker->setStateMachine( new QwtPickerDragPointMachine() );
}
