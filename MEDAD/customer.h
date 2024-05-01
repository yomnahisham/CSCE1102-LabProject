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
    void setPreferredGenres(const vector<string>& genres);
   // static void setPreferredAuthors(const vector<string>& authors);
    const vector<string>& getPreferredGenres();
    // static const vector<string>& getPreferredAuthors();
    void virtualfunc();
private:
    vector<std::string> preferredGenres;
   // static vector<std::string> preferredAuthors;

    ShoppingCart MyCart;

    //need to add credit cards??
};

#endif // CUSTOMER_H
