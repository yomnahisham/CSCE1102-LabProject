#ifndef USER_H
#define USER_H

#include "QtCore/qstring.h"
class User
{
public:
    User();
    ~User();
    void setUsername (QString u);
    void setPassword (QString p);
    QString getUsername () ;
    QString getPassword () ;
    bool isempty = true;
    virtual void virtualfunc();
private:
    QString password;
    QString username;

};

#endif // USER_H
