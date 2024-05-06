#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "user.h"
#include "allusers.h"
#include "loginwindow.h"
#include "productmanager.h"
#include "shoppingcart.h"

#include <QDebug>
#include <QScreen>
using namespace std;

RegisterWindow::RegisterWindow(QWidget *parent, AllUsers* Allusers, AllUsers::Type type, User* ogUser)
    : QWidget(parent)
    , ui(new Ui::RegisterWindow)
    ,users(Allusers)
    , type(type)
    ,ogUser (ogUser)
{
    ui->setupUi(this);
    ui -> userError -> hide();
    ui -> passError -> hide();
    ui->preferenceError->hide();
    ui -> loginB -> hide();
    ui -> returnB -> hide();

    if (type == AllUsers::admin)
    {
        ui -> genreL -> hide();
        ui -> genreLab -> hide();
    } else if (type == AllUsers::seller)
    {
        ui -> genreL -> hide();
        ui -> genreLab -> hide();
    }
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_backB_clicked()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    if (type == AllUsers::customer)
    {    LoginWindow* login = new LoginWindow(nullptr, users);
        login->resize(screenGeometry.width(), screenGeometry.height());
        login -> setWindowTitle("Login");
        login -> show();
        hide();
    }else{
        ShoppingCart *cart = new ShoppingCart(nullptr, user, users);
        ProductManager* home = new ProductManager(nullptr, ogUser, users, cart);
        home -> setWindowTitle("Home");
        home->resize(screenGeometry.width(), screenGeometry.height());
        home-> show();
        hide();
    }
}


void RegisterWindow::on_regB_clicked()
{
    QString username = ui -> userLE -> text();
    bool uniqueUser = !users -> userExists(type, username);

    bool repeatedPass;
    QString password = ui-> passLE -> text() ;
    if (password == ui -> passRLE -> text() && password != "")
        repeatedPass = true;
    else
        repeatedPass = false;


    bool hasChecks = false;
    vector<QString> genres;
    if(ui->classics->isChecked()) {
        genres.push_back("Classics");
        hasChecks = true;
    }
    if(ui->arabLit->isChecked()) {
        genres.push_back("Arabic-Literature");
        hasChecks = true;
    }
    if(ui->philo->isChecked()) {
        genres.push_back("Philosophy");
        hasChecks = true;
    }
    if(ui->poetry->isChecked()) {
        genres.push_back("Poetry");
        hasChecks = true;
    }
    if(ui->palestine->isChecked()) {
        genres.push_back("Palestine");
        hasChecks = true;
    }
    if(ui->arabAmerican->isChecked()) {
        genres.push_back("Arab-American");
        hasChecks = true;
    }
    if(ui->comic->isChecked()) {
        genres.push_back("Comic-Books");
        hasChecks = true;
    }

    if (type != AllUsers::customer)
        hasChecks = true;

    if (uniqueUser && repeatedPass && hasChecks)
    {
        users -> insert (type, username, password, genres);
        user = users -> authenticateUser (type, username, password);
        qDebug()<< "entered conditions";

        if (type == AllUsers::customer)
        {
            QScreen* screen = QGuiApplication::primaryScreen();
            QRect screenGeometry = screen->geometry();
            ShoppingCart *cart = new ShoppingCart(nullptr, user, users);
            ProductManager* home = new ProductManager(nullptr, user, users, cart);
            home -> setWindowTitle("Home");
            home->resize(screenGeometry.width(), screenGeometry.height());
            home-> show();
            hide();
        }else
        {
            ui-> loginB -> show();
            ui -> returnB -> show();
            ui -> userError -> hide();
            ui -> userL -> hide();
            ui -> userLE -> hide();
            ui -> passError -> hide();
            ui -> passL -> hide();
            ui -> passLE -> hide();
            ui -> passRL -> hide();
            ui -> passRLE -> hide();
            ui -> backB -> hide();
            ui -> regB -> hide();
        }
    }else {

        if (!uniqueUser)
        {   ui -> userError -> show();
            ui -> userLE -> setText("");
        }
        if (!repeatedPass)
        {
            ui -> passLE -> setText("");
            ui -> passRLE -> setText("");
            ui -> passError -> show();
        }
        if(!hasChecks) {
            ui->preferenceError->show();
        }
    }

}


void RegisterWindow::on_returnB_clicked()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    ShoppingCart *cart = new ShoppingCart(nullptr, user, users);
    ProductManager* home = new ProductManager(nullptr, ogUser, users, cart);
    home -> setWindowTitle("Home");
    home->resize(screenGeometry.width(), screenGeometry.height());
    home-> show();
    hide();
}


void RegisterWindow::on_loginB_clicked()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    ShoppingCart *cart = new ShoppingCart(nullptr, user, users);
    ProductManager* home = new ProductManager(nullptr, user, users, cart);
    home -> setWindowTitle("Home");
    home->resize(screenGeometry.width(), screenGeometry.height());
    home-> show();
    hide();
}

