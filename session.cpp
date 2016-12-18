#include "session.h"
#include <QDebug>



Session::Session (Bank* bank , const QString& cardNumber):
    _bank(bank),
    _cardNumber(cardNumber)
{

}


Session::~Session()
{

}

bool Session::validatePin(const QString& pin) const{
    return _bank->validatePin(_cardNumber, pin);
}

QString Session::getBalance(){
    return _bank->getBalance(_cardNumber);
}

QString Session::withdraw(QString sum){
    return _bank->withdraw(_cardNumber, sum);
}

