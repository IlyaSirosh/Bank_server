#include <QCoreApplication>
#include "server.h"
#include "bank.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;

    server.start(3333);

    //Bank bank("aaa");

    //bank.validateAccount("aaa","bbb");

    return a.exec();
}
