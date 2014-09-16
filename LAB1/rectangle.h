#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
private:
    QPoint A, B;

public:
    rectangle(int, int, int, int);
    void drawMySelf(QPainter *);

};

#endif // RECTANGLE_H
