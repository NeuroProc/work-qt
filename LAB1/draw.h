#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QDebug>

#include "shape.h"
#include "line.h"
#include "ellipse.h"
#include "rectangle.h"

class QPaintEvent;

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:
    QPaintWidget(QWidget * parent = 0);
    //void drawMyLine(QPainter *);
    //static shape *current;
    QVector<shape *> mylist;
    char current;

protected:
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
};
#endif // DRAW_H
