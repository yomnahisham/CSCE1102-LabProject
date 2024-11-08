#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H
#include "user.h"
#include "allusers.h"
#include "customer.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"
#include "clickablelabels.h"
#include "shoppingcart.h"

#include <QWidget>
#include <vector>
#include <QLayoutItem>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QStringList>
#include <algorithm>
#include<QScrollArea>
#include <QMainWindow>

using namespace std;

namespace Ui {
class ProductManager;
}

class ProductManager : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManager(QWidget *parent, User* loggedUser, AllUsers* Allusers,ShoppingCart *cartPage = nullptr);
    ~ProductManager();

    Books* createBook(const QString& name, double price, int quantity, bool availability, const QString& imagePath, const QString& seller,const QString& genre, const QString& author, const QString& ISBN);
    Accessories* createAccessory(const QString& name, double price, int quantity, bool availability, const QString& imagePath, const QString& seller, const QString& type, QString size);
    Techs* createTech(const QString& name, double price, int quantity, bool availability, const QPixmap& image, const QString& seller, int type);

    void createAdminAccessPage();
    void makeAccountsTable(QTableWidget *accountsTable);
    void createSellerView();

    vector<Products*> getSellerProducts();
    vector<Products*> suggestSimilarItems();

    void makeFirstPage();
    void makeSecondPage();
    void makeThirdPage();
    void makeFourthPage();

    void showPrevious();
    void showProductsBasedonPage(vector<Products*> neededProducts);

    void loadProducts();
    void loadNewProduct();

    void initializeProducts();
    void showSuggestions();
    void showRemainingProducts();

    void clearLayout(QLayout* layout);
    bool isProductDisplayed(Products* product);
    void remarkItemsBeforeCall();


    ShoppingCart *cart;
    Customer *customer;

private slots:
    void onCartClicked();
    void onSignOutClicked();
    void onAddToCartClicked();
    void onNextClicked();
    void onPrevClicked();
    void searchProducts(const QString& keyword);
    QWidget* createProductWidget(Products* product);
    QPixmap resizeImage(const QPixmap& originalPixmap, int maxWidth, int maxHeight);
    void onRegisterAdminClicked();
    void onRegisterSellerClicked();
   void sortPage(QLayout* layout, const QString &arg1, vector<Products*> &products , int startIndex, int maxBooksToShow);
   void on_filterBox_currentTextChanged(const QString &arg1);
    void updateLayout(QLayout* layout);
   void sortProducts(vector<Products*>& products, const QString& arg1);
    //void loadProducts();
   void on_addProductButton_clicked();

   public:
    Ui::ProductManager *ui;
    User* user;
    AllUsers* allusers;
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
    vector<Products*> sellerNewProducts;

    bool secondPage = false;
    bool thirdPage = false;
    bool fourthPage = false;
    bool calledPrevious = false;
    bool filteractivated=false;
    bool firstPage=false;
    bool addedNewProduct = false;

    int widthFull;
    int heightFull;

    ClickableLabels* nextButton;
    ClickableLabels* prevButton;
};

#endif // PRODUCTMANAGER_H

