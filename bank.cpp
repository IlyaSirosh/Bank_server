#include "bank.h"


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

QString Bank::validateAccount(const QString& cardNumber, const int pin) const{

    QFile file("Accounts.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
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

Session* Bank::createSession(const QString& cardNumber, const int pin)const{
    return new Session(this*, cardNumber, pin);
}

int Bank::getBalance(const QString&){
    QFile file("Accounts.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
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

char* Bank::withdraw(const QString&, const int){
    QFile file("Accounts.txt");
    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
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

