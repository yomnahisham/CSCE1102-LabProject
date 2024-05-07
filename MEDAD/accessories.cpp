
#include "accessories.h"

Accessories::Accessories(QString n, double p, int q, bool a, QPixmap i, QString sel, QString t, QString s): Products(n,p,q,a,i,sel) , type(t) ,size(s){}

void Accessories:: setType(QString t)
{
    type=t;
}
QString Accessories:: getType()
{
    return type;
}
void Accessories:: setSize(QString s)
{
    size=s;
}
QString Accessories:: getSize()
{
    return size;
}

void Accessories::displayDetails()
{
    qDebug() << "Name: " << name;
    qDebug() << "Price: " << price;
    qDebug() << "Quantity: " << quantity;
    qDebug() << "Availability: " << (availability ? "Available" : "Not available");
    qDebug() << "Type: " << type;
    qDebug() << "Size: " << size;
}


