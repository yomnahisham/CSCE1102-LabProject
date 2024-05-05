#ifndef ORDERCONFIRMATION_H
#define ORDERCONFIRMATION_H

#include "checkout.h"

namespace Ui {
class OrderConfirmation;
}

class OrderConfirmation :  public Checkout
{
    Q_OBJECT

public:
    explicit OrderConfirmation(QWidget *parent = nullptr);
    ~OrderConfirmation();

private:
    Ui::OrderConfirmation *ui;
    int DelieveryFee;
    int sub;
    int Total;
};

#endif // ORDERCONFIRMATION_H
