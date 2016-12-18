#include "server.h"
#include "session.h"
#include <QDebug>

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

    qDebug()<<"newConnection"<<endl;

    bool connected = true;

    QStringList list;

    Session * session;


    while(connected){
        socket->waitForReadyRead(5000);
        QString data(socket->readAll());
        list = data.split(":");
        QString operation = list.at(0);
        if(operation == "01"){

            qDebug()<<"try to check card"<<endl;
                if(_bank.validateAccount(list.at(1))){
                    session=new Session(&_bank, list.at(1));
                    response("1",socket);
                }
                else{
                    response("0",socket);
                }
        }
        if(operation == "02"){
                if(session->validatePin(list.at(1))){
                    response("1",socket);
                }
                else{
                    response("0",socket);
                }
        }
       if(operation == "03"){
            response(session->getBalance(),socket);
       }
       if(operation == "04"){
           response(session->withdraw(list.at(1)),socket);
       }
       if(operation == "05"){

            connected = false;
        }



    }

    socket->flush();
    socket->close();

}

Server::~Server(){
    _server->close();
    _server = 0;
}
void Server::response(const QString & message, QTcpSocket * socket)
{
    QByteArray arr;
    arr.append(message);
    socket->write(arr);
}
