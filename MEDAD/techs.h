#ifndef TECHS_H
#define TECHS_H
#include"products.h"
class Techs: public Products
{
protected:
    int warranty;
public:
    Techs(QString n, double p, int q, bool a, QPixmap i, int w);
    void setWarranty(int w);
    int getWarranty();

};

#endif // TECHS_H