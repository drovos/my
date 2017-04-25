#include "server.h"
#include <QTcpSocket>
#include <QRegExp>
#include <locale.h>
#include <QTime>
Server::Server(QObject *parent) : QTcpServer(parent)
{
    setlocale(LC_ALL,"rus");
}

void Server::incomingConnection(int i)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(i);
    u.insert(client);
    qDebug() << "Новый пользователь. Онлайн:  "+QString::number(u.size()) << client->peerAddress().toString();

    connect(client, SIGNAL(readyRead()), this, SLOT(rr()));
    connect(client, SIGNAL(disconnected()), this, SLOT(ds()));

}

void Server::rr()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    QTime time=QTime::currentTime();
    while(client->canReadLine())
    {

        QString line = QString::fromUtf8(client->readLine()).trimmed();
        QRegExp hm("^/yo:(.*):/kek:(.*)$");
        if(hm.indexIn(line) != -1)
        {
            QString user = hm.cap(1);
            hah[client] = user;
            QString sus=hm.cap(2);
            qDebug()<<user<<" : "<<sus;
            if(this->chto!=sus){
                qDebug()<<"intruder: "<<user<<client->peerAddress().toString();
                client->disconnectFromHost();
            }else
            foreach(QTcpSocket *client, u)
                client->write(QString(user + " присоединился.\n").toUtf8());
            s();
        }
        else if(hah.contains(client))
        {
            QString message = line;
            QString user = hah[client];
            qDebug() << user+": "+ message;


            foreach(QTcpSocket *otherClient, u)
                otherClient->write(QString("["+time.toString()+"]<b> "+user + "</b>: " + message + "\n").toUtf8());
        }
        else
        {
            qWarning() << "Некорректное сообщение:" << client->peerAddress().toString() << line;
        }
    }
}

void Server::ds()
{
    QTcpSocket *client = (QTcpSocket*)sender();
    qDebug() << "Клиент отключился:"+hah[client]+" " << client->peerAddress().toString();

    u.remove(client);

    QString user = hah[client];
    hah.remove(client);

    s();
    foreach(QTcpSocket *client, u)
        client->write(QString(user + " отсоединился.\n").toUtf8());
}

void Server::s()
{
    QStringList lol;
    foreach(QString a, hah.values())
        lol << a;

    foreach(QTcpSocket *client, u)
        client->write(QString("/mom:" + lol.join(",") + "\n").toUtf8());
}
