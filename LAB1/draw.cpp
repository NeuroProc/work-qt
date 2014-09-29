#include "draw.h"

QPaintWidget::QPaintWidget(QWidget * parent) : QWidget(parent)
{
}

QPaintWidget::~QPaintWidget()
{
    foreach(Shape *obj, mylist)
        obj->deleteLater();
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
    if (int id = QMetaType::type(current.toAscii().data()))
    {
        QPoint pos = this->mapFromGlobal(QCursor::pos());

        Shape *s = (Shape *)QMetaType::construct(id);
        s->setProperty("x", pos.x());
        s->setProperty("y", pos.y());
        s->initDefault();

        mylist.push_back(s);
    }

    this->update();
}
