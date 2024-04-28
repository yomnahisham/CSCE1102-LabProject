#include "allusers.h"
#include "customer.h"
#include "admin.h"
#include <QFile>
#include <QTextStream>

int AllUsers::m = 17;

AllUsers::AllUsers() {
}

void AllUsers::LoadUsers(){
    //load all user data
    QFile userData (":/new/prefix1/UserData.txt");

    QTextStream in(&userData);

    while(!in.atEnd()) {
        QString data = in.readLine();
        QStringList splitdata = data.split (" ");

        if (splitdata[0] == "admin")
            insert (admin,splitdata[1], splitdata[2]);
        else if (splitdata[0] == "customer")
           insert (customer,splitdata[1], splitdata[2]);

    }

    userData.close ();
}


int AllUsers:: hash (QString u, int att)
{   //quadratic probing
    int hash_value = 0;
    for (auto c : u){
        hash_value += c.unicode();
    }
    return (hash_value + att*att) % m;

}

void AllUsers::insert (Type type, QString u, QString p)
{
    int a = 0;
    int i = hash (u, a);
    switch (type)
    {case admin:
       /* if (AllAdmins[i].isempty)
        {    AllAdmins[i].setUsername(u);
             AllAdmins[i].setPassword(p);
        }else
            hash(u, a++);*/
        break;
    case customer:
        /*if (AllCustomers[i].isempty)
        {    AllCustomers[i].setUsername(u);
            AllCustomers[i].setPassword(p);
        }else
            hash(u, a++);*/
        break;
    }
}

bool AllUsers::authenticateUser (Type type, QString u, QString p) {
    int a = 0;
    int i = hash (u, a);
    switch (type)
    {case admin:
       /* while ((!AllAdmins[i].isempty )||(a < 17))
        {
            if ((AllAdmins[i].getUsername() == u)&&(AllAdmins[i].getPassword() == p))
                return true;
            else
                i = hash (u, a++);
        }
        return false;*/
        break;
    case customer:
      /*  while ((!AllCustomers[i].isempty )||(a < 17))
        {
            if ((AllCustomers[i].getUsername() == u)&&(AllCustomers[i].getPassword() == p))
                return true;
            else
                i = hash (u, a++);
        }
        return false;*/
        break;
    }
}

bool AllUsers::userExists (Type type, QString u)
{

}
