#include "loginwindow.h"
#include "allusers.h"
#include <QApplication>
#include <QScreen>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //using QScreen to take the measurements of the screen using the app
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    AllUsers allusers;
    allusers.LoadUsers(); //load all users
    qDebug()<< "finished loading";
    LoginWindow login (nullptr, &allusers);
    qDebug()<< "login created";
    login.resize(screenGeometry.width(), screenGeometry.height()); //resizing according to the QScreen measurements
    login.setWindowTitle("Login");
    login.show();

    return a.exec();



}
