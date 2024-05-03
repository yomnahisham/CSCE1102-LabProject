#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H
#include "user.h"
#include "allusers.h"
#include "customer.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"
#include"allproducts1.h"
#include <QWidget>
#include <vector>
#include <QLayoutItem>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStringList>
#include <algorithm>
#include<QScrollArea>
#include"search.h"
#include <QMainWindow>

using namespace std;

namespace Ui {
class ProductManager;
}

class ProductManager : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManager(QWidget *parent, User* loggedUser, AllUsers* Allusers);
    ~ProductManager();

    void setUser(User* loggedUser);

    Books* createBook(const QString& name, double price, int quantity, bool availability, const QString& imagePath, const QString& genre, const QString& author, const QString& ISBN);
    Accessories* createAccessory(const QString& name, double price, int quantity, bool availability, const QString& imagePath, const QString& type, char size);
    Techs* createTech(const QString& name, double price, int quantity, bool availability, const QPixmap& image, int type);

    vector<Products*> suggestSimilarItems();

    void makeFirstPage();
    void makeSecondPage();
    void makeThirdPage();
    void makeFourthPage();

    void initializeProducts();
    void showSuggestions();
    void showRemainingProducts();
    void clearLayout(QLayout* layout);

    bool isProductDisplayed(Products* product);


private slots:
    void onCartClicked();
    void onSignOutClicked();
    void onAddToCartClicked();
    void onNextClicked();
    void searchProducts(const QString& keyword);
   //void sortProducts();
   // vector<Products*> clickSearch();


   // void on_AllProducts_clicked();

   // void on_addAdminB_clicked();

public:
    Ui::ProductManager *ui;
    User* user;
    AllUsers* users;
    QVector<Books*> *bookProducts;
    QVector<Accessories*> *accessoryProducts;
    QVector<Techs*> *techyProducts;
    vector<Products*> displayedProducts; //to store all displayed products in first page
    bool secondPage = false;
    bool thirdPage = false;
    bool fourthPage = false;
};

#endif // PRODUCTMANAGER_H

