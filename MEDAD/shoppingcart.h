#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "productmanager.h"
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
    void AddItemToTable();

private:
    Ui::ShoppingCart *ui;


};

#endif // SHOPPINGCART_H
