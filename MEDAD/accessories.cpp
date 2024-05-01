#include "accessories.h"

Accessories::Accessories(QString n, double p, int q, bool a, QPixmap i, QString t, char s): Products(n,p,q,a,i) , type(t) ,size(s){}

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
