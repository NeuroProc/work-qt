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
};

#endif // SHAPE_H
