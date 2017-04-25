
#include <QtWidgets/QMainWindow>
#include <QTcpSocket>


#include "ui_MainWindow.h"


class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

    public:


        explicit MainWindow(const QString& data,const QString& pass,const QString& ad,QWidget *parent=0);


    private slots:



        void lol();

        void rr();

        void cn();
        void inc();
    private:
        QString LLLLLLLLLILLLLL;
        Ui::MainWindow *ui;
        QTcpSocket *socket;
        QString LLLLLILLLLLLLLL;
        QString password;
        QString name1;
        QString name2;
};
