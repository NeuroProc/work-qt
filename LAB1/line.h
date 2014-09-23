#ifndef LINE_H
#define LINE_H

#include "shape.h"

class line : public shape
{
private:
    QPoint A, B;

public:
    line(int, int, int, int);
    line(QPoint);
    void drawMySelf(QPainter *);

};

#endif // LINE_H
