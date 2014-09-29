#include "extra.h"

int Extra::id = qRegisterMetaType<Extra>();

void Extra::drawMySelf(QPainter *painter)
{
    for(int i = 0; i < points.size() - 1; i++)
        painter->drawLine(points[i], points[i + 1]);
}

void Extra::initDefault()
{
   for (int i = 0; i < extraNum; i++)
   {
       points.push_back(QPoint(x() + static_cast<int>(def * qCos(2 * i * M_PI / extraNum)),
                               y() + static_cast<int>(def * qSin(2 * i * M_PI/ extraNum))));
   }
   points.push_back(QPoint(points.value(0).x(), points.value(0).y()));
}
