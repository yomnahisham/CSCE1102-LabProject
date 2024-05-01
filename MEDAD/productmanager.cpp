#include "productmanager.h"
#include "ui_productmanager.h"
#include "clickablelabels.h"
#include "shoppingcart.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"

#include <QScreen>
#include <QVector>
#include <QString>


ProductManager::ProductManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProductManager)
    , bookProducts(new QVector<Books*>())
    , accessoryProducts(new QVector<Accessories*>())
    , techyProducts(new QVector<Techs*>())
{
    ui->setupUi(this);

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int widthFull = screenGeometry.width();

    //setting logo in the corner of the shop app
    QPixmap logoPix(":/logos/assets/nameonlyLogo.png");
    int w = ui->logoCorner->width();
    int h = ui->logoCorner->height();
    ui-> logoCorner -> setPixmap(logoPix.scaled(w,h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->logoCorner->move(50, 50);

    QPixmap sublogoPix(":/logos/assets/logosubtitle.png");
    ui-> logoSub -> setPixmap(sublogoPix.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //creating custom clickable labels and buttons
    ClickableLabels* cartLabel = new ClickableLabels(this);
    ClickableLabels* signOutButton = new ClickableLabels(this);

    //setting image of the clickable shopping cart label
    QPixmap cartPix(":/logos/assets/shoppingcartlogo.png");
    cartLabel->setPixmap(cartPix.scaled(60, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    int cartLabelWidth = cartLabel->width();
    cartLabel->move(widthFull - (2*cartLabelWidth), 60);

    //connecting cartLabel, its signal from ClickableLabels, this ui, and the function onCartClicked to handle what happens after cart is clicked
    connect(cartLabel, &ClickableLabels::clicked, this, &ProductManager::onCartClicked);

    //setting the button for signing out, user data should be saved in file
    QPixmap signoutPix(":/logos/assets/signoutbutton.png");
    signOutButton->setPixmap(signoutPix.scaled(100, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    int signOutButtonWidth = 135;
    signOutButton->move(widthFull - (signOutButtonWidth), 60);

    //connecting signoutbutton, its signal from ClickableLabels, this ui, and the function onSignOutClicked to handle the click
    connect(signOutButton, &ClickableLabels::clicked, this, &ProductManager::onSignOutClicked);

    initializeProducts();
}

void ProductManager::setUser(User* loggedUser){
    user = loggedUser;
    if (user)
        qDebug() << "User transferred successfully";
}

ProductManager::~ProductManager()
{
    delete ui;
    delete user; // Delete user object if necessary
    // Delete vectors and their elements
    for (auto book : *bookProducts) {
        delete book;
    }
    delete bookProducts;
    for (auto accessory : *accessoryProducts) {
        delete accessory;
    }
    delete accessoryProducts;
    for (auto tech : *techyProducts) {
        delete tech;
    }
    delete techyProducts;
}

void ProductManager::onCartClicked(){
    qDebug() << "cart clicked, moving to shopping cart ui.";

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    ShoppingCart* shop = new ShoppingCart();
    shop->resize(screenGeometry.width(), screenGeometry.height());
    shop->show();
    hide();
}

void ProductManager::onSignOutClicked(){
    qDebug() << "signing out!";
    //ayla, please see what signout should do according to your user and allusers class
}

Books* ProductManager::createBook(const QString& name, double price, int quantity, bool availability, const QString& imagePath, const QString& genre, const QString& author, const QString& ISBN){
    QPixmap image(imagePath);
    return new Books(name, price, quantity, availability, image, genre, author, ISBN);
}

Accessories* ProductManager::createAccessory(const QString& name, double price, int quantity, bool availability, const QString& imagePath, const QString& type, char size) {
    QPixmap image(imagePath);
    return new Accessories(name, price, quantity, availability, image, type, size);
}

Techs* ProductManager::createTech(const QString& name, double price, int quantity, bool availability, const QPixmap& imagePath, int type){
    QPixmap image(imagePath);
    return new Techs(name, price, quantity, availability, image, type);
}

void ProductManager::initializeProducts() {
    QString productsData[][8] = {
        {"War and Peace", "12.5", "5", "true", ":/Books/assets/war and peace.jpeg", "Classics", "Leo Tolstoy", "9780393042375"},
        {"Anna Karenina", "15", "5", "true", ":/Books/assets/anna kare.jpeg", "Classics", "Leo Tolstoy", "9780393042771"},
        {"A Tale of Two Cities", "15.5", "5", "true", ":/Books/assets/tale of two.jpeg", "Classics", "Charles Dickens", "9780582400115"},
        {"Oliver Twist", "14", "5", "true", ":/Books/assets/oliver.jpeg", "Classics", "Charles Dickens", "9780140430172"},
        {"Julius Caesar", "16", "5", "true", ":/Books/assets/ceaser.jpeg", "Plays", "William Shakespeare", "9780743482745"},
    };

    for (const auto& data : productsData) {
        QString name = data[0];
        double price = data[1].toDouble();
        int quantity = data[2].toInt();
        bool availability = (data[3].compare("true", Qt::CaseInsensitive) == 0);
        QString imagePath = data[4];
        QString genre = data[5];
        QString author = data[6];
        QString ISBN = data[7];

        Books* product = createBook(name, price, quantity, availability, imagePath, genre, author, ISBN);
        bookProducts->push_back(product);
    }

    QString accessoriesData[][7] = {
        {"Books Defense Tshirt", "25", "5", "true", ":/Tshirts/assets/Books Defense Tshirt.jpeg", "T-shirt", "M"},
        {"Cool Kids Tshirt", "20", "5", "true", ":/Tshirts/assets/Cool Kids Are Reading.jpeg", "T-shirt", "L"}
        //add more accessories data later
    };

    for (const auto& data : accessoriesData) {
        QString name = data[0];
        double price = data[1].toDouble();
        int quantity = data[2].toInt();
        bool availability = (data[3].compare("true", Qt::CaseInsensitive) == 0);
        QString imagePath = data[4];
        QString type = data[5];
        QChar size = data[6][0];

        char sizeChar = size.toLatin1();

        Accessories* accessory = createAccessory(name, price, quantity, availability, imagePath, type, sizeChar);
        accessoryProducts->push_back(accessory);
    }

    QString techsData[][6] = { // Change the inner array size to 6
        {"Kindle", "500", "5", "true", ":/Techs/assets/Kindle.jpeg", "1"},
        {"BookLight", "200", "5", "true", ":/Techs/assets/Book Light.jpeg", "2"},
        {"ReadingLight", "250", "5", "true", ":/Techs/assets/Reading Light.jpeg", "3"}
    };

    for (const auto& data : techsData) {
        QString name = data[0];
        double price = data[1].toDouble();
        int quantity = data[2].toInt();
        bool availability = (data[3].compare("true", Qt::CaseInsensitive) == 0);
        QString imagePath = data[4];
        int type = data[5].toInt();

        Techs* tech = createTech(name, price, quantity, availability, QPixmap(imagePath), type);
        techyProducts->push_back(tech);
    }

}


