#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H


#include "products.h"
#include <QWidget>
#include <QTableWidget>

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QWidget
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ~ShoppingCart();
    void AddItemToCart(const QString &ItemName, double price, int quantity);

private:
    Ui::ShoppingCart *ui;


};

#endif // SHOPPINGCART_H
