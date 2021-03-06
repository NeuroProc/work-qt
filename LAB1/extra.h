#ifndef EXTRA_H
#define EXTRA_H

#include "shape.h"
#include <qmath.h>

class Extra;
Q_DECLARE_METATYPE(Extra)

class Extra : public Shape
{
    Q_OBJECT

    Q_PROPERTY(int num READ num WRITE setNum)
private:
    static int id;
    int mNum;

public:
    Extra() { setNum(extraNum); }
    //Extra(QVector<QPoint> *);

    void drawMySelf(QPainter *);
    void initDefault();

    int num() { return mNum; }
    void setNum(const int num) { mNum = num; }

    QVector<QPoint> points;
};

#endif // EXTRA_H
