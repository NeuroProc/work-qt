#ifndef LAGRANGE_H
#define LAGRANGE_H

#include <QPolygonF>

class Lagrange
{
public:
    static float interpolate(float x, QPolygonF values, int size)
    {
        float lagrangePol = 0;

        for (int i = 0; i < size; i++)
        {
            float basicPol = 1;

            for (int j = 0; j < size; j++)
            {
                if (j != i)
                    basicPol *= (x - values[j].x()) / (values[i].x() - values[j].x());
            }
            lagrangePol += basicPol * values[i].y();
        }

        return lagrangePol;
    }

};

#endif // LAGRANGE_H
