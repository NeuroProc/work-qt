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
    void setRandomCore();

    void classify();
    bool reCompute();
    double maximin(int *);

    double getDistance(int, int, int, int);
    double getAverageDistance();
    int getMin(QVector<int> *);

    int getCore(int);
    void setCore(int, int);
    void pushCore(int);

    void setGlobalFlag(bool);

    void drawCores();

private:

    struct pointInf;
    Draw *d;
    QMessageBox msg;
    QWidget *p;
    QMutex mutex;

    int numPoint;
    int numClass;
    bool globalFlag;

    //int *cores;
    //uint *colors;

    pointInf *vect;

    QVector<int> cores;
    QVector<uint> colors;
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
