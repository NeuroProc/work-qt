#include "rectangle.h"

int Rectangle::id = qRegisterMetaType<Rectangle>();

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
    this->A = QPoint(x1, y1);
    this->B = QPoint(x2, y2);
}

Rectangle::Rectangle(QPoint xy)
{
    this->A = xy;
    this->B = QPoint(def, def);
}


void Rectangle::drawMySelf(QPainter *painter)
{
    painter->drawRect(this->A.x(), this->A.y(), this->B.x(), this->B.y());
}

void Rectangle::initDefault()
{
    A = QPoint(x(), y());
    B = QPoint(def, def);
}


