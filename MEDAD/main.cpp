#include "loginwindow.h"
#include "allusers.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AllUsers allusers;
    allusers.LoadUsers(); //load all users
    LoginWindow login;
    login.show();
    return a.exec();
}
