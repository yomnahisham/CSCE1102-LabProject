#include "loginwinodw.h"
#include "ui_loginwinodw.h"

LoginWinodw::LoginWinodw(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWinodw)
{
    ui->setupUi(this);
}

LoginWinodw::~LoginWinodw()
{
    delete ui;
}
