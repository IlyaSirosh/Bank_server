#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{


}

void Server::start(int port){

    _server = new QTcpServer(this);

    // whenever a user connects, it will emit signal
    connect(_server, SIGNAL(newConnection()),
            this, SLOT(newConnection()));

    if(!_server->listen(QHostAddress::Any, port))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
    }

}


void Server::newConnection(){

    QTcpSocket *socket = _server->nextPendingConnection();

    bool connected = true;

    while(connected){

        connected = false;


    }

    socket->flush();
    socket->close();

}

Server::~Server(){
    _server->close();
    _server = 0;
}
