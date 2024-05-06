#ifndef PRODUCTS_H
#define PRODUCTS_H
#include<QPixmap>
#include<Qstring>
#include<QDebug>

class Products
{
protected:
    QString name;
    double price;
    int quantity;
    bool availability;
    QPixmap image;
    QString seller;


public:
    Products(QString n, double p, int q, bool a, QPixmap i , QString s );
    virtual void displayDetails();
    void setName(QString n);
    QString getName();
    void setPrice(double p);
    double getPrice();
    void setQuantity(int q);
    int getQuantity();
    void setAvailability(bool a);
    bool getAvailability();
    void setImage(QPixmap i);
    QPixmap getImage ();
    void setSeller(QString s);
    QString getSeller();

};

#endif // PRODUCTS_H
