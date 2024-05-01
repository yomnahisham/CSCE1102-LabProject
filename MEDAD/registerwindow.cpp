#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "user.h"
#include "allusers.h"
#include "loginwindow.h"
#include "productmanager.h"
#include "customer.h"

#include <QDebug>
using namespace std;

RegisterWindow::RegisterWindow(QWidget *parent, AllUsers* Allusers)
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
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_backB_clicked()
{
    LoginWindow* login = new LoginWindow();
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
    vector<string> genres;
    if(ui->fantasy->isChecked()) {
        genres.push_back("Fantasy");
        hasChecks = true;
    }
    if(ui->mystery->isChecked()) {
        genres.push_back("Mystery");
        hasChecks = true;
    }
    if(ui->thriller->isChecked()) {
        genres.push_back("Thriller");
        hasChecks = true;
    }
    if(ui->selfHelp->isChecked()) {
        genres.push_back("SelfHelp");
        hasChecks = true;
    }
    if(ui->romance->isChecked()) {
        genres.push_back("Romance");
        hasChecks = true;
    }
    if(ui->horror->isChecked()) {
        genres.push_back("Horror");
        hasChecks = true;
    }   

    if (uniqueUser && repeatedPass && hasChecks)
    {
        users -> insert (AllUsers:: customer, username, password);
        user = users -> authenticateUser (AllUsers:: customer, username, password);
        Customer* cus = dynamic_cast<Customer*> (user);
        cus -> setPreferredGenres(genres);
        qDebug() << "Worked, sent genres into preferences.";
        ProductManager* home = new ProductManager();
        home-> setUser (user);
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

