#ifndef NEWTON_H
#define NEWTON_H

#include <QPolygonF>

class Newton
{

public:

    static double interpolate(float x, QPolygonF values, int size)
    {
        float res = values[0].y();
        float F, den;


        for(int i = 1; i < size; i++)
        {
            F = 0;
            for (int j = 0; j <= i; j++)
            {//следующее слагаемое полинома
                den = 1;
                //считаем знаменатель разделенной разности
                for(int k = 0; k <= i; k++)
                {
                    if (k != j)
                        den *= (values[j].x() - values[k].x());
                }
                //считаем разделенную разность
                F += values[j].y() / den;
            }

            //домножаем разделенную разность на скобки (x-x[0])...(x-x[i-1])
            for (int k = 0; k < i; k++)
                F *= (x - values[k].x());
            res += F;//полином
        }

    return res;
    }
};

#endif // NEWTON_H
