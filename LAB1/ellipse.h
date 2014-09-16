#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class ellipse : public shape
{
private:
    QPoint center;
    int rx, ry;


public:
    ellipse(int, int, int, int);
    void drawMySelf(QPainter *);
};

#endif // ELLIPSE_H
