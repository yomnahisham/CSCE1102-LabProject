#ifndef PRODUCTS_H
#define PRODUCTS_H
#include<QPixmap>
#include<Qstring>
class Products
{
protected:
    QString name;
    double price;
    int quantity;
    bool availibilty;
    QPixmap image;


public:
    Products(QString n, double p, int q, bool a, QPixmap i );
    void setName(QString n);
    QString getName();
    void setPrice(double p);
    double getPrice();
    void setQuantity(int q);
    int getQuantity();
    void setAvailibilty(bool a);
    bool getAvailibilty();
    void setImage(QPixmap i);
    QPixmap getImage ();
};

#endif // PRODUCTS_H
