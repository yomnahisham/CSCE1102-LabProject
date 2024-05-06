#include "allusers.h"
#include "customer.h"
#include "admin.h"
#include "user.h"
#include "products.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QStandardPaths>
#include <QCoreApplication>

int AllUsers::m = 17;
int AllUsers::n = 17;
int AllUsers::l = 17;


AllUsers::AllUsers() {
    AllAdmins = new Admin[m];
    AllCustomers = new Customer[n];
    AllSellers = new Seller[l];
    //SaveUsers();
}

AllUsers& AllUsers::operator=( AllUsers& other) { // add const
    LoadUsers();
    qDebug()<< "loaded in copy assign";
    return *this;
}

QString cachedResource(const QString &resPath) {
    // Not a resource -> done
    if (!resPath.startsWith(":"))
        return resPath;

    // Get the cache directory of your app relative to the executable
    QString executablePath = QCoreApplication::applicationDirPath();
    QString cacheDir = executablePath + "/cache";

    // Construct the path for the cached resource
    QString subPath = cacheDir + resPath.mid(1); // cache folder plus resource without the leading ':'

    // Check if the resource is already cached
    if (QFile::exists(subPath)) // File exists -> done
    {   qDebug()<< "file exists";
        return subPath;}

    // Ensure the cache directory exists
    if (!QFileInfo(cacheDir).dir().mkpath("."))
    {   qDebug()<< "couldn't create cache folder";
        return {}; // Failed to create dir
    }

    // Copy the resource file to the cache directory
    if (!QFile::copy(resPath, subPath))
    {   qDebug()<< "couldn't copy file";
        return {}; // Failed to copy file
    }

    // Make the copied file writable
    QFile::setPermissions(subPath, QFileDevice::ReadUser | QFileDevice::WriteUser);

    return subPath;
}

void AllUsers::LoadUsers(){
    //load all user data
    qDebug() << "loading users:";

    //QFile userData (cachedResource(":/UsersInfo/UserData.txt"));
    QFile userData (":/UsersInfo/UserData.txt");

    if (userData.setPermissions(QFile::ReadOwner))
        qDebug() << "Permissions updated successfully for file:";
    else
        qDebug() << "Error updating permissions for file:" ;

    userData.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&userData);
    int x = 0;
    while(!in.atEnd()) {
        QString data = in.readLine();
        qDebug()<< x << " : " <<data ;
        QStringList splitdata = data.split (" ");

        vector<QString> genres;

        if (splitdata[0] == "admin")
           insert (admin,splitdata[1], splitdata[2], genres);
        else if (splitdata[0] == "customer")
        {
            for (int i = 3; splitdata[i] != "N" ; i++)
                genres.push_back(splitdata[i]);
            insert (customer,splitdata[1], splitdata[2], genres);
        }else if (splitdata[0]== "seller"){
            insert (seller, splitdata[1], splitdata[2], genres);
        }else if (splitdata[0]== "/")
        {
            qDebug()<< "empty spot";
        }
        x++;
    }

    userData.close();
    finishedloading = true;
    return;
}

void AllUsers::SaveUsers()
{
    qDebug() << "Saving users:";

    QFile userData (cachedResource(":/UsersInfo/UserData.txt"));

    if (userData.setPermissions(QFile::WriteOwner)) {
        qDebug() << "Permissions updated successfully for file:";
    } else {
        qDebug() << "Error updating permissions for file:" ;
    }

    userData.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Truncate);

    QTextStream stream(&userData);
   /* stream << "customer yomna yomna1 Classics Comic-Books N" << "\n";
    stream << "customer aylaS ayla1234 Classics Palestine N" << "\n";
    stream << "admin AylaSaleh ayla1234" << "\n";
    stream << "admin yoyoo yomna1" << "\n";
    for (int i = 0; i < 30; i++)
        stream << "/" << "\n";*/


    for (int i = 0 ; i < m; i ++)
    {
        if (AllAdmins[i].isempty)
            stream << "/" << "\n";
        else
            stream << "admin " << AllAdmins[i].getUsername() << " " << AllAdmins[i].getPassword() << "\n" ;

        if (AllCustomers[i].isempty)
            stream << "/" << "\n";
        else
        {    stream << "customer " << AllCustomers[i].getUsername() << " " << AllCustomers[i].getPassword() ;
            vector <QString> genre = AllCustomers[i].getPreferredGenres();
            for (auto it = genre.begin(); it != genre.end(); it++)
                stream << " " <<*it;
            stream << " N" << "\n";
        }

        if (AllSellers[i].isempty)
            stream << "/" << "\n";
        else{
            stream << "seller " << AllSellers[i].getUsername() << " " << AllSellers[i].getPassword() << "\n" ;
        }
    }

    userData.close();
}

