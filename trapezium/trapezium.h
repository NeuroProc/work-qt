#ifndef TRAPEZIUM_H
#define TRAPEZIUM_H

#include <QMetaObject>
#include <QMetaType>
#include <QObject>

#include "trapezium_global.h"
#include "shape.h"

class TRAPEZIUMSHARED_EXPORT Trapezium;
Q_DECLARE_METATYPE(Trapezium)

extern "C" TRAPEZIUMSHARED_EXPORT int getId();

class TRAPEZIUMSHARED_EXPORT Trapezium : public Shape
{
    Q_OBJECT
    
private:
    QVector<QPoint> points;

public:
    Trapezium();

    void drawMySelf(QPainter *);
    void initDefault();

    static int id;
};

#endif // TRAPEZIUM_H
