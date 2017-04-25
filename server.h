#ifndef SERVER_H
#define SERVER_H
#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>
#include <QTime>
class Server : public QTcpServer
{
    Q_OBJECT

    public:
        Server(QObject *parent=0);
        QString WOW()
        {
            QTime mn(0,0,0);
            qsrand(mn.secsTo(QTime::currentTime()));
           QString
           kek("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
           const int hz = 10*10/sqrt(100);

           QString rS;
           for(int i=0; i<hz; ++i)
           {
               int index = qrand() % kek.length();
               QChar nextChar = kek.at(index);
               rS.append(nextChar);
           }
           return rS;
        }
        QString chto;
    private slots:
        void rr();
        void ds();
        void s();

    protected:
        void incomingConnection(int i);

    private:

        QSet<QTcpSocket*> u;
        QMap<QTcpSocket*,QString> hah;
};

#endif // SERVER_H
