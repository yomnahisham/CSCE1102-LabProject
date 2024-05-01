#ifndef BOOKS_H
#define BOOKS_H
#include"Products.h"

class Books : public Products
{
protected:
    QString genre;
    QString author;
    QString ISBN;

public:
    Books(QString n, double p, int q, bool a, QPixmap i, QString g, QString au , QString I );
    void setGenre(QString g);
    QString getGenre();
    void setAuthor(QString a);
    QString getAuthor();
    void setISBN(QString I);
    QString getISBN();

};

#endif // BOOKS_H
