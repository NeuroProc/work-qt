#include "ellipse.h"

int Ellipse::id = qRegisterMetaType<Ellipse>();

Ellipse::Ellipse(int centx, int centy, int rx, int ry)
{
    this->center = QPoint(centx, centy);
    this->rx = rx;
    this->ry = ry;
}

Ellipse::Ellipse(QPoint cent)
{
    this->center = cent;
    this->rx = def;
    this->ry = def;
}

void Ellipse::drawMySelf(QPainter *painter)
{
    painter->drawEllipse(this->center, this->rx, this->ry);
}

void Ellipse::initDefault()
{
    center = QPoint(x(), y());
    rx = def;
    ry = def;
}

