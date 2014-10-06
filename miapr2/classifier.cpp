#include "classifier.h"

struct Classifier::pointInf
{
    int c;
    QPoint p;
};

Classifier::Classifier(int numP, int numC, QWidget * parent, Draw * dr)
{
    numPoint = numP;
    numClass = numC;

    vect = new pointInf[numPoint];
    //cores = new int[numClass];
    //colors = new uint[numClass];

    d = dr;
    p = parent;

    setRandomVect(parent->width(), parent->height());
}

Classifier::~Classifier()
{
    /* dispose data */
    delete[] vect;
    //delete[] cores;
    //delete[] colors;
}

double Classifier::maximin(int *newCore)
{
    double maxDist = -1;
    double curDist;

    for (int i = 0; i < numPoint; i++)
    {
        curDist = getDistance(vect[i].p.x(), vect[i].p.y(), vect[ cores[vect[i].c] ].p.x(), vect[ cores[vect[i].c] ].p.y());
        if ( curDist > maxDist )
        {
            maxDist = curDist;
            *newCore = i;
        }
    }

    return maxDist;
}

double Classifier::getAverageDistance()
{
    double resSum = 0;

    for (int i = 0; i < numClass; i++)
    {
        for (int j = i + 1; j < numClass; j++)
        {
            resSum += getDistance(vect[ cores[i] ].p.x(), vect[ cores[i] ].p.y(), vect[ cores[j] ].p.x(), vect[ cores[j] ].p.y());
        }
    }

    return (resSum / numClass);
}

bool Classifier::reCompute()
{
    QHash<int, QVector<int> *> hash;
    QThreadPool pool(this);

    globalFlag = false;

    for (int i = 0; i < numPoint; i++)
    {
        if (!hash.contains(vect[i].c))
             hash.insert(vect[i].c, new QVector<int>);

        hash[vect[i].c]->push_back(i);
    }

    //qDebug() << pool.maxThreadCount();

    pool.setMaxThreadCount(numClass);

    foreach (int i, hash.keys())
        pool.start(new getMinC(this, hash[i], i));

    pool.waitForDone();
    hash.clear();

    return globalFlag;
}

int Classifier::getMin(QVector<int> *tmp)
{
    double minSum = -1;
    double sum;
    int min;


    for (int j = 0; j < tmp->size(); j++)
    {
        sum = 0;

        for (int k = 0; k < tmp->size(); k++)
        {
            if (j == k)
                continue;

            sum += getDistance(vect[(*tmp)[j]].p.x(), vect[(*tmp)[j]].p.y(), vect[(*tmp)[k]].p.x(), vect[(*tmp)[k]].p.y());
        }

        if (sum < minSum || minSum < 0)
        {
            minSum = sum;
            min = (*tmp)[j];
        }
    }

    return min;

}

double Classifier::getDistance(int ax, int ay, int bx, int by)
{
    return sqrt( pow(bx - ax, 2) + pow(by - ay, 2) );
}

void Classifier::classify()
{
    double min, tmp;
    int minIndex;

    numClass = cores.size();  //GET CURRENT NUMBER OF CORES

    for (int i = 0; i < numPoint; i++)
    {
        min = 0;
        minIndex = -1;

        for (int j = 0; j < numClass; j++)
        {
            if (( tmp = getDistance(vect[ i ].p.x(), vect[ i ].p.y(), vect[ cores[j] ].p.x(), vect[ cores[j] ].p.y()) ) < min || minIndex < 0)
            {
                min = tmp;
                minIndex = j;
            }

        }
        vect[i].c = minIndex;
        d->drawPixel(vect[i].p.x(), vect[i].p.y(), colors[minIndex]);

    }

}

void Classifier::setRandomCore()
{
    int target = 0;

    vect[ (target = qrand() % numPoint) ].c = -1;
    cores.push_back(target);
    colors.push_back(qRgb(qrand() % 255, qrand() % 255, qrand() % 255));

    /*
    int target = 0;

    for (int i = 0; i < numClass; i++)
    {
        while (vect[ (target = qrand() % numPoint) ].c == -1)
            ;
        cores[i] = target;
        vect[target].c = -1;
        colors[i] = qRgb(qrand() % 255, qrand() % 255, qrand() % 255);
    }
    */
}

void Classifier::pushCore(int value)
{
    cores.push_back(value);
    colors.push_back(qRgb(qrand() % 255, qrand() % 255, qrand() % 255));
}

int Classifier::getCore(int i)
{
    return cores[i];
}

void Classifier::setCore(int i, int value)
{
    cores[i] = value;
}

void Classifier::setGlobalFlag(bool value)
{
    globalFlag = value;
}

void Classifier::setRandomVect(int x, int y)
{   
    for (int i = 0; i < numPoint; i++)
    {
        vect[i].p = QPoint(qrand() % x, qrand() % y);
        vect[i].c = 0;
    }
}

getMinC::getMinC(Classifier * parent, QVector<int> *t, int key)
{
    p = parent;
    tmp = t;
    k = key;
}

void getMinC::run()
{
    int min;
    min = p->getMin(tmp);

    if (p->getCore(k) != min)
    {
        p->setCore(k, min);
        p->setGlobalFlag(true);
    }

    qDebug() << QThread::currentThreadId() << "ENDED";
}

