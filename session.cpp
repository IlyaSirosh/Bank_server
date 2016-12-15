#include "bank.h"


Session::Session(QString& name)
    :_bankName(name)
{

}


Session (const Bank* bank , const QString& cardNumber)
{

}


Session::~Session()
{

}

char* Session::validatePin(const int pin) const{
    if(_pin == pin)return "01";
    return "00";
}

int Session::getBalance(){
    return this->bank.getBalance(_cardNumber);
}

int Session::withdraw(const int sum){
    return this->bank.withdraw(_cardNumber, sum);
}

