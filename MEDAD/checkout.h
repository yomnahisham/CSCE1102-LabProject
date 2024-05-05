#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "shoppingcart.h"
#include <QWidget>
#include <QVector>

namespace Ui {
class Checkout;
}

class Checkout : public QWidget
{
    Q_OBJECT

public:
    explicit Checkout(QWidget *parent, QVector<ShoppingCart::CartItems>itemsInCart);
    ~Checkout();
    void SaveCreditInfo();
protected:
    int CVV[3];
    QString CardNum;
    int Month;
    int Year;





private slots:
    void on_pushButton_clicked();


private:
    Ui::Checkout *ui;
    double Total;
    double subTotal;
    double deliveryFee;

};

#endif // CHECKOUT_H
