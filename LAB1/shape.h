#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include <QPainter>
#include <QString>
#include <QWidget>

class Shape;

class Shape : public QObject
{
    Q_OBJECT
public:
    Shape() {}
    Shape(const Shape &) {}
    virtual ~Shape() {}

    virtual void drawMySelf(QPainter *);
    virtual void initDefault(QPoint);
    static const int def = 100;
    static int extraNum;
};

#endif // SHAPE_H
