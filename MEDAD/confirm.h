#ifndef CONFIRM_H
#define CONFIRM_H

#include <QWidget>
#include "checkout.h"
#include "shoppingcart.h"
#include "user.h"
#include "allusers.h"
namespace Ui {
class Confirm;
}

class Confirm : public QWidget
{
    Q_OBJECT

public:
    explicit Confirm(QWidget *parent, Checkout *c, ShoppingCart *cart, const Checkout::Address &address, const Checkout::CreditCard *creditcard, User *us, AllUsers *all);
    Checkout *checkout;
    ~Confirm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Confirm *ui;
    double Subtotal;
    double deliveryFee;
    double Total;
    QString Provice, Area, Street;
    QString PaymentMethod;
    bool isCredit;
    AllUsers *users;
    User *user;
    ShoppingCart *cartt;






};

#endif // CONFIRM_H
