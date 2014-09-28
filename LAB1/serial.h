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
    bool serialize(QObject *object, QIODevice *output);
    bool _deserialize(QIODevice *input, QObject *object);

    template<class T>
    T * deserialize(QIODevice *input)
    {
        T* object = new T();
        if(_deserialize(input, object))
            return object;
        delete object;
        return NULL;
    }
};

#endif // SERIAL_H
