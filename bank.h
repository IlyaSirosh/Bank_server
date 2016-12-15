#ifndef BANK_H
#define BANK_H
#include <QObject>

friend class Session;

class Bank:public QObject
{
public:

    Bank (const QString&);
    Bank (const Bank&);
    ~Bank();
    bool validateAccount(const QString&, const QString&) const;
    Session* createSession(const QString&,const int) const;
    int getBalance(const QString&);
    char* withdraw(const QString&, const int);

private:

    QString _bankName;

};

#endif
