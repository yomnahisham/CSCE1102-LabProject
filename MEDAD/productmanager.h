#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H
#include "user.h"
#include "allusers.h"
#include "customer.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"
#include"allproducts1.h"
#include "shoppingcart.h"
#include "clickablelabels.h"
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
    explicit ProductManager(QWidget *parent, User* loggedUser, AllUsers* Allusers, ShoppingCart *cartPage);
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

    void showPrevious();
    void showProductsBasedonPage(vector<Products*> neededProducts);

    void initializeProducts();
    void showSuggestions();
    void showRemainingProducts();
    void clearLayout(QLayout* layout);
    bool isProductDisplayed(Products* product);
    void remarkItemsBeforeCall();
    ShoppingCart *cart;


private slots:
    void onCartClicked();
    void onSignOutClicked();
    void onAddToCartClicked();
    void onNextClicked();
    void onPrevClicked();
    void searchProducts(const QString& keyword);
    QWidget* createProductWidget(Products* product);
    QPixmap resizeImage(const QPixmap& originalPixmap, int maxWidth, int maxHeight);
    void on_addAdminB_clicked();
   void sortPage(QLayout* layout, const QString &arg1, vector<Products*> &products , int startIndex, int maxBooksToShow);
   void on_filterBox_currentTextChanged(const QString &arg1);
    void updateLayout(QLayout* layout);
   void sortProducts(vector<Products*>& products, const QString& arg1);
public:
    Ui::ProductManager *ui;
    User* user;
    AllUsers* users;
    QVector<Books*> *bookProducts;
    QVector<Accessories*> *accessoryProducts;
    QVector<Techs*> *techyProducts;
    vector<Products*> displayedProducts; //to store all displayed products in first page
    vector<Products*> firstPageProducts;
    vector<Products*> secondPageProducts;
    vector<Products*> thirdPageProducts;
    vector<Products*> fourthPageProducts;
    vector<Products*> beforeCallProducts;
    vector<Products*> allProducts;

    bool secondPage = false;
    bool thirdPage = false;
    bool fourthPage = false;
    bool calledPrevious = false;
    bool filteractivated=false;
    bool firstPage=false;

    ClickableLabels* nextButton;
    ClickableLabels* prevButton;
};

#endif // PRODUCTMANAGER_H

