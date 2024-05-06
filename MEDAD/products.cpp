#include "products.h"


Products::Products(QString n, double p, int q, bool a, QPixmap i,QString s )
{
    name=n;
    price=p;
    quantity=q;
    availability=a;
    image=i;
    seller=s;

}
void Products::setSeller(QString s)
{
    seller=s;
}
QString Products::getSeller()
{
    return seller;
}
void Products::setName(QString n)
{
    name=n;
}
QString Products:: getName()
{
    return name;
}
void Products:: setPrice(double p)
{
    price=p;
}
double Products:: getPrice()
{
    return price;
}
void Products:: setQuantity(int q)
{
    quantity=q;
}
int Products:: getQuantity()
{
    return quantity;
}
void Products:: setAvailability(bool a)
{
    availability=a;
}
bool Products:: getAvailability()
{
    return availability;
}
void Products:: setImage(QPixmap i)
{
    image=i;
}
QPixmap Products:: getImage ()
{
    return image;
}
void Products::displayDetails()
{
    qDebug() << "Name: " << name;
    qDebug() << "Price: " << price;
    qDebug() << "Quantity: " << quantity;
    qDebug() << "Availability: " << (availability ? "Available" : "Not available");

}
