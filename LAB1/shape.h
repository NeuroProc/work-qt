#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include <QPainter>
#include <QString>

class shape
{
public:
    //static QPainter painter;
    virtual void drawMySelf(QPainter *) = 0;
    static const int def = 100;
};

#endif // SHAPE_H
