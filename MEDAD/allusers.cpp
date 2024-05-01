#include "allusers.h"
#include "customer.h"
#include "admin.h"
#include "user.h"
#include <QFile>
#include <QTextStream>

int AllUsers::m = 17;

AllUsers::AllUsers() {
    finishedloading = false;
}

AllUsers& AllUsers::operator=( AllUsers& other) { // add const
    LoadUsers();
    qDebug()<< "loaded in copy assign";
    return *this;
}

void AllUsers::LoadUsers(){
    //load all user data
    QFile userData (":/UsersInfo/UserData.txt");
    if (!userData.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << userData.errorString();
        return;
    }

    QTextStream in(&userData);

    while(!in.atEnd()) {
        QString data = in.readLine();
        QStringList splitdata = data.split (" ");

        if (splitdata[0] == "admin")
           insert (admin,splitdata[1], splitdata[2]);
        else if (splitdata[0] == "customer")
           insert (customer,splitdata[1], splitdata[2]);

    }

    userData.close();

    finishedloading = true;
}

void AllUsers::SaveUsers()
{
    QFile userData (":/UsersInfo/UserData.txt");

    if (userData.setPermissions(QFile::WriteOwner)) {
        qDebug() << "Permissions updated successfully for file:";
    } else {
        qDebug() << "Error updating permissions for file:" ;
    }

    userData.open(QIODevice::WriteOnly | QIODevice::Text);
    if (userData.isOpen()) {
        qDebug ()<< "opened file:";

        QTextStream stream(&userData);

        for (int i = 0 ; i < m; i ++)
        {
            stream << "admin " << AllAdmins[i].getUsername() << " " << AllAdmins[i].getPassword() ;
            stream << "customer " << AllCustomers[i].getUsername() << " " << AllCustomers[i].getPassword() ;
        }

        userData.close();
    } else
        qDebug ()<< "Error opening file:" << userData.errorString();

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
        while (!AllAdmins[i].isempty)//while full
        {
            i = hash(u, a++); //find next index
        }
       if (AllAdmins[i].isempty)
        {    AllAdmins[i].setUsername(u);
             AllAdmins[i].setPassword(p);
        }
        break;
    case customer:
        while (!AllCustomers[i].isempty)//while full
        {
            i = hash(u, a++); //find next index
        }
        if (AllCustomers[i].isempty)
        {    AllCustomers[i].setUsername(u);
            AllCustomers[i].setPassword(p);
        }
        break;
    }

    if (finishedloading)
    {
        SaveUsers(); // save any new users created
    }
}

User* AllUsers::authenticateUser (Type type, QString u, QString p) {
    int a = 0;
    int i = hash (u, a);
    bool endHash = false;
    switch (type)
    {case admin:
        while (!endHash) // while [i] is full and we haven't completed a full loop
        {
            if ((AllAdmins[i].getUsername() == u)&&(AllAdmins[i].getPassword() == p))
                return &AllAdmins[i];
            else
                i = hash (u, a++);

            if ((!AllAdmins[i].isempty )||(a < m))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        return nullptr;
        break;
    case customer:
        while (!endHash)
        {
            if ((AllCustomers[i].getUsername() == u)&&(AllCustomers[i].getPassword() == p))
                return &AllCustomers[i];
            else
                i = hash (u, a++);

            if ((!AllAdmins[i].isempty )||(a < m))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        return nullptr;
        break;
    }
}

bool AllUsers::userExists (Type type, QString u)
{
    int a = 0;
    int i = hash (u, a);
    bool endHash = false;
    switch (type)
    {case admin:
        while (!endHash)
        {
            if (AllAdmins[i].getUsername() == u)
                return true;
            else
                i = hash (u, a++);

            if ((!AllAdmins[i].isempty )||(a < m))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        return false;
        break;
    case customer:
        while (!endHash)
        {
            if (AllCustomers[i].getUsername() == u)
                return true;
            else
                i = hash (u, a++);

            if ((!AllCustomers[i].isempty )||(a < m))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        return false;
        break;
    }
}
