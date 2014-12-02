#include <QDebug>
#include "parser.h"

Parser::Parser(QString dataBase)
{
    dataFile.setFileName(dataBase);

    if (QFile::exists(dataBase))
        update();
}

Parser::~Parser()
{
    save();
}

void Parser::open(QIODevice::OpenMode mode)
{
    if (!dataFile.open(mode))
        qDebug() << "EE: can't open file";
}

void Parser::close()
{
    dataFile.close();
}

void Parser::initialize(QString rootTag)
{
    dataDocument.appendChild(dataDocument.createElement(rootTag));

    save();
    update();
}

void Parser::update()
{
    open();
    if (dataDocument.setContent(&dataFile))
        qDebug() << "II: database updated";
    else
        qDebug() << "EE: can't update database";
    close();

    rootElement = dataDocument.documentElement();
}

void Parser::save()
{
    open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    QTextStream dataStream(&dataFile);
    dataDocument.save(dataStream, 3);
    qDebug() << "II: database saved";
    close();
}

QDomElement Parser::createElement(QString tagName, QDomElement * parent)
{
    if (parent == 0)
        parent = &rootElement;

    QDomElement newElement = dataDocument.createElement(tagName);

    parent->appendChild(newElement);

    return newElement;
}

QDomText Parser::createTextNode(QString text, QDomElement * parent)
{
    if (parent == 0)
        parent = &rootElement;

    QDomText textNode = dataDocument.createTextNode(text);

    parent->appendChild(textNode);

    return textNode;
}

void Parser::replaceElement(QDomElement newElement, QDomElement oldElement)
{
    rootElement.replaceChild(newElement, oldElement);
}

void Parser::deteleElement(QDomElement oldElement)
{
    rootElement.removeChild(oldElement);
}

QDomElement Parser::getElement(QString targetElement, long targetId)
{
    QDomNodeList nodes = rootElement.elementsByTagName(targetElement);

    return nodes.at(targetId).toElement();
}
