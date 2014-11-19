#ifndef CRYPTER_H
#define CRYPTER_H

#include <QAction>
#include <QDebug>
#include <QtCrypto/QtCrypto>

class Crypter
{
public:
    Crypter();
    ~Crypter();

    static QString md5(QString msg);
    QString crypt(QString msg, QString myKey);
    QString deCrypt(QString msg, QString myKey);

    void setCipher(QString cipherName);

private:
    QCA::Initializer *init;
    QCA::Cipher *cipher;



};

#endif // CRYPTER_H
