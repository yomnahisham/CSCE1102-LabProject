#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "user.h"
#include "allusers.h"
#include "products.h"
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QVector>
namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QWidget
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent, User *logged, AllUsers * all);
    ~ShoppingCart();
    AllUsers *users;
    User *user;
    struct CartItems{
        QPixmap pic;
        QString name;
        double price;
        int quantity;

        CartItems(const QPixmap &pp, const QString &n, double p, int q ) :pic(pp), name(n) , price(p), quantity(q) {} ;
    };
    static QVector<CartItems> Cart;
    QVector <Products*> cart;
    bool isExist;
    void AddItemToCart(const QPixmap image, const QString &ItemName, double price, int quantity);
    void updateTable();
    void deleteItem(int);
    void addQuantity(int);
    void subQuantity(int);
    void setCart (QVector<Products*> CART);

private slots:
    void on_DeleteItem_clicked();
    void handleItemDeletion();


    void on_returnHome_clicked();

    void on_CheckOutButton_clicked();

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
