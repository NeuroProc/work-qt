#include "shape.h"

int Shape::extraNum = 2;
int Shape::def = 100;

//Shape::setProperty("def", 100);
//Shape::setProperty("extraNum", 2);

void Shape::drawMySelf(QPainter *)
{
    return;
}

void Shape::initDefault(QPoint)
{
    return;
}

QPoint Shape::getPoint()
{
    return m_point;
}

void Shape::setPoint(const QPoint point)
{
    m_point = point;
}
