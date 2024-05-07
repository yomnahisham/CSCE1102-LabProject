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

    if (QFile::exists(subPath)) {
        qDebug() << "File exists:" << subPath;
        // Check if the file is open by another process
        QFile checkFile(subPath);
        if (!checkFile.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::OpenModeFlag::Unbuffered)) {
            qDebug() << "File is currently in use. Cannot set permissions.";
            return {}; // Return or handle appropriately
        }
        checkFile.close(); // Close the file after checking
        return subPath; // Return the file path
    }
    else
    {
        qDebug() << "File does not exists:" << subPath;
    }


    return subPath;
}

void AllUsers::LoadUsers(){
    //load all user data
    qDebug() << "loading users:";

    QFile userData (cachedResource(":/UsersInfo/UserData.txt"));
    //QFile userData (":/UsersInfo/UserData.txt");

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
        QStringList splitdata = data.split (" :");

        if (splitdata[0] == "admin")
            insert (admin,splitdata[1], splitdata[2]);
        else if (splitdata[0] == "customer")
        {

            vector<QString> genres;
            vector <Customer::UserCart> cart;
            vector <Customer::UserAddress> add;
            vector <Customer::UserCreditCard> cc;

            int x = 3;
            for (int i = 3; splitdata[i] != "G" ; i++)
            {    genres.push_back(splitdata[i]);
                x++;
                qDebug()<< "added genre " << x;
            }

            x++;
            bool active = splitdata [x].toInt();
            x++;

            qDebug()<< "exited genre";

            if (splitdata[x] != "N")
            {
                qDebug()<< "entered cart";
                QStringList cartit = splitdata[x].split(",");
                for (int i = 0; i < cartit.size(); i += 2) {
                    int q = cartit[i + 1].toInt();
                    QString n = cartit[i];
                    Customer::UserCart item(n, q);
                    cart.push_back(item);
                    qDebug()<< "added cart item";
                }
                x++;
            }

            if (splitdata[x] != "N")
            {
                qDebug()<< "entered cart";
                QStringList ad = splitdata[x].split(",");
                for (int i = 0; i < ad.size(); i+=7) {
                    QString p = ad[i];
                    QString ar = ad[i+1];
                    QString s = ad[i+2];
                    QString b = ad[i+3];
                    int f = ad[i+4].toInt();
                    int ap = ad[i+5].toInt();
                    QString ph = ad[i+6];

                    Customer::UserAddress a(p,ar,s,b,f,ap,ph);
                    add.push_back(a);
                    qDebug()<< "added address";
                }
                x++;
            }


            if (splitdata[x] != "N")
            {
                qDebug()<< "entered cart";

                QStringList credit = splitdata[x].split(",");
                for (int i = 0; i < credit.size(); i += 2) {
                    int ccv = credit[i].toInt();
                    QString cn = credit[i+1];
                    int m = credit[i+2].toInt();
                    int y = credit[i+3].toInt();
                    Customer::UserCreditCard c(ccv, cn, m, y);
                    cc.push_back(c);
                    qDebug()<< "added credit card";
                }
            }

            insert (customer,splitdata[1], splitdata[2], genres,active, cart, add, cc);
        }else if (splitdata[0]== "seller"){
            insert (seller, splitdata[1], splitdata[2]);
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
   /*stream << "customer :yomna :yomna1 :Classics :Comic-Books :G :1 :N" << "\n";
    stream << "customer :aylaS :ayla1234 :Classics :Palestine :G :1 :N" << "\n";
    stream << "admin :AylaSaleh :ayla1234 :N" << "\n";
    stream << "admin :yoyoo :yomna1 :N" << "\n";
    for (int i = 0; i < 47; i++)
        stream << "/" << "\n";*/


       for (int i = 0 ; i < n; i ++)
    {
        if (AllAdmins[i].isempty)
            stream << "/" << "\n";
        else
            stream << "admin :" << AllAdmins[i].getUsername() << " :" << AllAdmins[i].getPassword() << " :N" << "\n" ;

    }

    for (int i = 0 ; i < m; i ++)
    {
        if (AllCustomers[i].isempty)
            stream << "/" << "\n";      //put a slash in the line
        else
        {    stream << "customer :" <<AllCustomers[i].getUsername() << " :" << AllCustomers[i].getPassword() ;
            vector <QString> genre = AllCustomers[i].getPreferredGenres();
            for (auto it = genre.begin(); it != genre.end(); it++)
                stream << " :" <<*it;
            stream << " :G";
            stream << " :" << AllCustomers[i].activated;
            vector <Customer::UserCart> cart = AllCustomers[i].getShopingCart();
            if (!cart.empty())                                          //if cart is not empty save it's contents, if empty skip
                for (auto it = cart.begin(); it != cart.end(); i++)
                    stream << " :" << it->name << "," << it -> quant;

            vector <Customer::UserAddress> add = AllCustomers[i].getAddress();
            if (!add.empty())
                for (auto it = add.begin(); it != add.end(); i++)
                    stream << " :" << it->Province << "," << it -> Area<< "," << it -> Street<< "," << it -> Building<< "," << it -> Floor<< "," << it -> Apartment<< "," << it -> PhoneNumber;

            vector <Customer::UserCreditCard> cc = AllCustomers[i].getCreditCards();
            if (! cc.empty())
                for (auto it = cc.begin(); it != cc.end(); i++)
                    stream << " :" << it->CVV <<  "," << it -> CardNum<<  "," << it -> Month<<  "," << it -> Year;


            stream << " :N" << "\n";        //end with N for future loading then newline.
        }
    }

    for (int i = 0 ; i < l; i ++)
    {
        if (AllSellers[i].isempty)
            stream << "/" << "\n";
        else{
            stream << "seller :" << AllSellers[i].getUsername() << " :" << AllSellers[i].getPassword() << " :N" << "\n" ;
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

void AllUsers::insert (Type type,  QString u, QString p, vector<QString> genres,bool active,vector <Customer::UserCart> cart,vector <Customer::UserAddress> add,vector <Customer::UserCreditCard> cc)
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
            AllCustomers[i].activated = active;
            AllCustomers[i].setPreferredGenres(genres);
            AllCustomers[i].setShopingCart(cart);
            AllCustomers[i].setAddress(add);
            AllCustomers[i].setCreditCards(cc);
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

void AllUsers::deleteUser (Type type, QString u)
{
    int a = 0;
    int i = hash (type, u, a);
    bool endHash = false;
    switch (type)
    {case admin:
        while (!endHash)
        {
            if (AllAdmins[i].getUsername() == u)
                AllAdmins[i].isempty = true;
            else
                i = hash (type, u, a++);

            if ((!AllAdmins[i].isempty )||(a < m))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        break;
    case customer:
        qDebug()<< "entered customer";
        while (!endHash)
        {
            if (AllCustomers[i].getUsername() == u)
            {   AllCustomers[i].isempty = true;
                qDebug()<< "found custimer deleted";
            }
            else
            {    i = hash (type, u, a++);
                qDebug()<< "rehashing";}

            if ((!AllCustomers[i].isempty )||(a < n))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        break;
    case seller:
        while (!endHash)
        {
            if (AllSellers[i].getUsername() == u)
                AllSellers[i].isempty = true;
            else
                i = hash (type, u, a++);

            if ((!AllSellers[i].isempty )||(a < l))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        break;
    }

    qDebug()<< "deleted in all users";

}

void AllUsers::deActivateUser (Type type, QString u)
{
    int a = 0;
    int i = hash (type, u, a);
    bool endHash = false;
    switch (type)
    {case admin:
        while (!endHash)
        {
            if (AllAdmins[i].getUsername() == u)
                AllAdmins[i].activated = false;
            else
                i = hash (type, u, a++);

            if ((!AllAdmins[i].isempty )||(a < m))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        break;
    case customer:
        qDebug()<< "entered customer";
        while (!endHash)
        {
            if (AllCustomers[i].getUsername() == u)
            {   AllCustomers[i].activated = false;
                qDebug()<< "found custimer deleted";
            }
            else
            {    i = hash (type, u, a++);
                qDebug()<< "rehashing";}

            if ((!AllCustomers[i].isempty )||(a < n))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        break;
    case seller:
        while (!endHash)
        {
            if (AllSellers[i].getUsername() == u)
                AllSellers[i].activated = false;
            else
                i = hash (type, u, a++);

            if ((!AllSellers[i].isempty )||(a < l))  // while [i] is full and we haven't completed a full loop
                endHash = true;
        }
        break;
    }

    qDebug()<< "deleted in all users";

}
