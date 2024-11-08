#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"
#include "allusers.h"
#include "productmanager.h"
#include "shoppingcart.h"

#include <QScreen>

LoginWindow::LoginWindow(QWidget *parent, AllUsers* Allusers)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
    , users(Allusers)
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
    ui -> sellerB -> hide();
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
    ui -> sellerB -> hide();
    ui -> customerB -> hide();
    ui-> userL -> show();
    ui -> passL -> show();
    ui -> userLE -> show();
    ui -> passLE -> show();
    ui -> loginB -> show();

}


void LoginWindow::on_regB_clicked()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();


    RegisterWindow *reg = new RegisterWindow(nullptr, users);
    reg->resize(screenGeometry.width(), screenGeometry.height());
    reg -> setWindowTitle("Register");
    reg->show();
    hide();
}


void LoginWindow::on_loginB_clicked()
{
    qDebug()<< "type is" << UserType;

    QString username = ui -> userLE ->text();
    QString password = ui -> passLE ->text();

    //check fo username
    bool userExists = users-> AllUsers::userExists(UserType, username);

    //check for password
    loggedUser = users-> AllUsers::authenticateUser(UserType, username, password);

    if (!loggedUser)
        qDebug()<< "user not authenticated";

    //if both apply then go to productmanager window
    if (userExists&&loggedUser && password != "" && !loggedUser->isempty)
    {
        qDebug()<< "user found";

        QScreen* screen = QGuiApplication::primaryScreen();
        QRect screenGeometry = screen->geometry();
        ShoppingCart *cart = new ShoppingCart(nullptr, loggedUser, users);
        ProductManager* home = new ProductManager(nullptr, loggedUser, users, cart);
        home->resize(screenGeometry.width(), screenGeometry.height());
        home -> setWindowTitle("Home");
        home-> show();
        hide();
    }
    else
    {   //show accurate error messages and clear inaccurate LineEdits

        if (!userExists ||!loggedUser->isempty)
        {
            ui -> userError-> show();
            ui -> userLE -> setText("");

        }
        if (!loggedUser || password == "")
        {
            qDebug()<< "null ptr";
            ui -> passError -> show();
            ui -> passLE -> setText("");

        }

    }
}


void LoginWindow::on_sellerB_clicked()
{
    UserType = AllUsers::seller;
    ui ->LoginAsL -> hide();
    ui -> adminB -> hide();
    ui -> customerB -> hide();
    ui -> sellerB -> hide();
    ui-> userL -> show();
    ui -> passL -> show();
    ui -> userLE -> show();
    ui -> passLE -> show();
    ui -> loginB -> show();
}
