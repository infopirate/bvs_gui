#ifndef BALLOT_H
#define BALLOT_H

#include <QString>
#include <QStringList>

class Ballot
{
public:
    Ballot();

    void setUid(QString uid);
    QString getUid();

    QString getName();
    void setName(QString name);

    QString getLogo();
    void setLogo(QString logo);

    QString getText();
    void setText(QString text);

    QString getWalletAddress();
    void setWalletAddress(QString walletAdress);

    QStringList getOptions();
    void setOptionsStrList(QStringList options);

private:

    QString uid;
    QString name;
    QString logo;
    QString text;
    QString walletAddress;
    QStringList options;
};

#endif // BALLOT_H
