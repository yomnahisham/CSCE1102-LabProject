#include "books.h"

Books::Books(QString n, double p, int q, bool a, QPixmap i, QString g, QString au, QString I): Products(n,p,q,a,i) , genre(g) ,author(au), ISBN(I) {}

void Books:: setGenre(QString g)
{
    genre=g;
}
QString Books::getGenre()
{
    return genre;
}
void Books::setAuthor(QString au)
{
    author=au;
}
QString Books::getAuthor()
{
    return author;
}
void Books:: setISBN(QString I)
{
    ISBN=I;
}
QString Books::getISBN()
{
    return ISBN;
}
void Books::displayDetails()
{
    qDebug() << "Name: " << name;
    qDebug() << "Price: " << price;
    qDebug() << "Quantity: " << quantity;
    qDebug() << "Availability: " << (availability ? "Available" : "Not available");
    qDebug() << "Genre: " << genre;
    qDebug() << "Author: " << author;
    qDebug() << "ISBN: " << ISBN;
}
