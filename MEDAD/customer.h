#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"
#include "shoppingcart.h"

#include <vector>
#include <string>

using namespace std;

class Customer : public User
{
public:
    Customer();
    static void setPreferredGenres(const vector<string>& genres);
   // static void setPreferredAuthors(const vector<string>& authors);
    static const vector<string>& getPreferredGenres();
    // static const vector<string>& getPreferredAuthors();

private:
    static vector<std::string> preferredGenres;
   // static vector<std::string> preferredAuthors;

    ShoppingCart MyCart;

    //need to add credit cards??
};

#endif // CUSTOMER_H
