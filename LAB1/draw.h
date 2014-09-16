#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include "shape.h"

class QPaintEvent;

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:
    QPaintWidget(QWidget * parent = 0);
    //void drawMyLine(QPainter *);
    //static shape *current;
    QVector<shape *> mylist;


protected:
    void paintEvent(QPaintEvent *);
};
#endif // DRAW_H
