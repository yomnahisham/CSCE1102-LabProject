#include "products.h"


Products::Products(QString n, double p, int q, bool a, QPixmap i )
{
    name=n;
    price=p;
    quantity=q;
    availibilty=a;
    image=i;

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
void Products:: setAvailibilty(bool a)
{
    availibilty=a;
}
bool Products:: getAvailibilty()
{
    return availibilty;
}
void Products:: setImage(QPixmap i)
{
    image=i;
}
QPixmap Products:: getImage ()
{
    return image;
}
