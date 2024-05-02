#include "allusers.h"
#include "customer.h"
#include "admin.h"
#include "user.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QStandardPaths>
#include <QCoreApplication>

int AllUsers::m = 17;
int AllUsers::n = 17;


AllUsers::AllUsers() {
    AllAdmins = new Admin[m];
    AllCustomers = new Customer[n];
    finishedloading = false;
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
        return subPath;

    // Ensure the cache directory exists
    if (!QFileInfo(cacheDir).dir().mkpath("."))
        return {}; // Failed to create dir

    // Copy the resource file to the cache directory
    if (!QFile::copy(resPath, subPath))
        return {}; // Failed to copy file

    // Make the copied file writable
    QFile::setPermissions(subPath, QFileDevice::ReadUser | QFileDevice::WriteUser);

    return subPath;
}

void AllUsers::LoadUsers(){
    //load all user data
    QFile userData (cachedResource(":/UsersInfo/UserData.txt"));

    if (userData.setPermissions(QFile::ReadOwner))
        qDebug() << "Permissions updated successfully for file:";
    else
        qDebug() << "Error updating permissions for file:" ;

    userData.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&userData);

    while(!in.atEnd()) {
        QString data = in.readLine();
        qDebug()<< data;
        QStringList splitdata = data.split (" ");

        vector<QString> genres;

        if (splitdata[0] == "admin")
           insert (admin,splitdata[1], splitdata[2], genres);
        else if (splitdata[0] == "customer")
        {    for (int i = 3; splitdata[i] != "N" ; i++)
                genres.push_back(splitdata[i]);
            insert (customer,splitdata[1], splitdata[2], genres);
        }

    }

    userData.close();
    finishedloading = true;
}

void AllUsers::SaveUsers()
{
    qDebug() << "Saving users";

    QFile userData (cachedResource(":/UsersInfo/UserData.txt"));

    if (userData.setPermissions(QFile::WriteOwner)) {
        qDebug() << "Permissions updated successfully for file:";
    } else {
        qDebug() << "Error updating permissions for file:" ;
    }

    userData.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Truncate);

    QTextStream stream(&userData);
    /*stream << "customer yomna yomna1 Classics Comic-Books N" << "\n";
    stream << "customer aylaS ayla1234 Classics Palestine N" << "\n";
    stream << "admin AylaSaleh ayla1234" << "\n";
    stream << "admin yoyoo yomna1" << "\n";*/

    for (int i = 0 ; i < m; i ++)
    {
        stream << "admin " << AllAdmins[i].getUsername() << " " << AllAdmins[i].getPassword() << "\n" ;
        stream << "customer " << AllCustomers[i].getUsername() << " " << AllCustomers[i].getPassword() ;
        vector <QString> genre = AllCustomers[i].getPreferredGenres();
        for (auto it = genre.begin(); it != genre.end(); it++)
            stream << " " <<*it;
        stream << " N" << "\n";
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
    else
        return (hash_value + att*att) % n;


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
            LoadUsers();
        }
        break;
    }
}

void AllUsers::insert (Type type, QString u, QString p, vector<QString> genres)
{
    checkTable(type);
    int a = 0;
    int i = hash (type, u, a);
    switch (type)
    {case admin:
        while (!AllAdmins[i].isempty)//while full
        {
            i = hash(type, u, a++); //find next index
        }
       if (AllAdmins[i].isempty)
        {    AllAdmins[i].setUsername(u);
             AllAdmins[i].setPassword(p);
        }
        break;
    case customer:
        while (!AllCustomers[i].isempty)//while full
        {
            i = hash(type, u, a++); //find next index
        }
        if (AllCustomers[i].isempty)
        {    AllCustomers[i].setUsername(u);
            AllCustomers[i].setPassword(p);
            AllCustomers[i].setPreferredGenres(genres);
        }
        break;
    }

    qDebug()<< finishedloading;

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
    }
}
