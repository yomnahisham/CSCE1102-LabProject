#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include "allusers.h"

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr, AllUsers* Allusers = nullptr);
    ~LoginWindow();

private slots:
    void on_customerB_clicked();

    void on_adminB_clicked();

    void on_regB_clicked();

    void on_loginB_clicked();

    void on_sellerB_clicked();

private:
    Ui::LoginWindow *ui;
    AllUsers* users;
    User* loggedUser;
    AllUsers::Type UserType;

};

#endif // LOGINWINDOW_H
