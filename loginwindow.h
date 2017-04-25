#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
   // QString passwd;
private slots:
    void on_LoginButton_clicked();



private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
