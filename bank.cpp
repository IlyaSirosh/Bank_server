#include "bank.h"
#include <QFile>
#include <QTextStream>
//#include <QtWidgets/QMessageBox>

Bank::Bank(const QString& name)
    :_bankName(name)
{

}

Bank::Bank(const Bank & bank)
    :_bankName(bank._bankName)
{

}


Bank::~Bank()
{

}

bool Bank::validateAccount(const QString& cardNumber) const{

    QFile file("Accounts.txt");
    if(!file.open(QIODevice::ReadOnly)) {
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");
        if(fields.at(0)==cardNumber)
            return true;
    }
    file.close();
    return false;
}

QString Bank::getBalance(const QString& cardNumber){
    QFile file("Accounts.txt");
    if(!file.open(QIODevice::ReadOnly)) {
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");
        if(fields.at(0)==cardNumber)
            return fields.at(2);
    }
    file.close();
    return "00";
}

QString Bank::withdraw(const QString& cardNumber, const  QString& sum){
    QFile file("Accounts.txt");
    if(!file.open(QIODevice::ReadWrite)) {
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");
        if(fields.at(0)==cardNumber)
            return fields.at(2);
    }
    file.close();
    return "00";
}

