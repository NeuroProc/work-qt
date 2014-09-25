#ifndef SERIAL_H
#define SERIAL_H

#include <QDataStream>
#include <QMetaProperty>
#include <QMetaObject>

class SerializedBase;

class SerializedBase : public QObject
{
    Q_OBJECT
public:
    QString Serialize();
    bool DeSerialize(QString *dataStream);

};

#endif // SERIAL_H
