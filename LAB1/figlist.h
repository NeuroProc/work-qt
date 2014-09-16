#ifndef FIGLIST_H
#define FIGLIST_H

#include <QVector>
#include "shape.h"

class FigList
{
public:
    QVector<shape *> list;
    void drawList();
};

#endif // FIGLIST_H
