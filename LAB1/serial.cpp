#include "serial.h"

#include <QDebug>

QString SerializedBase::Serialize()
{
    QString data;
  for (int i = 1; i < this->metaObject()->propertyCount(); i++)
  {
     QMetaProperty prop = this->metaObject()->property(i);
     const char* propName = prop.name();
     data = static_cast<char *>((this->property(propName)).data());
  }
  return data;
}

bool SerializedBase::DeSerialize(QString *dataStream)
{
  for (int i = 1; i < this->metaObject()->propertyCount(); i++)
  {
     QMetaProperty prop = this->metaObject()->property(i);
     const char* propName = prop.name();
     QVariant v;
     //(void *)(*dataStream).toAscii().data();
     v.fromValue((void *)(*dataStream).toAscii().data());
     this->setProperty(propName, v);
  }
  return true;
}
