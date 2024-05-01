#include "techs.h"

Techs::Techs(QString n, double p, int q, bool a, QPixmap i, int w):Products(n,p,q,a,i), warranty(w){}
void Techs:: setWarranty(int w)
{
    warranty=w;
}
int Techs:: getWarranty()
{
    return warranty;
}
void Techs:: displayDetails()
{
    qDebug() << "Name: " << name;
    qDebug() << "Price: " << price;
    qDebug() << "Quantity: " << quantity;
    qDebug() << "Availability: " << (availability ? "Available" : "Not available");
    qDebug() << "Warranty: " << warranty << " months";
}
