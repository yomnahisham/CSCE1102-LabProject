#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"

class Admin : public User
{
public:
    Admin();
    ~Admin();
    QString getBadgeNum() const;
    void virtualfunc();
private:
    QString authorizedViewPassNum = "3950"; //only badge number allowed to view passwords
};

#endif // ADMIN_H
