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
    explicit RegisterWindow(QWidget *parent = nullptr, AllUsers* Allusers = nullptr);
    ~RegisterWindow();

private slots:
    void on_backB_clicked();

    void on_regB_clicked();

private:
    Ui::RegisterWindow *ui;
    User* user;
    AllUsers* users;
};

#endif // REGISTERWINDOW_H
