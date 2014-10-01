#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <QMetaObject>
#include <QMetaType>
#include <QObject>

#include "trapezium_global.h"
#include "../LAB1/shape.h"


class TRAPEZIUMSHARED_EXPORT Trapezium;

Q_DECLARE_METATYPE(Trapezium)

class TRAPEZIUMSHARED_EXPORT Trapezium : public Shape
{
    Q_OBJECT
    
private:
    static int id;
    QVector<QPoint> points;

public:
    Trapezium();

    void drawMySelf(QPainter *);
    void initDefault();
};

#endif // TRAPEZIUM_H
