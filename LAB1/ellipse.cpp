#include "ellipse.h"

ellipse::ellipse(int centx, int centy, int rx, int ry)
{
    this->center = QPoint(centx, centy);
    this->rx = rx;
    this->ry = ry;
}

void ellipse::drawMySelf(QPainter *painter)
{
    painter->drawEllipse(this->center, this->rx, this->ry);
}
