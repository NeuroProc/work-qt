#include "xmleditor.h"

XMLEditor::XMLEditor()
{

}

XMLEditor::XMLEditor(const char *path)
{
    appendFile(path);
}

XMLEditor::~XMLEditor()
{
    file.close();
}

void XMLEditor::release()
{
   delete this;
}

void XMLEditor::print()
{
    qDebug() << xmlFile.toString();
}


void XMLEditor::appendFile(const char * path)
{
    file.setFileName(path);
    if (!file.exists())
    {
        qDebug() << "Cannot find a file";
        exit(1);
    }

    if (file.open(QIODevice::ReadOnly))
    {
        xmlFile.setContent(&file);
        root = xmlFile.documentElement();
    }
    else
    {
        qDebug() << "Cannot open a file";
        exit(1);
    }
}

void XMLEditor::changeTagByTag(Parameters parameters, const char *newTag)
{
    QDomNodeList nl = xmlFile.elementsByTagName(parameters.tag);

    if (QString(parameters.attr) != "" && QString(parameters.val) != "")
    {
        for (int i = 0; i < nl.count(); i++)
        {
            QDomElement elem = nl.at(i).toElement();

            if (elem.toElement().attribute(parameters.attr) == QString(parameters.attrVal) && elem.firstChild().nodeValue() == QString(parameters.val))
                elem.setTagName(newTag);
        }
    }
    else if (QString(parameters.attr) != "" && QString(parameters.val) == "")
    {
        for (int i = 0; i < nl.count(); i++)
        {
            QDomElement elem = nl.at(i).toElement();

            if (elem.toElement().attribute(parameters.attr) == QString(parameters.attrVal))
                elem.setTagName(newTag);
        }
    }
    else if (QString(parameters.attr) == "" && QString(parameters.val) != "")
    {
        for (int i = 0; i < nl.count(); i++)
        {
            QDomElement elem = nl.at(i).toElement();

            if (elem.firstChild().nodeValue() == QString(parameters.val))
                elem.setTagName(newTag);
        }
    }
    else
    {
        for (int i = 0; i < nl.count(); i++)
        {
            QDomElement elem = nl.at(i).toElement();
            elem.setTagName(newTag);
        }
    }
}

void XMLEditor::setAttributeValueByTag(Parameters parameters, const char *newValue)
{
    QDomNodeList nl = xmlFile.elementsByTagName(parameters.tag);

    for (int i = 0; i < nl.count(); i++)
    {
        QDomElement elem = nl.at(i).toElement();

        if (elem.toElement().attribute((parameters.attr)) == QString(parameters.attrVal))
            elem.setAttribute(parameters.attr, newValue);
    }
}

void XMLEditor::setValueByTag(Parameters parameters, const char *newValue)
{
    QDomNodeList nl = xmlFile.elementsByTagName(parameters.tag);

    if (QString(parameters.attr) != "" && QString(parameters.val) != "")
    {
        for (int i = 0; i < nl.count(); i++)
        {
            QDomElement elem = nl.at(i).toElement();

            if (elem.toElement().attribute(parameters.attr) == QString(parameters.attrVal) && elem.firstChild().nodeValue() == QString(parameters.val))
                elem.firstChild().setNodeValue(newValue);
        }
    }
    else if (QString(parameters.attr) != "" && QString(parameters.val) == "")
    {
        for (int i = 0; i < nl.count(); i++)
        {
            QDomElement elem = nl.at(i).toElement();

            if (elem.toElement().attribute(parameters.attr) == QString(parameters.attrVal))
                elem.firstChild().setNodeValue(newValue);
        }
    }
    else if (QString(parameters.attr) == "" && QString(parameters.val) != "")
    {
        for (int i = 0; i < nl.count(); i++)
        {
            QDomElement elem = nl.at(i).toElement();

            if (elem.firstChild().nodeValue() == QString(parameters.val))
                elem.firstChild().setNodeValue(newValue);
        }
    }
    else
    {
        for (int i = 0; i < nl.count(); i++)
        {
            QDomElement elem = nl.at(i).toElement();
            elem.firstChild().setNodeValue(newValue);
        }
    }
}

void XMLEditor::deleteTagByAttrValue(Parameters pParam, Parameters parameters)
{
    //QDomNodeList nl = xmlFile.elementsByTagName(/*parameters.tag*/"Spec");
    QDomNodeList nl = xmlFile.elementsByTagName(pParam.tag);

    for (int i = 0; i < nl.count(); i++)
    {
        QDomNode node = nl.at(i);
        QDomElement child = node.firstChildElement(parameters.tag);
        //if (!child.isNull() && child.attribute(parameters.attr) == parameters.attrVal)
            node.removeChild(child);
    }
}

void XMLEditor::addNewTag(Parameters pParam, Parameters parameters)
{
    QDomNodeList parentList = xmlFile.elementsByTagName(pParam.tag);
    QDomElement parent;

    if (QString(pParam.attr) != "")
    {
        for (int i = 0; i < parentList.count(); i++)
        {
            QDomElement tmpParent = parentList.at(i).toElement();

            if (tmpParent.toElement().attribute(pParam.attr) == QString(pParam.attrVal))
            {
                parent = parentList.at(i).toElement();
                break;
            }
        }
    }
    else
        parent = parentList.at(0).toElement();

    QDomElement nodeTag = xmlFile.createElement(parameters.tag);
    QDomText nodeText;

    if (QString(parameters.val) != "")
    {
        nodeText = xmlFile.createTextNode(parameters.val);
        nodeTag.appendChild(nodeText);
    }

    if (QString(parameters.attr) != "")
        nodeTag.setAttribute(parameters.attr, parameters.attrVal);


    parent.appendChild(nodeTag);
}

IXMLEditor * getHandler()
{
    return new XMLEditor;
}
