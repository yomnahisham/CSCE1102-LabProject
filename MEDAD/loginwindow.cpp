#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"
#include "allusers.h"
#include "productmanager.h"

LoginWindow::LoginWindow(QWidget *parent, AllUsers* Allusers)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui-> userL -> hide();
    ui -> passL -> hide();
    ui -> userLE -> hide();
    ui -> passLE -> hide();
    ui -> passError -> hide();
    ui -> userError -> hide();
    ui -> regB -> hide();
    ui -> loginB -> hide();
    users = Allusers;
    if (users)
    {
        qDebug()<< "coppied successfully";
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_customerB_clicked()
{
    UserType = AllUsers::customer;
    ui ->LoginAsL -> hide();
    ui -> adminB -> hide();
    ui -> customerB -> hide();
    ui-> userL -> show();
    ui -> passL -> show();
    ui -> userLE -> show();
    ui -> passLE -> show();
    ui -> regB -> show();
    ui -> loginB -> show();
}


void LoginWindow::on_adminB_clicked()
{
    UserType = AllUsers::admin;
    ui ->LoginAsL -> hide();
    ui -> adminB -> hide();
    ui -> customerB -> hide();
    ui-> userL -> show();
    ui -> passL -> show();
    ui -> userLE -> show();
    ui -> passLE -> show();
    ui -> loginB -> show();

}


void LoginWindow::on_regB_clicked()
{
    RegisterWindow *reg = new RegisterWindow(nullptr, users);
    reg->show();
    hide();
}


void LoginWindow::on_loginB_clicked()
{
    QString username = ui -> userLE ->text();
    QString password = ui -> passLE ->text();

    //check fo username
    bool userExists = users-> AllUsers::userExists(UserType, username);

    //check for password
    loggedUser = users-> AllUsers::authenticateUser(UserType, username, password);



    //if both apply then go to productmanager window
    if (userExists&&loggedUser)
    {
        qDebug()<< "user found";
        ProductManager* home = new ProductManager();
        home-> setUser (loggedUser);
        home-> show();
        hide();
    }
    else
    {   //show accurate error messages and clear inaccurate LineEdits

        if (!userExists)
        {
            ui -> userError-> show();
            ui -> userLE -> setText("");

        }
        if (!loggedUser)
        {
            qDebug()<< "null ptr";
            ui -> passError -> show();
            ui -> passLE -> setText("");

        }

    }
}
