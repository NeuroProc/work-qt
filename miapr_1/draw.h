#ifndef DRAW_H
#define DRAW_H

#include <QImage>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QWidget>
#include "paintw.h"

class Draw
{
public:
    Draw(int, int, QWidget * parent = 0);
    ~Draw();
    QImage * getImg();
    void drawPixel(int, int, uint);
    void eraseImage();
    QPaintWidget * wgt;

private:
    //QPaintWidget * wgt;
    QImage *img;
    QPainter painter;

};


#endif // DRAW_H
