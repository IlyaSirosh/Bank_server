#include "server.h"
#include "session.h"

Server::Server(QObject *parent) : QObject(parent), _bank(bankName)
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

    QString data;

    QStringList list;

    Session session;

    while(connected){
        data = _server->readAll();
        list = data.split(":");
        switch(list.at(0))
        {
            case "01":
                if(_bank.validate(list.at(1))){
                    session(list.at(1));
                    server->write("1");
                }
                else{
                    server->write("0");
                }
            case "02":
                if(session.validatePin(list.at(1))){
                    server->write("1");
                }
                else{
                    server->write("0");
                }
            case "03":
                server->write(session.getBalance());
            case "04":
                server->write(session.withDraw(list.at(1)));
            case "04":
                server->close();
            server->flush();
        }

        connected = false;
    }

    socket->flush();
    socket->close();

}

Server::~Server(){
    _server->close();
    _server = 0;
}
