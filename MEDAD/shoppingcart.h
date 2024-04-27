#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QWidget>

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QWidget
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ~ShoppingCart();

private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H
