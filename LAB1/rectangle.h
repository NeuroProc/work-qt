#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle;
Q_DECLARE_METATYPE(Rectangle)

class Rectangle : public Shape
{
    Q_OBJECT
private:
    QPoint A, B;

public:
    Rectangle() {}
    Rectangle(int, int, int, int);
    Rectangle(QPoint);

    void drawMySelf(QPainter *);

    static int id;
};

#endif // RECTANGLE_H
