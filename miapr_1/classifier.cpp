#include "classifier.h"

struct Classifier::pointInf
{
    int c;
    QPoint p;
};

Classifier::Classifier(long numP, long numC, QWidget * parent, Draw * dr)
{
    numPoint = numP;
    numClass = numC;

    vect = new pointInf[numPoint];
    cores = new long[numClass];
    colors = new uint[numClass];

    d = dr;
    p = parent;

    //msg.setText(QString("%1").arg(RAND_MAX));
    //msg.setText("");
    //msg.show();
    //msg.exec();

    setRandomVect(parent->width(), parent->height());
}

Classifier::~Classifier()
{
    /* dispose data */
    delete[] vect;
    delete[] cores;
    delete[] colors;
}

bool Classifier::reCompute()
{
    QHash<long, QVector<long> *> hash;
    QThreadPool pool(this);

    globalFlag = false;

    for (long i = 0; i < numPoint; i++)
    {
        if (!hash.contains(vect[i].c))
             hash.insert(vect[i].c, new QVector<long>);

        hash[vect[i].c]->push_back(i);
    }

    //qDebug() << pool.maxThreadCount();

    pool.setMaxThreadCount(numClass);

    foreach (long i, hash.keys())
        pool.start(new getMinC(this, hash[i], i));

    pool.waitForDone();
    hash.clear();

    return globalFlag;
}

long Classifier::getMin(QVector<long> *tmp)
{
    double minSum = -1;
    double sum;
    long min;


    for (long j = 0; j < tmp->size(); j++)
    {
        sum = 0;

        for (long k = 0; k < tmp->size(); k++)
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
    long minIndex;

    for (long i = 0; i < numPoint; i++)
    {
        min = 0;
        minIndex = -1;

        for (long j = 0; j < numClass; j++)
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

void Classifier::getRandomCores()
{
    long target = 0;

    for (long i = 0; i < numClass; i++)
    {
        while (vect[ (target = qrand() % numPoint) ].c == -1)
            ;
        cores[i] = target;
        vect[target].c = -1;
        colors[i] = qRgb(qrand() % 255, qrand() % 255, qrand() % 255);
    }
}

long Classifier::getCore(long i)
{
    return cores[i];
}

void Classifier::setCore(long i, long value)
{
    cores[i] = value;
}

void Classifier::setGlobalFlag(bool value)
{
    globalFlag = value;
}

void Classifier::setRandomVect(int x, int y)
{   
    for (long i = 0; i < numPoint; i++)
    {
        vect[i].p = QPoint(qrand() % x, qrand() % y);
        vect[i].c = 0;
    }
}

getMinC::getMinC(Classifier * parent, QVector<long> *t, long key)
{
    p = parent;
    tmp = t;
    k = key;
}

void getMinC::run()
{
    long min;
    min = p->getMin(tmp);

    if (p->getCore(k) != min)
    {
        p->setCore(k, min);
        p->setGlobalFlag(true);
    }

    qDebug() << QThread::currentThreadId() << "ENDED";
}

