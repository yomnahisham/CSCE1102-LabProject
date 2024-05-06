#ifndef CONFIRM_H
#define CONFIRM_H

#include <QWidget>
#include "checkout.h"

namespace Ui {
class Confirm;
}

class Confirm : public QWidget
{
    Q_OBJECT

public:
    explicit Confirm(QWidget *parent, Checkout *c,  const Checkout::Address &address);
    Checkout *checkout;
    ~Confirm();

private:
    Ui::Confirm *ui;
    double Subtotal;
    double deliveryFee;
    double Total;
    QString Provice, Area, Street;
    QString PaymentMethod;






};

#endif // CONFIRM_H
