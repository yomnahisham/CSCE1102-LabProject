#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"


#include <vector>

using namespace std;

class Customer : public User
{
public:
    Customer();
    ~Customer();
    void setPreferredGenres(const vector<QString>& genres);
    const vector<QString>& getPreferredGenres() const;
    struct UserCart{
        QString name;
        int quant;
    };
    vector <UserCart> userCart;
    //void setShopingCart(const QVector <ShoppingCart::CartItems> cart);
    //const QVector <ShoppingCart::CartItems>& getShopingCart() const;
    void virtualfunc();
private:
    vector<QString> preferredGenres;
    bool emptyCart;

   // static vector<std::string> preferredAuthors;



    //need to add credit cards??
};

#endif // CUSTOMER_H
