#ifndef SESSION_H
#define SESSION_H

class Session
{
public:

    struct BadSession;
    Session (const Bank*, const QString&, const int);
    ~Session();
    char* validatePin(const int)const;
    int getBalance();
    int withdraw(const int);

private:
    Bank * _bank;
    QString _cardNumber;
    int  * _pin;
};

#endif // SESSION_H
