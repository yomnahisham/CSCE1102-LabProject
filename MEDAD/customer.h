#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "user.h"
#include "shoppingcart.h"

class Customer : public User
{
public:
    Customer();
    void AddAuthor(QString Author);
    void AddGenre (QString Genre);

private:
    ShoppingCart MyCart;
    //need to add credit cards??
    //need to add presonalized data
};

#endif // CUSTOMER_H
