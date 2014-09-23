#include "draw.h"

QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
}

void QPaintWidget::paintEvent(QPaintEvent *) {

    QPainter painter;


    painter.begin(this);
    painter.setPen(QPen(Qt::red));

    for (int i = 0; i < mylist.size(); i++)
    {
        mylist[i]->drawMySelf(&painter);
    }

    painter.end();

}

void QPaintWidget::mousePressEvent(QMouseEvent *)
{
    switch (current)
    {
    case 'L':
        mylist.push_back(new line(this->mapFromGlobal(QCursor::pos())));
        break;
    case 'R':
        mylist.push_back(new rectangle(this->mapFromGlobal(QCursor::pos())));
        break;
    case 'E':
        mylist.push_back(new ellipse(this->mapFromGlobal(QCursor::pos())));
        break;
    }

    this->update();
}
