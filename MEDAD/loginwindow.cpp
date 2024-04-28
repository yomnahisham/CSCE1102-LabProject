#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
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
    ui -> regB -> show();
    ui -> loginB -> show();
}


void LoginWindow::on_regB_clicked()
{
    RegisterWindow reg;
    reg.show();
    hide();
}


void LoginWindow::on_loginB_clicked()
{
    //check fo username
    bool userExists = false;

    //check for password
    bool passCorrect = false;


    //if both apply then go to productmanager window
    if (userExists&&passCorrect)
    {

    }
    else
    {   //show accurate error messages and clear inaccurate LineEdits

        if (!userExists)
        {
            ui -> userError-> show();
            ui -> userLE -> setText("");

        }
        if (!passCorrect)
        {
            ui -> passError -> show();
            ui -> passLE -> setText("");

        }

    }
}

