#ifndef PARSER_H
#define PARSER_H

#include <QtXml>
#include <QFile>

class Parser
{
public:
    Parser(QString dataBase);
    ~Parser();

    void initialize(QString rootTag);
    QDomElement createElement(QString tagName, QDomElement * parent = 0);
    QDomText createTextNode(QString text, QDomElement * parent = 0);
    void replaceElement(QDomElement newElement, QDomElement oldElement);
    void deteleElement(QDomElement oldElement);
    QDomElement getElement(QString targetElement, long targetId = 0);

    void save();

private:
    void open(QIODevice::OpenMode mode = QIODevice::ReadWrite | QIODevice::Text);
    void close();
    void update();

    QFile dataFile;
    QDomDocument dataDocument;
    QDomElement rootElement;
};

#endif // PARSER_H
