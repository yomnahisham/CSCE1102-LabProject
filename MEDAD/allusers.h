#ifndef ALLUSERS_H
#define ALLUSERS_H
#include "user.h"
#include "customer.h"
#include "admin.h"


class AllUsers
{
public:
    AllUsers();
    enum Type {admin, customer};
    static Customer AllCustomers [17];
    static Admin AllAdmins [17];
    static void SaveUsers ();
    static void LoadUsers();
    static bool authenticateUser(Type type , QString u, QString p);
    static void insert (Type type, QString u, QString p);
    static bool userExists (Type type, QString u) ;
private:
    static int m;
    static int hash (QString u, int att = 0);

};

#endif // ALLUSERS_H
