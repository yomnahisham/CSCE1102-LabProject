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

        UserCart(const QString &n, int q) :name(n), quant(q) {};
    };

    void setShopingCart(const vector <UserCart> Cart);
    const vector <UserCart>& getShopingCart() const;
    void virtualfunc();
    void addToCartVec(const UserCart& items);
private:
    vector<QString> preferredGenres;
    bool emptyCart;
    vector <UserCart> userCart;

   // static vector<std::string> preferredAuthors;



    //need to add credit cards??
};

#endif // CUSTOMER_H
