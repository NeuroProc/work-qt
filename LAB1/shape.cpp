#include "shape.h"

int Shape::extraNum = 2;
int Shape::def = 100;

//Shape::setProperty("def", 100);
//Shape::setProperty("extraNum", 2);

void Shape::drawMySelf(QPainter *)
{
    qDebug() << "SHAPE PAINT";
    return;
}

void Shape::initDefault()
{
    return;
}
