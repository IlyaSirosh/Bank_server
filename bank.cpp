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

QString Bank::validateAccount(const QString& cardNumber, const QString& pin) const{

    QFile file("Accounts.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        //QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(" ");
        if(fields.at(0)==cardNumber)
            return "01";
    }
    file.close();
    return "00";
}

//Session* Bank::createSession(const QString& cardNumber, const QString& pin)const{
//    return new Session(this, cardNumber, pin);
//}

QString Bank::getBalance(const QString& cardNumber){
    QFile file("Accounts.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        //QMessageBox::information(0, "error", file.errorString());
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

QString Bank::withdraw(const QString& cardNumber, const int){
    QFile file("Accounts.txt");
    if(!file.open(QIODevice::ReadWrite)) {
        //QMessageBox::information(0, "error", file.errorString());
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

