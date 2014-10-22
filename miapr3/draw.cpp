#include "draw.h"
#include <QTime>
#include <qmath.h>
#include <QMessageBox>

#define MAXPOINTS 10000

Draw::Draw(QWidget *parent)
{
  plot = new QwtPlot;
  doButton = new QPushButton;
  editC1 = new QLineEdit;
  editC2 = new QLineEdit;
  editFalse = new QLineEdit;
  editMissError = new QLineEdit;
  editSummary = new QLineEdit;
  hlayout1 = new QHBoxLayout;
  hlayout2 = new QHBoxLayout;
  hlayout3 = new QHBoxLayout;
  hlayout4 = new QHBoxLayout;
  hlayout5 = new QHBoxLayout;
  c1 = new QLabel;
  c2 = new QLabel;
  editF = new QLabel;
  editMiss = new QLabel;
  editSum = new QLabel;
  vlay = new QVBoxLayout;

  QObject::connect(doButton, SIGNAL(clicked()), this, SLOT(button_click()));

  doButton->setStyleSheet("background-color: #FF0000;");
  doButton->setMinimumHeight(100);
  doButton->setText("COMPUTE");

  c1->setText("First probability");
  c2->setText("Second probability");
  editF->setText("False Error");
  editMiss->setText("Miss Error Detecting");
  editSum->setText("Summary Error");

  hlayout1->addWidget(c1);
  hlayout1->addWidget(editC1);

  hlayout2->addWidget(c2);
  hlayout2->addWidget(editC2);

  hlayout3->addWidget(editF);
  hlayout3->addWidget(editFalse);

  hlayout4->addWidget(editMiss);
  hlayout4->addWidget(editMissError);

  hlayout5->addWidget(editSum);
  hlayout5->addWidget(editSummary);

  vlay->addLayout(hlayout1);
  vlay->addLayout(hlayout2);
  vlay->addWidget(doButton);
  vlay->addWidget(plot);
  vlay->addLayout(hlayout3);
  vlay->addLayout(hlayout4);
  vlay->addLayout(hlayout5);



  QwtPlotPicker *d_picker =
          new QwtPlotPicker(
              QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
  QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
  QwtPicker::AlwaysOn, // всегда включен
  plot->canvas() ); // ассоциация с полем
  // Цвет перпендикулярных линий
  d_picker->setRubberBandPen( QColor( Qt::red ) );
  // цвет координат положения указателя
  d_picker->setTrackerPen( QColor( Qt::black ) );
  // непосредственное включение вышеописанных функций
  d_picker->setStateMachine( new QwtPickerDragPointMachine() );

  c1Curve = new QwtPlotCurve;
  c2Curve = new QwtPlotCurve;
  line = new QwtPlotCurve;

  c1Curve->setPen(QPen(Qt::red));
  c2Curve->setPen(QPen(Qt::blue));
  line->setPen(QPen(Qt::green));

  c1Curve->setRenderHint(QwtPlotItem::RenderAntialiased);
  c2Curve->setRenderHint(QwtPlotItem::RenderAntialiased);
  line->setRenderHint(QwtPlotItem::RenderAntialiased);

  c1Curve->attach(plot);
  c2Curve->attach(plot);
  line->attach(plot);

  qsrand(QTime::currentTime().msec());

  setLayout(vlay);
  showMaximized();
}

void Draw::button_click()
{
  double p1, p2, pc1, pc2, x, falseError, missError, sumError;
  double sigm1, sigm2, mu1, mu2;
  double arr1[MAXPOINTS], arr2[MAXPOINTS], arrx[500];
  double y1[500], y2[500];
  double linex[500], liney[500];
  int i;

  pc1 = editC1->text().toDouble();
  pc2 = editC2->text().toDouble();

  if ((pc1 + pc2) > 1) {
        QMessageBox m;

        m.setText("Probability must be <= 1");
        m.exec();
        return;
  }

  for (i = 0; i < MAXPOINTS; i++) {
    arr1[i] = qrand()%500 - 100;
    arr2[i] = qrand()%500 + 100;
  }

  mu1 = 0;
  mu2 = 0;
  for (i = 0; i < MAXPOINTS; i++) {
    mu1 = mu1 + arr1[i];
    mu2 = mu2 + arr2[i];
  }
  mu1 /= MAXPOINTS;
  mu2 /= MAXPOINTS;

  sigm1 = 0;
  sigm2 = 0;
  for (i = 0; i < MAXPOINTS; i++) {
    sigm1 = sigm1 + qwtSqr(arr1[i] - mu1);
    sigm2 = sigm2 + qwtSqr(arr2[i] - mu2);
  }
  sigm1 = qSqrt(sigm1/MAXPOINTS);
  sigm2 = qSqrt(sigm2/MAXPOINTS);

  for (i = 0; i < 500; i++) {
    y1[i] = 100000*pc1 * (qExp(-0.5*qwtSqr((i-mu1)/sigm1)))/(sigm1*qSqrt(2*3.14));
    y2[i] = 100000*pc2 * (qExp(-0.5*qwtSqr((i-mu2)/sigm2)))/(sigm2*qSqrt(2*3.14));
    arrx[i] = i;
  }

  x = -100;
  p1 = 1;
  p2 = 0;
  falseError = 0;
  if (pc2 != 0)
    while (p2 < p1) {
      p1 = pc1 * (qExp(-0.5*qwtSqr((x-mu1)/sigm1)))/(sigm1*qSqrt(2*3.14));
      p2 = pc2 * (qExp(-0.5*qwtSqr((x-mu2)/sigm2)))/(sigm1*qSqrt(2*3.14));
      falseError += p2*0.001;
      x += 0.001;
    }
  if (x > 0 && x < 500) {
    for (i = 0; i < 500; i++) {
      linex[i] = x;
      liney[i] = i;
    }
    line->setSamples(linex, liney, 500);
    line->setVisible(true);
    plot->replot();
  }

  missError = 0;
  while(x < 1000) {
    p1 = (qExp(-0.5*qwtSqr((x-mu1)/sigm1)))/(sigm1*qSqrt(2*3.14));
    p2 = (qExp(-0.5*qwtSqr((x-mu2)/sigm2)))/(sigm1*qSqrt(2*3.14));
    missError += p1 * 0.001 * pc1;
    x += 0.001;
  }

  if (pc1 == 0) {
    falseError = 1;
    missError = 0;
    sumError = 1;
  }
  if (pc2 == 0) {
    falseError = 0;
    missError = 0;
    sumError = 0;
  }
  else {
    falseError /= pc1;
    missError /= pc1;
  }
  sumError = falseError + missError;


  editFalse->setText(QString::number(falseError));
  editMissError->setText(QString::number(missError));
  editSummary->setText(QString::number(sumError));

  c2Curve->setSamples(arrx, y2, 500);
  c1Curve->setSamples(arrx, y1, 500);
  c1Curve->setVisible(true);
  c2Curve->setVisible(true);

  plot->replot();
}
