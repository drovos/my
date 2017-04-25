#include "server.h"
#include <QCoreApplication>
#include <locale.h>
#include <qmath.h>

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"rus");
    QCoreApplication app(argc, argv);
    Server *lll = new Server();
    lll->chto=lll->WOW();
    bool f = lll->listen(QHostAddress(),666);
    if(!f)
    {
        qFatal(QString("Ошибка. Не удается прослушать порт").toUtf8());
    }

    qDebug()<<lll->chto;
    return app.exec();
}
