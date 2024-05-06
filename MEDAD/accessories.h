#ifndef ACCESSORIES_H
#define ACCESSORIES_H
#include"products.h"
class Accessories : public Products
{
protected:
    QString type;
    char size;

public:
    Accessories(QString n, double p, int q, bool a, QPixmap i, QString sel, QString t, char s );
    void setType(QString t);
    QString getType();
    void setSize(char s);
    char getSize();
    void displayDetails();



};

#endif // ACCESSORIES_H
