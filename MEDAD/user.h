#ifndef USER_H
#define USER_H

#include "QtCore/qstring.h"
class User
{
public:
    User();
    void setUsername (QString u);
    void setPassword (QString p);
    QString getUsername ();
    QString getPassword ();
    bool isempty = true;

private:
    QString username;
    QString password;

};

#endif // USER_H
