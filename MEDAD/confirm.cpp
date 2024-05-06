#include "confirm.h"
#include "ui_confirm.h"
#include "checkout.h"
#include <QScreen>
#include "productmanager.h"
Confirm::Confirm(QWidget *parent, Checkout *c, ShoppingCart *cart, const Checkout::Address &address, const Checkout::CreditCard *creditcard, User *us, AllUsers *all)
    : QWidget(parent)
    , ui(new Ui::Confirm)
{
    ui->setupUi(this);
    checkout = c;
    deliveryFee = checkout->getDeliveryFee();
    Total = checkout->getTotal();
    Subtotal = checkout ->getSubTotal();

    user = us;
    users = all;

    cartt = cart;

    ui->TotalLabel->setText("Total: " + QString("EGP %1").arg(Total, 0, 'f', 2));
    ui->DeliveryLabel->setText("Delivery Fee: " + QString("EGP %1").arg(deliveryFee, 0, 'f', 2));
    ui->SubTotalLabel->setText("SubTotal: " + QString("EGP %1").arg(Subtotal, 0, 'f', 2));
    ui->DeliveryDate-> setText(" 5 buisness days");

    if(creditcard != nullptr){
        ui->PaymentMethod->setText("Credit Card, ****" +creditcard->CardNum.right(4));

    }else{
        ui->PaymentMethod->setText("Cash on delivery (COD)");
    }

    ui->AddressLabel->setText(address.Province + " , " + address.Area + " , " + address.Street);

}

Confirm::~Confirm()
{
    delete ui;
}

void Confirm::on_pushButton_clicked()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    ProductManager *productManager = new ProductManager(nullptr, user, users, cartt);
    productManager->resize(screenGeometry.width(), screenGeometry.height());
    productManager->show();
    this->hide();
}

