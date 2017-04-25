#include "MainWindow.h"

#include <QRegExp>

MainWindow::MainWindow(const QString& data,const QString& pass,const QString& ad,QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    password=pass;
    name1=data;
    name2=name1;
    LLLLLLLLLILLLLL=name2;
    name1=name2;
    name2=password;
    LLLLLILLLLLLLLL=name2;
    setAttribute(Qt::WA_DeleteOnClose, true);
    MyLabel->setText("Вы - "+name1);
    this->setWindowTitle("Chat - "+name1);
    socket = new QTcpSocket(this);
    socket->connectToHost(ad, 666);
    connect(socket, SIGNAL(readyRead()), this, SLOT(rr()));
    connect(socket, SIGNAL(connected()), this, SLOT(cn()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(inc()));
    connect(this->SendLineEdit,SIGNAL(returnPressed()),this,SLOT(lol()));
    connect(this->SendButton,SIGNAL(clicked(bool)),this,SLOT(lol()));
}
void MainWindow::lol()
{
    QString message = SendLineEdit->text().trimmed();

    if(!message.isEmpty())
    {
        socket->write(QString(message + "\n").toUtf8());
    }

    SendLineEdit->clear();

    SendLineEdit->setFocus();
}


void MainWindow::rr()
{
    while(socket->canReadLine())
    {
        QString line = QString::fromUtf8(socket->readLine()).trimmed();
        QRegExp tomat("^([^:]+):(.*)$");
        QRegExp bread("/mom:(.*)$");
        if(bread.indexIn(line) != -1)
        {

            QStringList users = bread.cap(1).split(",");
            userListWidget->clear();
            foreach(QString user, users)
                new QListWidgetItem(user, userListWidget);
        }

        else if(tomat.indexIn(line) != -1)
        {

            QString user = tomat.cap(1);
            QString message = tomat.cap(2);

            Messages->append(user + " : " + message);
        }
    }
}

void MainWindow::inc()
{
    Messages->append("GO AWAY\n");
    socket->close();

}

void MainWindow::cn()
{

    SendLineEdit->setFocus();
    socket->write(QString("/yo:" + LLLLLLLLLILLLLL +":"+"/kek:"+LLLLLILLLLLLLLL + "\n").toUtf8());

}
