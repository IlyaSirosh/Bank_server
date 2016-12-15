#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include "bank.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();

    void start(int port);
    QString bankName = "Privat";
    void response(const QString &, QTcpSocket *);

signals:

public slots:
    void newConnection();

private:
    QTcpServer *_server;
    Bank _bank;
};

#endif // SERVER_H
