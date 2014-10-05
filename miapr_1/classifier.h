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
    explicit Classifier(int, int, QWidget *parent = 0, Draw *dr = 0);
    ~Classifier();

    void setRandomVect(int, int);
    void getRandomCores();

    void classify();
    bool reCompute();

    double getDistance(int, int, int, int);
    int getMin(QVector<int> *);

    int getCore(int);
    void setCore(int, int);

    void setGlobalFlag(bool);

private:

    struct pointInf;
    Draw *d;
    QMessageBox msg;
    QWidget *p;
    QMutex mutex;

    int numPoint;
    int numClass;
    bool globalFlag;

    int *cores;
    pointInf *vect;
    uint *colors;
};

class getMinC : public QRunnable
{
public:
    getMinC(Classifier * parent = 0, QVector<int> * t = 0, int key = -1);
    void run();

private:
    int k;
    Classifier *p;
    QVector<int> *tmp;

};

#endif // CLASSIFIER_H
