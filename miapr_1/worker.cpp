#include "worker.h"

// --- CONSTRUCTOR ---
Worker::Worker(Classifier *lol) {

    l = lol;
    // you could copy data from constructor arguments to internal variables here.
}

// --- DECONSTRUCTOR ---
Worker::~Worker() {
    // free resources
}

// --- PROCESS ---
// Start processing data.
void Worker::process() {
    // allocate resources using new here
    qDebug("Hello World!");

    l->proc();
    emit finished();
}
