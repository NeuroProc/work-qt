#include "crypter.h"

Crypter::Crypter()
{
    //initialize QCA
    init = new QCA::Initializer;
    cipher =  new QCA::Cipher("aes128", QCA::Cipher::CBC);
}

Crypter::~Crypter()
{
    delete cipher;
    delete init;
}

QString Crypter::md5(QString msg)
{
    if(!QCA::isSupported("md5"))
        qDebug() << "EE: MD5 not supported!";

    QCA::Hash hash("md5");

    hash.update(msg.toAscii());

    return hash.final().toByteArray().toHex();
}

QString Crypter::crypt(QString msg, QString myKey)
{
    QCA::SymmetricKey key(myKey.toAscii());
    QCA::InitializationVector iv(myKey.toAscii());

    //set the cipher mode to decryption
    cipher->setup(QCA::Encode, key, iv);

    QCA::SecureArray secureData = msg.toAscii();
    QCA::SecureArray encryptedData = cipher->process(secureData);

    //check if encryption succeded
    if (!cipher->ok())
    {
        qDebug() << "EE: Encryption failed!";
        return "";
    }


    //display the result
    //qDebug() << QString(qPrintable(QCA::arrayToHex(encryptedData.toByteArray())));

    return QString(qPrintable(QCA::arrayToHex(encryptedData.toByteArray())));
}

QString Crypter::deCrypt(QString msg, QString myKey)
{
    QCA::SymmetricKey key(myKey.toAscii());
    QCA::InitializationVector iv(myKey.toAscii());

    //set the cipher mode to decryption
    cipher->setup(QCA::Decode, key, iv);

    QCA::SecureArray secureData = QCA::hexToArray(msg);
    QCA::SecureArray decryptedData = cipher->process(secureData);

    //check if decryption succeded
    if (!cipher->ok())
    {
        qDebug() << "EE: Decryption failed!";
        return "";
    }

    //qDebug() << QString(decryptedData.data());

    return QString(decryptedData.data());
}

void Crypter::setCipher(QString cipherName)
{
    *cipher = QCA::Cipher(cipherName, QCA::Cipher::CBC);
}

