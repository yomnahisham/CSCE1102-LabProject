#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H


#include "products.h"
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QWidget
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ~ShoppingCart();
    void AddItemToCart(const QPixmap image, const QString &ItemName, double price, int quantity);
    void deleteItem(int);
    void addQuantity(int);
    void subQuantity(int);



private slots:
    void on_DeleteItem_clicked();
    void handleItemDeletion();


private:
    Ui::ShoppingCart *ui;
    QTableWidgetItem *itemName ;
    QTableWidgetItem *itemPrice ;
    QTableWidgetItem *itemQuantity;
    QTableWidgetItem *pic;
    QWidget *buttonWidget;
    QPushButton *addButton;
    QPushButton *subButton;






};

#endif // SHOPPINGCART_H
