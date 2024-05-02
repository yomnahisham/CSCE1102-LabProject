#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin : public User
{
public:
    Admin();
    void virtualfunc();
    void addAdmin ();
};

#endif // ADMIN_H
