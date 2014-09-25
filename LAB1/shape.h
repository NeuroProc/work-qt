#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include <QPainter>
#include <QString>
#include <QWidget>
#include "serial.h"

class Shape;

class Shape : /*public QObject,*/ public SerializedBase
{
    Q_OBJECT
    Q_PROPERTY(QPoint point READ getPoint WRITE setPoint)
    //Q_PROPERTY(int m_extraNum READ m_extraNum WRITE setExtraNum)

public:
    Shape() {}
    Shape(const Shape &) {}
    virtual ~Shape() {}

    virtual void drawMySelf(QPainter *);
    virtual void initDefault(QPoint);

    static int def;
    static int extraNum;

    QPoint getPoint();
    void setPoint(const QPoint point);

/*
    int m_def() { return def; }
    void setDef(const int def);

    int extraNum() const;
    void setExtraNum(const int extraNum);
*/
private:
    QPoint m_point;
};

#endif // SHAPE_H
