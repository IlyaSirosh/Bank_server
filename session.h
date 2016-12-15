#ifndef SESSION_H
#define SESSION_H
#include "bank.h"
#include <QObject>


class Session:public QObject
{
    Q_OBJECT
public:

    Session (Bank*, const QString&);
    ~Session();
    bool validatePin(const QString&)const;
    QString getBalance();
    QString withdraw(QString);

private:
    Bank *   _bank;
    QString  _cardNumber;
    QString  _pin;
};

#endif // SESSION_H
