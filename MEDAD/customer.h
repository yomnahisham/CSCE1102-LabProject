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
    struct UserCreditCard{
        int CVV;
        QString CardNum;
        int Month;
        int Year;

        UserCreditCard(int c, const QString& card, int m, int y) : CVV(c), CardNum(card), Month(m), Year(y){};

    };
    struct UserAddress{

        QString Province;
        QString Area;
        QString Street;
        QString Building;
        int Floor;
        int Apartment;
        QString PhoneNumber;

        UserAddress(const QString& p, const QString& a,const QString& s, const QString& b, int f, int ap, const QString& ph):
            Province(p) , Area(a), Street(s), Building(b), Floor(f), Apartment(ap), PhoneNumber(ph) {};

    };

    void setShopingCart(const vector <UserCart> Cart);
    const vector <UserCart>& getShopingCart() const;
    void virtualfunc();
    void addToCartVec(const UserCart& items);
private:
    vector<QString> preferredGenres;
    bool emptyCart;
    vector <UserCart> userCart;
    vector <UserCreditCard> userCredit;
    vector <UserAddress> userAddress;



   // static vector<std::string> preferredAuthors;



    //need to add credit cards??
};

#endif // CUSTOMER_H
