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
    Customer AllCustomers [17];
    Admin AllAdmins [17];
    void SaveUsers ();
    void LoadUsers();
    bool authenticateUser (Type , QString u, QString p);

private:
    int m = 17;
    int hash (Type type, QString u, int att = 0);

};

#endif // ALLUSERS_H
