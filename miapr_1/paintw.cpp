#include "paintw.h"


QPaintWidget::QPaintWidget(QWidget * parent, QImage * i) : QWidget(parent)
{
    par = parent;
    img = i;
}

void QPaintWidget::paintEvent(QPaintEvent *)
{
    QPainter painter;

    painter.begin(this);
    painter.drawImage(QPoint(0, 0), *img);
    painter.end();
}

