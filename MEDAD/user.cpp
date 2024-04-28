#include "user.h"

User::User() {}

void User::setUsername (QString u)
{
    username = u;
    isempty = false;
}

void User::setPassword (QString p)
{
    password = p;
}


