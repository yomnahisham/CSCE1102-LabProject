#include "confirm.h"
#include "ui_confirm.h"
#include "checkout.h"

Confirm::Confirm(QWidget *parent, Checkout *c)
    : QWidget(parent)
    , ui(new Ui::Confirm)
{
    ui->setupUi(this);
    checkout = c;
    deliveryFee = checkout->getDeliveryFee();
    Total = checkout->getTotal();
    Subtotal = checkout ->getSubTotal();

    ui->TotalLabel->setText("Total: " + QString("EGP %1").arg(Total, 0, 'f', 2));
    ui->DeliveryLabel->setText("Delivery Fee: " + QString("EGP %1").arg(deliveryFee, 0, 'f', 2));
    ui->SubTotalLabel->setText("SubTotal: " + QString("EGP %1").arg(Subtotal, 0, 'f', 2));

}

Confirm::~Confirm()
{
    delete ui;
}
