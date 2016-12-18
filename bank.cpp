#include "bank.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
//#include <QtWidgets/QMessageBox>

Bank::Bank(const QString& name)
    :_bankName(name),accounts(QList<Account>())
{
    accounts.append(Account("abc","111","2000"));
    accounts.append(Account("def","222","4000"));
    accounts.append(Account("ghi","333","5000"));
}

Bank::Bank(const Bank & bank)
    :_bankName(bank._bankName)
{

}


Bank::~Bank()
{

}

bool Bank::validateAccount(const QString& cardNumber) const{
    QListIterator<Account> it(accounts);
    while(it.hasNext()){
        qDebug()<<"finding.."<<endl;
        if(it.next()._card==cardNumber)
        {
            qDebug()<<"i find"<<endl;
            return true;
        }
    }
    return false;
}

QString Bank::getBalance(const QString& cardNumber){
    QListIterator<Account>  it(accounts);
    while(it.hasNext()){
        Account acc = it.next();
        if(acc._card==cardNumber)
        {
            return acc._balance;
        }
    }
    return "0";
}

QString Bank::withdraw(const QString& cardNumber, const  QString& sum){
    QListIterator<Account>  it(accounts);
    int i = 0;
    while(it.hasNext()){
        Account acc = it.next();
        if(acc._card==cardNumber)
        {

            acc._balance=QString::number(acc._balance.toInt()-sum.toInt());
            accounts.replace(i,Account(acc._card,acc._pin,acc._balance));
            return "1";
        }
        i++;
    }


    return "0";
}

Bank::Account::Account(QString card,QString pin,QString balance):
    _card(card),_pin(pin),_balance(balance)
{
}

bool Bank::validatePin(const QString& cardNumber, const QString& pin){
    qDebug()<<"pin "<<pin<<endl;
    QListIterator<Account>  it(accounts);
    while(it.hasNext()){
        Account acc = it.next();
        if(acc._card==cardNumber)
        {

            return acc._pin == pin;
        }
    }

    return false;
}
