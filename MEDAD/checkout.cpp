#include "checkout.h"
#include "ui_checkout.h"

Checkout::Checkout(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Checkout)
{
    ui->setupUi(this);
}

Checkout::~Checkout()
{
    delete ui;
}
