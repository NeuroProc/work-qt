#include <QDebug>
#include "parser.h"

Parser::Parser(QString dataBase)
{
    dataFile.setFileName(dataBase);
}

Parser::~Parser()
{
}

void Parser::open()
{
    if (dataFile.open(QIODevice::ReadWrite | QIODevice::Text))
        qDebug() << "II: file open successfully";
    else
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

    rootElement = dataDocument.documentElement();
}

void Parser::update()
{
    open();
    if (dataDocument.setContent(&dataFile))
        qDebug() << "II: database update successfully";
    else
        qDebug() << "EE: can't update database";
    close();

    rootElement = dataDocument.documentElement();
}

void Parser::save()
{
    open();
    QTextStream dataStream(&dataFile);
    dataDocument.save(dataStream, 3);
    close();
}

void Parser::createElement(QString tagName, QString nodeValue)
{
    QDomElement newElement = dataDocument.createElement(tagName);
    newElement.appendChild(dataDocument.createTextNode(nodeValue));

    rootElement.appendChild(newElement);
    save();
}

QDomElement Parser::getElement(QString targetElement, long targetId)
{
    QDomNodeList nodes = rootElement.elementsByTagName(targetElement);

    return nodes.at(targetId).toElement();
}

bool Parser::setElement(const QDomElement &newElement, long targetId)
{
    QDomNodeList nodes = rootElement.elementsByTagName(newElement.tagName());

    QDomNode node = nodes.at(targetId);
    if (node.isNull())
        return false;

    node = newElement;
    save();

    return true;
}
