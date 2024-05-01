#include "loginwindow.h"
#include "allusers.h"
#include <QApplication>
#include"books.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AllUsers allusers;
    allusers.LoadUsers(); //load all users
    LoginWindow login (nullptr, &allusers);
    login.setWindowTitle("Login");
    login.show();
    return a.exec();



}
