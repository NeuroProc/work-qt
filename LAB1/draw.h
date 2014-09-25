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
#include "extra.h"

class QPaintEvent;

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:
    QPaintWidget(QWidget * parent = 0);

    QVector<Shape *> mylist;
    QString current;

protected:
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
};
#endif // DRAW_H
