#include "serial.h"

#include <QDebug>

#include <QPoint>
#include <QBitArray>
#include <QFile>

bool Serializer::serialize(QObject *object, QIODevice *output)
{
    QDomDocument doc;
    QDomElement root = doc.createElement(object->metaObject()->className());
    doc.appendChild(root);

    for(int i = 0; i < object->metaObject()->propertyCount(); i++)
    {
        QMetaProperty prop = object->metaObject()->property(i);
        QString propName = prop.name();
        if(propName == "objectName")
            continue;
        QDomElement el = doc.createElement(propName);
        QVariant value = object->property(propName.toAscii().data());
        QDomText txt = doc.createTextNode( value.toString() );
        el.appendChild(txt);
        root.appendChild(el);
    }

    //QFile output1("note.xml");
    QTextStream stream(output);
    doc.save(stream, 2);

    qDebug() << doc.toString();

    return true;
}

bool Serializer::_deserialize(QIODevice* input, QObject* object)
{
    QDomDocument doc;
    if (!doc.setContent(input))
        return false;
    QDomElement root = doc.documentElement();

    qDebug() << root;

    for(int i = 0; i < object->metaObject()->propertyCount(); i++)
    {
        QMetaProperty prop = object->metaObject()->property(i);
        QString propName = prop.name();
        if(propName == "objectName")
            continue;
        QDomNodeList nodeList = root.elementsByTagName(propName);
        if(nodeList.length() < 1)
            continue;
        QDomNode node = nodeList.at(0);
        //QVariant value = object->property(propName.toAscii().data());
        QString v = node.toElement().text();
        object->setProperty(propName.toAscii().data(), QVariant(v));
    }
    return true;
}
