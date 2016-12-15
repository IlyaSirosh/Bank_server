#ifndef SESSION_H
#define SESSION_H
#include "bank.h"
#include <QObject>


class Session:public QObject
{
    Q_OBJECT
public:

    //struct BadSession;
    Session (Bank*, const QString&, const QString&);
    ~Session();
    QString validatePin(const QString&)const;
    QString getBalance();
    QString withdraw(const int);

private:
    Bank * _bank;
    QString _cardNumber;
    QString  _pin;
};

#endif // SESSION_H
