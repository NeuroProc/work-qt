#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "draw.h"
#include <QMessageBox>
#include <qmath.h>
#include <QObject>
#include <QHash>
#include <QVector>
#include <QThreadPool>
#include <QMutex>
#include <QDebug>

class Classifier : public QObject
{
   Q_OBJECT

public:
    explicit Classifier(long, long, QWidget *parent = 0, Draw *dr = 0);
    ~Classifier();

    void setRandomVect(int, int);
    void getRandomCores();

    void classify();
    bool reCompute();

    double getDistance(int, int, int, int);
    long getMin(QVector<long> *);

    long getCore(long);
    void setCore(long, long);

    void setGlobalFlag(bool);

private:

    struct pointInf;
    Draw *d;
    QMessageBox msg;
    QWidget *p;
    QMutex mutex;

    long numPoint;
    long numClass;
    bool globalFlag;

    long *cores;
    pointInf *vect;
    uint *colors;
};

class getMinC : public QRunnable
{
public:
    getMinC(Classifier * parent = 0, QVector<long> * t = 0, long key = -1);
    void run();

private:
    long k;
    Classifier *p;
    QVector<long> *tmp;

};

#endif // CLASSIFIER_H
