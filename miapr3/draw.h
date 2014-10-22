#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <qwt6/qwt_plot.h>
#include <qwt6/qwt_plot_curve.h>
#include <qwt6/qwt_plot_picker.h>
#include <qwt6/qwt_picker_machine.h>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>

class Draw : public QWidget {
  Q_OBJECT

private:
  QwtPlot *plot;
  QwtPlotCurve *c1Curve;
  QwtPlotCurve *c2Curve;
  QwtPlotCurve *line;
  QPushButton *doButton;
  QLineEdit *editC1;
  QLineEdit *editC2;
  QLineEdit *editFalse;
  QLineEdit *editMissError;
  QLineEdit *editSummary;
  QHBoxLayout *hlayout1;
  QHBoxLayout *hlayout2;
  QHBoxLayout *hlayout3;
  QHBoxLayout *hlayout4;
  QHBoxLayout *hlayout5;
  QLabel *c1;
  QLabel *c2;
  QLabel *editF;
  QLabel *editMiss;
  QLabel *editSum;
  QVBoxLayout *vlay;
public:
  Draw(QWidget *parent = 0);
  //~Draw();
public slots:
  void button_click();


};

#endif // DRAW_H
