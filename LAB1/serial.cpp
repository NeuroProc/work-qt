#include "serial.h"

Serializer::Serializer()
{
    rootDoc = doc.createElement("Collection");
    doc.appendChild(rootDoc);
}


bool Serializer::save(QIODevice *output)
{
    //QFile output1("note.xml");
    QTextStream stream(output);
    doc.save(stream, 2);

    //qDebug() << doc.toString();

    return true;
}

bool Serializer::serialize(QObject *object)
{
    QDomElement root = doc.createElement(object->metaObject()->className());
    rootDoc.appendChild(root);

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

    return true;
}

bool Serializer::_deserialize(QDomElement root, QObject** object)
{
    if (int id = QMetaType::type(root.nodeName().toAscii().data()))
        *object = (QObject*)QMetaType::construct(id);
    else
        return false;

    for(int i = 0; i < (*object)->metaObject()->propertyCount(); i++)
    {
        QMetaProperty prop = (*object)->metaObject()->property(i);
        QString propName = prop.name();
        if(propName == "objectName")
            continue;
        QDomNodeList nodeList = root.elementsByTagName(propName);
        if(nodeList.length() < 1)
            continue;
        QDomNode node = nodeList.at(0);
        QString v = node.toElement().text();
        (*object)->setProperty(propName.toAscii().data(), QVariant(v));
        qDebug() << propName << " = " << v;
    }
    return true;
}
