#include "line.h"

int Line::id = qRegisterMetaType<Line>();

Line::Line(int x1, int x2, int y1, int y2)
{
    A = QPoint(x1, y1);
    B = QPoint(x2, y2);

}

Line::Line(QPoint xy)
{
    A = xy;
    B = QPoint(xy.x() + def, xy.y() + def);
}

void Line::drawMySelf(QPainter *painter)
{
    painter->drawLine(this->A, this->B);
}

void Line::initDefault(QPoint xy)
{
    A = xy;
    B = QPoint(xy.x() + def, xy.y() + def);
}
