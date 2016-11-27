#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();

    void start(int port);

signals:

public slots:
    void newConnection();

private:
    QTcpServer *_server;
};

#endif // SERVER_H
