#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class Ellipse;
Q_DECLARE_METATYPE(Ellipse)

class Ellipse : public Shape
{
    Q_OBJECT
private:
    QPoint center;
    int rx, ry;

public:
    Ellipse() {}
    Ellipse(int, int, int, int);
    Ellipse(QPoint);

    void drawMySelf(QPainter *);

    static int id;
};

#endif // ELLIPSE_H
