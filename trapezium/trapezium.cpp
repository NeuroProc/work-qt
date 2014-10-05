#include "trapezium.h"

int Trapezium::id = qRegisterMetaType<Trapezium>();

int getId()
{
    return Trapezium::id;
}

Trapezium::Trapezium()
{
}

void Trapezium::drawMySelf(QPainter *painter)
{
    for(int i = 0; i < points.size() - 1; i++)
        painter->drawLine(points[i], points[i + 1]);
}

void Trapezium::initDefault()
{
    points.push_back(QPoint(x() + (def / 2), y()));
    points.push_back(QPoint(x() + def, y()));
    points.push_back(QPoint(x() + (def * 2), y() + def));
    points.push_back(QPoint(x(), y() + def));
    points.push_back(QPoint(x() + (def / 2), y()));
}
