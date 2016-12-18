#ifndef BANK_H
#define BANK_H
#include <QObject>

//class Session;


class Bank:public QObject
{
    Q_OBJECT
public:

    //friend class Session;
    explicit Bank (const QString&);
    Bank (const Bank&);
    ~Bank();
    bool validateAccount(const QString&) const;
    QString getBalance(const QString&);
    QString withdraw(const QString&, const QString&);
    bool validatePin(const QString&, const QString&);
private:

    QString _bankName;
    class Account{
        public:
        QString _card;
        QString _pin;
        QString _balance;
            Account(QString card,QString pin,QString balance);
            ~Account(){}
    };
    QList<Account> accounts;
};

#endif
