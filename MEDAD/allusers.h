#ifndef ALLUSERS_H
#define ALLUSERS_H
#include "user.h"
#include "customer.h"
#include "admin.h"


class AllUsers
{
public:
    AllUsers();
    AllUsers& operator=(AllUsers& other);
    enum Type {admin, customer};
    Customer* AllCustomers;
    Admin* AllAdmins;
    void SaveUsers ();
    void LoadUsers();
    User* authenticateUser(Type type , QString u, QString p);
    void insert (Type type, QString u, QString p, vector<QString> genres);
    bool userExists (Type type, QString u) ;
private:
    static int m;
    static int n;
    static int hash (Type type, QString u, int att = 0);
    bool finishedloading;
    void checkTable (Type type);

};

#endif // ALLUSERS_H
