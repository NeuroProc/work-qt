#ifndef WORKER_H
#define WORKER_H

#include <QObject>

#include "classifier.h"

class Worker : public QObject {
    Q_OBJECT

public:
    Worker(Classifier *);
    ~Worker();

public slots:
    void process();

signals:
    void finished();
    void error(QString err);

private:

    Classifier *l;
    // add your variables here
};

#endif // WORKER_H
