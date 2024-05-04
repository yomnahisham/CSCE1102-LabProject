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
   // static void setPreferredAuthors(const vector<string>& authors);
    const vector<QString>& getPreferredGenres() const;
    // static const vector<string>& getPreferredAuthors();
    void virtualfunc();
private:
    vector<QString> preferredGenres;
   // static vector<std::string> preferredAuthors;



    //need to add credit cards??
};

#endif // CUSTOMER_H
