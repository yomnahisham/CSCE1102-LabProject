#include "allusers.h"
#include <QFile>
#include <QTextStream>

AllUsers::AllUsers() {
    //load all user data
    QFile userData (":/new/prefix1/UserData.txt");

    QTextStream in(&userData);

    while(!in.atEnd()) {
        QString data = in.readLine();
        QStringList splitdata = data.split (" ");

        if (splitdata[0] == "admin")
        {
            int index = hash(admin, splitdata[1]);
            AllAdmins[index].setUsername (splitdata[1]);
            AllAdmins[index].setPassword (splitdata[2]);
        }else if (splitdata[0] == "customer")
        {
            int index = hash(customer, splitdata[1]);
            AllCustomers[index].setUsername (splitdata[1]);
            AllCustomers[index].setPassword (splitdata[2]);
        }
    }

    userData.close ();
}

int AllUsers:: hash (Type type, QString u, int att)
{   //quadratic probing
    int hash_value = 0;
    for (auto c : u){
        hash_value += c.unicode();
    }

    switch (type)
    {
    case admin:
        if (AllAdmins[hash_value].isempty)
            return (hash_value + att*att) % m;
        else
            hash (type, u, att++);
        break;
    case customer:
        if (AllCustomers[hash_value].isempty)
            return (hash_value + att*att) % m;
        else
            hash (type, u, att++);
        break;
    }
}

bool AllUsers::authenticateUser (Type, QString u, QString p){

}