int AllUsers:: hash (Type type, QString u, int att)
{   //quadratic probing
    int hash_value = 0;
    for (auto c : u){
        hash_value += c.unicode();
    }
    if (type == admin)
        return (hash_value + att*att) % m;
    else if (type == customer)
        return (hash_value + att*att) % n;
    else if (type == seller)
        return (hash_value + att*att) % l;
}

void AllUsers::checkTable (Type type)
{
    int x = 0;

    switch(type)
    {case admin:
        for (int i = 0; i < m; i++)
        {
            if (!AllAdmins[i].isempty)
                x++;
        }

        if (x > m/2)    //reached half capacity
        {
            m = m*2;
            SaveUsers();
            Admin* q = AllAdmins;
            AllAdmins = nullptr;
            delete [] q;
            AllAdmins = new Admin[m];
            LoadUsers();
        }
        break;
    case customer:
        for (int i = 0; i < n; i++)
        {
            if (!AllCustomers[i].isempty)
                x++;
        }

        if (x > n/2)    //reached half capacity
        {
            n = n*2;
            SaveUsers();
            Customer* q = AllCustomers;
            AllCustomers = nullptr;
            delete [] q;
            AllCustomers = new Customer[n];
            LoadUsers();
        }
        break;
    case seller:
        for (int i = 0; i < l; i++)
        {
            if (!AllSellers[i].isempty)
                x++;
        }

        if (x > l/2)    //reached half capacity
        {
            l = l*2;
            SaveUsers();
            Seller* q = AllSellers;
            AllSellers = nullptr;
            delete [] q;
            AllSellers = new Seller[l];
            LoadUsers();
        }
        break;
    }
}

void AllUsers::insert (Type type, QString u, QString p, vector<QString> genres)
{
    //checkTable(type);
    int a = 0;
    int i = hash (type, u, a);
    switch (type)
    {case admin:
        while (!AllAdmins[i].isempty)//while full
        {
            i = hash(type, u, a++); //find next index
            qDebug()<< "mediate i :" <<i;
        }
       if (AllAdmins[i].isempty)
        {   AllAdmins[i].setUsername(u);
            AllAdmins[i].setPassword(p);
           qDebug()<< "final i : " << i;
        }
        break;
    case customer:
        while (!AllCustomers[i].isempty)//while full
        {
            i = hash(type, u, a++); //find next index
            qDebug()<< "mediate i :" <<i;

        }
        if (AllCustomers[i].isempty)
        {    AllCustomers[i].setUsername(u);
            AllCustomers[i].setPassword(p);
            AllCustomers[i].setPreferredGenres(genres);
            qDebug()<< "final i : " << i;

        }
        break;
    case seller:
        while (!AllSellers[i].isempty)//while full
        {
            i = hash(type, u, a++); //find next index
            qDebug()<< "mediate i :" <<i;

        }
        if (AllSellers[i].isempty)
        {    AllSellers[i].setUsername(u);
            AllSellers[i].setPassword(p);
            qDebug()<< "final i : " << i;

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
    int i = hash (type, u, a);
    bool endHash = false;
    switch (type)
    {case admin:
        while (!endHash) // while [i] is full and we haven't completed a full loop
        {
            if ((AllAdmins[i].getUsername() == u)&&(AllAdmins[i].getPassword() == p))
                return &AllAdmins[i];
            else
                i = hash (type , u, a++);

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
                i = hash (type, u, a++);

            if ((!AllCustomers[i].isempty )||(a < n))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        return nullptr;
        break;
    case seller:
        while (!endHash)
        {
            if ((AllSellers[i].getUsername() == u)&&(AllSellers[i].getPassword() == p))
                return &AllSellers[i];
            else
                i = hash (type, u, a++);

            if ((!AllSellers[i].isempty )||(a < l))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        return nullptr;
        break;
    }
}

bool AllUsers::userExists (Type type, QString u)
{
    int a = 0;
    int i = hash (type, u, a);
    bool endHash = false;
    switch (type)
    {case admin:
        while (!endHash)
        {
            if (AllAdmins[i].getUsername() == u)
                return true;
            else
                i = hash (type, u, a++);

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
                i = hash (type, u, a++);

            if ((!AllCustomers[i].isempty )||(a < n))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        return false;
        break;
    case seller:
        while (!endHash)
        {
            if (AllSellers[i].getUsername() == u)
                return true;
            else
                i = hash (type, u, a++);

            if ((!AllSellers[i].isempty )||(a < l))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        return false;
        break;
    }
}
