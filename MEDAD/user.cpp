#include "user.h"

User::User() {
    isempty = true;
}

User::~User() {}


void User::setUsername (QString u)
{
    username = u;
    isempty = false;
    activated = true;
}

void User::setPassword (QString p)
{
    password = p;
}
void User::setRole(QString r){ role = r; }
QString User::getUsername () const{
    return username;
}

QString User::getPassword () const{
    return password;
}

QString User::getRole() const{
    return role;
}

void User::deleteUser()
{
    isempty = true;
}

void User::virtualfunc()
{

}
