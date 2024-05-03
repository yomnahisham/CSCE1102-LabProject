#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H
#include "user.h"
#include "allusers.h"
#include <QWidget>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr, AllUsers* Allusers = nullptr, AllUsers::Type type = AllUsers::customer, Admin* ogAdmin = nullptr);
    ~RegisterWindow();

private slots:
    void on_backB_clicked();

    void on_regB_clicked();

    void on_returnB_clicked();

    void on_loginB_clicked();

private:
    Ui::RegisterWindow *ui;
    User* user;
    AllUsers* users;
    AllUsers::Type type;
    Admin* admin;
};

#endif // REGISTERWINDOW_H
