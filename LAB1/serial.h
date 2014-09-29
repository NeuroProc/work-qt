#ifndef SERIAL_H
#define SERIAL_H

#include <QDataStream>
#include <QMetaProperty>
#include <QMetaObject>
#include <QDomDocument>

class Serializer;

class Serializer
{
public:
    Serializer();
    bool serialize(QObject *object);
    bool _deserialize(QDomElement root, QObject **object);

    bool save(QIODevice *output);

private:
    QDomDocument doc;
    QDomElement rootDoc;
};

#endif // SERIAL_H
