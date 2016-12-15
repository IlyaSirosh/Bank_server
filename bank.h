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
    QString validateAccount(const QString&, const QString&) const;
    //Session* createSession(const QString&,const QString&) const;
    QString getBalance(const QString&);
    QString withdraw(const QString&, const int);
private:

    QString _bankName;

};

#endif
