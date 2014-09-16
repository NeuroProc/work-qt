#include "draw.h"

#include <QDebug>

Draw::Draw(int x, int y, QWidget *parent)
{
    img = new QImage(QSize(x,y), QImage::Format_RGB16);
    wgt = new QPaintWidget(parent, this->getImg());
    wgt->resize(parent->width(), parent->height());

    //qDebug() << wgt->width() << ":" << wgt->height();

    eraseImage();

}

Draw::~Draw()
{
    delete img;
    delete wgt;
}

QImage * Draw::getImg()
{
    return img;
}

void Draw::drawPixel(int x, int y, uint c)
{
    //img->setPixel(x, y, c);
    
    painter.begin(img);
    painter.fillRect(QRect(x, y, 5, 5), QBrush(c));
    painter.end();
}

void Draw::eraseImage()
{
    wgt->hide();
    img->fill(Qt::white);
    wgt->show();
}
