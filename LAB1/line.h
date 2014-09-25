#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line;
Q_DECLARE_METATYPE(Line)

class Line : public Shape
{
    Q_OBJECT
private:
    QPoint A, B;  
    static int id;

public:
    Line() {}
    Line(int, int, int, int);
    Line(QPoint);

    void drawMySelf(QPainter *);
    void initDefault(QPoint);
};

#endif // LINE_H
