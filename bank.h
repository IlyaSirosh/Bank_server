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
private:

    QString _bankName;

};

#endif
