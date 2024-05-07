#ifndef ALLUSERS_H
#define ALLUSERS_H
#include "user.h"
#include "customer.h"
#include "admin.h"
#include "seller.h"


class AllUsers
{
public:
    AllUsers();
    AllUsers& operator=(AllUsers& other);
    enum Type {admin, customer, seller};
    Customer* AllCustomers;
    Admin* AllAdmins;
    Seller* AllSellers;
    void SaveUsers ();
    void LoadUsers();
    User* authenticateUser(Type type , QString u, QString p);
    void insert (Type type, QString u, QString p, vector<QString> genres = vector<QString>(),bool active = true,vector <Customer::UserCart> cart = vector <Customer::UserCart>(),vector <Customer::UserAddress> add = vector <Customer::UserAddress> (),vector <Customer::UserCreditCard> cc = vector <Customer::UserCreditCard>());
    bool userExists (Type type, QString u) ;
    void deleteUser (Type type, QString u);
    void deActivateUser (Type type, QString u);
private:
    static int m;
    static int n;
    static int l;
    static int hash (Type type, QString u, int att = 0);
    bool finishedloading;
    void checkTable (Type type);

};

#endif // ALLUSERS_H
