#include "orderconfirmation.h"
#include "ui_orderconfirmation.h"

OrderConfirmation::OrderConfirmation(QWidget *parent)
    , ui(new Ui::OrderConfirmation)
{
    ui->setupUi(this);
}

OrderConfirmation::~OrderConfirmation()
{
    delete ui;
}
