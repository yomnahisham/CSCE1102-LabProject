#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H



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
    explicit ShoppingCart(QWidget *parent = nullptr);
    ~ShoppingCart();
    void AddItemToCart(const QPixmap image, const QString &ItemName, double price, int quantity);
    void deleteItem(int);
    void addQuantity(int);
    void subQuantity(int);
    struct CartItems{
        QString name;
        double price;
        int quantity;

        CartItems(const QString n, double p, int q ) : name(n) , price(p), quantity(q) {} ;
    };
    QVector<CartItems> Items;



private slots:
    void on_DeleteItem_clicked();
    void handleItemDeletion();


    void on_returnHome_clicked();

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
