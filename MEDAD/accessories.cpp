#include "accessories.h"

Accessories::Accessories(QString n, double p, int q, bool a, QPixmap i, QString sel, QString t, char s): Products(n,p,q,a,i,sel) , type(t) ,size(s){}

void Accessories:: setType(QString t)
{
    type=t;
}
QString Accessories:: getType()
{
    return type;
}
void Accessories:: setSize(char s)
{
    size=s;
}
char Accessories:: getSize()
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


