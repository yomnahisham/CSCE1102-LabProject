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
