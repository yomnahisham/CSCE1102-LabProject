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
    void setRole(QString r);
    QString getUsername () const;
    QString getPassword () const;
    QString getRole() const;
    bool isempty = true;
    virtual void virtualfunc();
private:
    QString password;
    QString username;
    QString role;

};

#endif // USER_H
