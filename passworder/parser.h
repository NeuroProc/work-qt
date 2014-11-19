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
    void createElement(QString tagName, QString nodeValue);
    QDomElement getElement(QString targetElement, long targetId = 0);
    bool setElement(const QDomElement &newElement, long targetId = 0);

private:
    void open();
    void close();
    void update();
    void save();

    QFile dataFile;
    QDomDocument dataDocument;
    QDomElement rootElement;
};

#endif // PARSER_H
