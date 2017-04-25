#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_LoginButton_clicked()
{
    if(ui->nameLineEdit->text().length()==0){
        QMessageBox msgBox;
          msgBox.setText("Внимание!!!");
          msgBox.setIcon(QMessageBox::Information);
          msgBox.setInformativeText("Введите никнейм!!!");
          msgBox.exec();
    }else if(ui->passEdit->text().length()==0){
        QMessageBox msgBox;
          msgBox.setText("Внимание!!!");
          msgBox.setIcon(QMessageBox::Information);
          msgBox.setInformativeText("Введите пароль!!!");
          msgBox.exec();
    }else{
    MainWindow *mw=new MainWindow(ui->nameLineEdit->text(),ui->passEdit->text(),ui->address->text());
    mw->show();
    this->close();
    }

}

