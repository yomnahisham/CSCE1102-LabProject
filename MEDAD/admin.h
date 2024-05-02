#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin : public User
{
public:
    Admin();
    ~Admin();
    void virtualfunc();
};

#endif // ADMIN_H
