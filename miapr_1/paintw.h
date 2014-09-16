#ifndef PAINTW_H
#define PAINTW_H

#include <QWidget>
#include <QPainter>

class QPaintEvent;

class QPaintWidget : public QWidget
{
    Q_OBJECT
public:
    QPaintWidget(QWidget * parent = 0, QImage * i = 0);

protected:
    void paintEvent(QPaintEvent *);

private:
    QWidget * par;
    QImage * img;
};


#endif // PAINTW_H
