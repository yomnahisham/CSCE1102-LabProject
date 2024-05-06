#ifndef ACCESSORIES_H
#define ACCESSORIES_H
#include"products.h"
class Accessories : public Products
{
protected:
    QString type;
    QString size;

public:
    Accessories(QString n, double p, int q, bool a, QPixmap i, QString sel, QString t, QString s );
    void setType(QString t);
    QString getType();
    void setSize(QString s);
    QString getSize();
    void displayDetails();



};

#endif // ACCESSORIES_H
