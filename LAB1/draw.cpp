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
        Shape *s = (Shape *)QMetaType::construct(id);
        s->initDefault(this->mapFromGlobal(QCursor::pos()));
        s->setPoint(this->mapFromGlobal(QCursor::pos()));
        //qDebug() << s->getPoint() << ":" << s->property("point");
        mylist.push_back(s);
    }

    this->update();
}
