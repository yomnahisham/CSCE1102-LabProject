#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "user.h"
#include "allusers.h"
#include "loginwindow.h"
#include "productmanager.h"

RegisterWindow::RegisterWindow(QWidget *parent, AllUsers* Allusers)
    : QWidget(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui -> userError -> hide();
    ui -> passError -> hide();
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

    if (uniqueUser && repeatedPass)
    {
        users -> insert (AllUsers:: customer, username, password);
        user = users -> authenticateUser (AllUsers:: customer, username, password);
        ProductManager* home = new ProductManager();
        home-> setUser (user);
        home-> show();
        hide();

        //add prefrences
    }else
    {
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
    }

}

