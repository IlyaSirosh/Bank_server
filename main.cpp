#include <QCoreApplication>
#include "server.h"
#include "bank.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;

    server.start(9999);



    return a.exec();
}
