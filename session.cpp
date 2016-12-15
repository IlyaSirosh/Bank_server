#include "session.h"




Session::Session (Bank* bank , const QString& cardNumber,const QString& pin):
    _bank(bank),
    _cardNumber(cardNumber),
    _pin(pin)
{

}


Session::~Session()
{

}

QString Session::validatePin(const QString& pin) const{
    if(_pin == pin)return "01";
    return "00";
}

QString Session::getBalance(){
    return _bank->getBalance(_cardNumber);
}

QString Session::withdraw(const int sum){
    return _bank->withdraw(_cardNumber, sum);
}

