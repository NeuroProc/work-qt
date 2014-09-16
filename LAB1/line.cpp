#include "line.h"

line::line(int x1, int y1, int x2, int y2)
{
    this->A = QPoint(x1, y1);
    this->B = QPoint(x2, y2);
}

void line::drawMySelf(QPainter *painter)
{
    painter->drawLine(this->A, this->B);
}
