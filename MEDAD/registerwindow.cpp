#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "user.h"
#include "allusers.h"
#include "loginwindow.h"
#include "productmanager.h"

#include <QDebug>
#include <QScreen>
using namespace std;

RegisterWindow::RegisterWindow(QWidget *parent, AllUsers* Allusers, AllUsers::Type type)
    : QWidget(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui -> userError -> hide();
    ui -> passError -> hide();
    ui->preferenceError->hide();
    users = Allusers;
    if (users)
    {
        qDebug()<< "coppied in reg successfully";
    }

    if (type == AllUsers::admin)
    {
        ui -> genreL -> hide();
        ui ->arabAmerican -> hide();
        ui ->classics -> hide();
        ui ->philo -> hide();
        ui ->comic -> hide();
        ui ->palestine -> hide();
        ui ->poetry -> hide();
        ui ->arabLit -> hide();

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

    LoginWindow* login = new LoginWindow(nullptr, users);
    login->resize(screenGeometry.width(), screenGeometry.height());
    login -> show();
    hide();
}


void RegisterWindow::on_regB_clicked()
{
    QString username = ui -> userLE -> text();
    bool uniqueUser = !users -> userExists(AllUsers::customer, username);

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

    if (uniqueUser && repeatedPass && hasChecks)
    {
        users -> insert (AllUsers:: customer, username, password, genres);
        user = users -> authenticateUser (AllUsers:: customer, username, password);

        QScreen* screen = QGuiApplication::primaryScreen();
        QRect screenGeometry = screen->geometry();

        ProductManager* home = new ProductManager(nullptr, user, users);
        home->resize(screenGeometry.width(), screenGeometry.height());
        home-> show();
        hide();
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

