#ifndef XMLEDITOR_H
#define XMLEDITOR_H

#include <QtXml>
#include <QFile>
#include <QIODevice>

#include "xmleditor_global.h"

extern "C" struct XMLEDITORSHARED_EXPORT Parameters
{
    char *tag;
    char *attr;
    char *attrVal;
    char *val;
};




/* INTERFACE */

class IXMLEditor {
    virtual void print() = 0;
    virtual void appendFile(const char *) = 0;

    virtual void changeTagByTag(Parameters, const char *) = 0;
    virtual void setAttributeValueByTag(Parameters, const char *) = 0;
    virtual void setValueByTag(Parameters, const char *) = 0;
    virtual void deleteTagByAttrValue(Parameters, Parameters) = 0;
    virtual void addNewTag(Parameters, Parameters) = 0;
};

/* END */





class XMLEditor : public IXMLEditor
{
    QFile file;
    QDomDocument xmlFile;
    QDomElement root;
public:
    XMLEditor();
    XMLEditor(const char *);
    virtual ~XMLEditor();

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
    void release();
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

    void print();
    void appendFile(const char *);

    void changeTagByTag(Parameters, const char *);
    void setAttributeValueByTag(Parameters, const char *);
    void setValueByTag(Parameters, const char *);
    void deleteTagByAttrValue(Parameters, Parameters);
    void addNewTag(Parameters, Parameters);
};

extern "C" XMLEDITORSHARED_EXPORT IXMLEditor * getHandler();


#endif // XMLEDITOR_H
