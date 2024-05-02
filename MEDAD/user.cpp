#include "user.h"

User::User() {
    isempty = true;
}

User::~User() {}


void User::setUsername (QString u)
{
    username = u;
    isempty = false;
}

void User::setPassword (QString p)
{
    password = p;
}

QString User::getUsername (){
    return username;
}

QString User::getPassword (){
    return password;
}

void User::virtualfunc()
{

}
