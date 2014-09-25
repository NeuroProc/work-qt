#ifndef EXTRA_H
#define EXTRA_H

#include "shape.h"
#include <qmath.h>

class Extra;
Q_DECLARE_METATYPE(Extra)

class Extra : public Shape
{
    Q_OBJECT
private:
    static int id;

public:
    Extra() {}
    //Extra(QVector<QPoint> *);

    void drawMySelf(QPainter *);
    void initDefault(QPoint);

    QVector<QPoint> points;
};

#endif // EXTRA_H
