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
    Customer AllCustomers [17];
    Admin AllAdmins [17];
    void SaveUsers ();
    void LoadUsers();
    User* authenticateUser(Type type , QString u, QString p);
    void insert (Type type, QString u, QString p);
    bool userExists (Type type, QString u) ;
private:
    static int m;
    static int hash (QString u, int att = 0);
    bool finishedloading;

};

#endif // ALLUSERS_H
