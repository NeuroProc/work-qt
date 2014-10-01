#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include <QPainter>
#include <QString>
#include <QWidget>
#include <QDebug>

class Shape;

class Shape : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int x READ x WRITE setX)
    Q_PROPERTY(int y READ y WRITE setY)

public:
    Shape() {}
    Shape(const Shape &) {}
    virtual ~Shape() {}

    virtual void drawMySelf(QPainter *);
    virtual void initDefault();

    static int def;
    static int extraNum;

    int x() const { return mX; }
    void setX(const int x) { mX = x; }

    int y() const { return mY; }
    void setY(const int y) { mY = y; }

/*
    int m_def() { return def; }
    void setDef(const int def);

    int extraNum() const;
    void setExtraNum(const int extraNum);
*/
private:
    int mX, mY;
};

#endif // SHAPE_H
