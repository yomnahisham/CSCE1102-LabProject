#include "productmanager.h"
#include "ui_productmanager.h"
#include "registerwindow.h"
#include "clickablelabels.h"
#include "customer.h"
#include "shoppingcart.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"
#include "loginwindow.h"
#include"products.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QStandardPaths>
#include <QCoreApplication>
#include <QApplication>
#include <QScreen>
#include <QVector>
#include <QString>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QGroupBox>
#include <QRadioButton>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QMessageBox>
#include <QCheckBox>
#include <QTimer>


ProductManager::ProductManager(QWidget *parent, User* loggedUser, AllUsers* Allusers, ShoppingCart *cartPage)
    : QWidget(parent)
    , ui(new Ui::ProductManager)
    , user(loggedUser)
    , allusers (Allusers)
    ,cart (cartPage)
    , techyProducts(new QVector<Techs*>())
    , accessoryProducts(new QVector<Accessories*>())
    , bookProducts(new QVector<Books*>())

{
    ui->setupUi(this);

    connect(ui->filterBox, &QComboBox::currentTextChanged, this, &ProductManager::on_filterBox_currentTextChanged);

    ui->searchLineEdit->setPlaceholderText("Search by genre or title...");
    ui->XLogo->setVisible(false);
    ui->sellerLogo->setVisible(false);
    ui -> sellerError -> setVisible(false);

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    widthFull = screenGeometry.width();
    heightFull = screenGeometry.height();

    ui -> sellerError -> move(widthFull/2,heightFull/2);
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
    nextButton = new ClickableLabels(this);
    prevButton = new ClickableLabels(this);

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

    //connecting searchLineEdit with the function searchProducts based on a textChanged signal
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &ProductManager::searchProducts);

    QPixmap nextPix(":/logos/assets/nextArrow.png");
    nextButton->setPixmap(nextPix.scaled(70, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    nextButton->move(widthFull/2 + 20, 800);
    connect(nextButton, &ClickableLabels::clicked, this, &ProductManager::onNextClicked);


    QPixmap prevPix(":/logos/assets/prevArrow.png");
    prevButton->setPixmap(prevPix.scaled(70, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    prevButton->move(widthFull/2 -20, 800);
    connect(prevButton, &ClickableLabels::clicked, this, &ProductManager::onPrevClicked);

    QPixmap allPix(":/logos/assets/ourproducts.png");
    ui->ourproductsLogo->setPixmap(allPix.scaled(ui->ourproductsLogo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->ourproductsLogo->setVisible(true);

    //prefered to use ui->basedonsearchLogo->size() because it fits the size needed to make the desgin look better
    QPixmap youPix(":/logos/assets/basedonyou.png");
    ui->basedonyouLogo->setPixmap(youPix.scaled(ui->basedonsearchLogo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->basedonyouLogo->setVisible(false);

    QPixmap searchPix(":/logos/assets/basedonsearch.png");
    ui->basedonsearchLogo->setPixmap(searchPix.scaled(ui->basedonsearchLogo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->basedonsearchLogo->setVisible(false);

    if(Customer* cus = dynamic_cast<Customer*>(user)){
        ui->addProductButton->setVisible(false);
        makeFirstPage();
        return;
    }else if(Admin* admin = dynamic_cast<Admin*>(user)){
        ui->searchLineEdit->setVisible(false);
        ui->filterBox->setVisible(false);
        cartLabel->setVisible(false);
        createAdminAccessPage();
        return;
    }else if(Seller* seller = dynamic_cast<Seller*>(user)){
        nextButton->setVisible(false);
        prevButton->setVisible(false);
        cartLabel->setVisible(false);
        ui->XLogo->setVisible(true);
        ui->searchLineEdit->setVisible(false);
        ui->filterBox->setVisible(false);
        createSellerView();
        nextButton->setVisible(true);
        prevButton->setVisible(true);
        nextButton->raise();
        prevButton->raise();

        return;
    }
    //loadProducts();
}

ProductManager::~ProductManager()
{
    delete ui;
    //delete vectors and their elements
    for (auto book : *bookProducts) {
        delete book;
    }
    delete bookProducts;
    for (auto accessory : *accessoryProducts){
        delete accessory;
    }
    delete accessoryProducts;
    for (auto tech : *techyProducts){
        delete tech;
    }
    delete techyProducts;
}

void ProductManager::clearLayout(QLayout* layout){
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr){
        if (QWidget* widget = item->widget()) {
            delete widget;
        } else {
            if (QLayout* childLayout = item->layout()) {
                clearLayout(childLayout); //recursively clear child layouts
            }
            delete item;
        }
    }

}


void ProductManager::createAdminAccessPage(){
    ui->ourproductsLogo->setVisible(false);
    nextButton->setVisible(false);
    prevButton->setVisible(false);

    //create the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *registerAdminButton = new QPushButton("Register Admin");
    QPushButton *registerSellerButton = new QPushButton("Register Seller");

    connect(registerAdminButton, &QPushButton::clicked, this, &ProductManager::onRegisterAdminClicked);
    connect(registerSellerButton, &QPushButton::clicked, this, &ProductManager::onRegisterSellerClicked);

    buttonLayout->addWidget(registerAdminButton);
    buttonLayout->addWidget(registerSellerButton);

    mainLayout->addLayout(buttonLayout);

    QLabel *manageAccountsLabel = new QLabel("Manage Accounts:");
    mainLayout->addWidget(manageAccountsLabel);


        QTableWidget *accountsTable = new QTableWidget();
        makeAccountsTable(accountsTable);
        mainLayout->addWidget(accountsTable);

    mainLayout->addStretch();
}
QString cached(const QString &resPath) {
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

void ProductManager::makeAccountsTable(QTableWidget *accountsTable) {
    qDebug()<<"MADE ACCOUNTS TABLE";
    //using QList to store User data before displaying them in the table
    QList<User> users;
    QFile file(cached(":/UsersInfo/UserData.txt"));
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(" :");
            if (parts.size() >= 3) {
                User client;
                client.setRole(parts[0]);
                client.setUsername(parts[1]);
                client.setPassword(parts[2]);
                users.append(client);
            }
        }
        file.close();
        if(file.isOpen())
        {
            file.close();
        }
    } else {
        qDebug() << "Error opening file"<< file.errorString();
        return;
    }

    qDebug() << "Number of users:" << users.size();

    accountsTable->setRowCount(users.size());

    qDebug() << "Row count of the table:" << accountsTable->rowCount();

    int numColumns = 6;
    accountsTable->setColumnCount(numColumns);

    QStringList headers;
    headers << "Role" << "Username" << "Password" << "     " << "     " << "     ";
    accountsTable->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < users.size(); ++i) {
        User client = users.at(i);
        QTableWidgetItem *roleItem = new QTableWidgetItem(client.getRole());
        QTableWidgetItem *usernameItem = new QTableWidgetItem(client.getUsername());
        QTableWidgetItem *passwordItem = new QTableWidgetItem();
        //adding a placeholder to protect private data from unauthorized access
        passwordItem->setData(Qt::DisplayRole, "********");

        //button to reveal the password, requiring admin badge number
        QPushButton* showPasswordButton = new QPushButton("Show Password");
        showPasswordButton->setProperty("userIndex", i); //set a property to identify the user index

        connect(showPasswordButton, &QPushButton::clicked, this, [=]() {
            int userIndex = showPasswordButton->property("userIndex").toInt();
            bool isVerified;
            QString secretNumber = QInputDialog::getText(this, "Enter Authorized Badge Number", "Enter authorized badge number:");
            Admin* ad = dynamic_cast<Admin*>(user);
            if(ad && (ad->getBadgeNum()) == secretNumber)
                isVerified = true;
            if (isVerified) {
                QTableWidgetItem *passwordItem = accountsTable->item(userIndex, 2);
                if (passwordItem) {
                    //set the real pass
                    passwordItem->setData(Qt::DisplayRole, client.getPassword());
                }
            }
        });

        QPushButton* deleteUserButton = new QPushButton("Delete User");
        deleteUserButton->setProperty("userIndex", i);

        connect(deleteUserButton, &QPushButton::clicked, this, [=]() {
            int userIndex = deleteUserButton->property("userIndex").toInt();
            if (client.getRole() == "admin")
                allusers -> deleteUser(AllUsers::admin, client.getUsername());
            else if (client.getRole() == "customer")
                allusers -> deleteUser(AllUsers::customer, client.getUsername());
            else if (client.getRole() == "seller")
                allusers -> deleteUser(AllUsers::seller, client.getUsername());
            qDebug()<< "deleted";
            allusers -> SaveUsers();
            accountsTable->removeRow(userIndex);
        });

        QPushButton* deactiveUserButton = new QPushButton("Deactivate User");
        deactiveUserButton->setProperty("userIndex", i);

        connect(deactiveUserButton, &QPushButton::clicked, this, [=]() {
            int userIndex = deactiveUserButton->property("userIndex").toInt();
            if (client.getRole() == "admin")
                allusers -> deActivateUser(AllUsers::admin, client.getUsername());
            else if (client.getRole() == "customer")
                allusers -> deActivateUser(AllUsers::customer, client.getUsername());
            else if (client.getRole() == "seller")
                allusers -> deActivateUser(AllUsers::seller, client.getUsername());
        });

        accountsTable->setItem(i, 0, roleItem);
        accountsTable->setItem(i, 1, usernameItem);
        accountsTable->setItem(i, 2, passwordItem);
        accountsTable->setCellWidget(i, 3, showPasswordButton);
        accountsTable->setCellWidget(i, 4, deactiveUserButton);
        accountsTable->setCellWidget(i, 5, deleteUserButton);
    }
}

void ProductManager::createSellerView(){
    ui->addProductButton->setVisible(true);
    ui->addProductButton->move(widthFull-(135), ui->filterBox->y());
    ui->sellerLogo->setVisible(true);
    QPixmap sellLogo;
    int w = ui->sellerLogo->width();
    int h = ui->sellerLogo->height();

    if (user->getUsername() == "AUCBookstore") {
        sellLogo.load(":/logos/assets/AUCBookstoreLogo.png");
    } else if (user->getUsername() == "VirginBookstore") {
        sellLogo.load(":/logos/assets/VirginBookstore.png");
    } else if (user->getUsername() == "ReadersCorner") {
        sellLogo.load(":/logos/assets/ReadersCorner.png");
    } else {
        // Set a default logo or hide the logo widget
        ui->sellerLogo->setVisible(false);
        ui->XLogo->setVisible(false);
    }

    ui->sellerLogo->setPixmap(sellLogo.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    qDebug() << "Creating seller view...";
    initializeProducts(); // Call initialize products to set the sellerProducts vector
    qDebug() << "Product initialization in createSellerView completed...";
    vector<Products*> myProducts = getSellerProducts();

    ui->basedonyouLogo->setVisible(false);
    ui->ourproductsLogo->setVisible(false);
    ui->basedonsearchLogo->setVisible(false);

    clearLayout(ui->recsLayout);
    clearLayout(ui->allproductsLayout);

    ui->allproductsLayout->parentWidget()->lower();

    int recsLayoutHeight = ui->recsLayout->parentWidget()->height() + 40;
    ui->recsLayout->parentWidget()->resize(widthFull - 100, recsLayoutHeight);

    //create a grid layout for displaying the seller's products
    QGridLayout* sellerProductsLayout = new QGridLayout();
    sellerProductsLayout->setAlignment(Qt::AlignTop);

    int maxItemsInRow = 10;
    int itemsInRow = 0;
    int row = 0;
    int col = 0;
    int productCount = 0;

    for (Products* product : myProducts) {
        if (productCount >= 20 || row >= 2) {
            break;
        }
        if (!isProductDisplayed(product)) {
            QString name;
            QPixmap imagePath;
            double price;
            int quantity;

            Books* book = dynamic_cast<Books*>(product);
            Accessories* accessory = dynamic_cast<Accessories*>(product);
            Techs* tech = dynamic_cast<Techs*>(product);

            if (book) {
                name = book->getName();
                imagePath = book->getImage();
                price = book->getPrice();
                quantity = book->getQuantity();
            } else if (accessory) {
                name = accessory->getName();
                imagePath = accessory->getImage();
                price = accessory->getPrice();
                quantity = accessory->getQuantity();
            } else if (tech) {
                name = tech->getName();
                imagePath = tech->getImage();
                price = tech->getPrice();
                quantity = tech->getQuantity();
            }

            if (!imagePath.isNull()) {
                // Create widgets for the product
                QVBoxLayout* productLayout = new QVBoxLayout();
                QLabel* imageLabel = new QLabel();
                //yomna: does not keep aspect ratio->kepps ratio of label
                imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                imageLabel->setScaledContents(true);
                QLabel* nameLabel = new QLabel(name);
                nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                nameLabel->setMaximumWidth(imageLabel->width());
                nameLabel->setWordWrap(true);
                QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                priceLabel->setFont(QFont("Optima", 12));
                QLabel* quanityLabel = new QLabel(QString::number(quantity) + " Avaliable");
                quanityLabel->setFont(QFont("Optima", 12, QFont::ExtraLight));

                productLayout->addWidget(imageLabel);
                productLayout->addWidget(nameLabel);
                productLayout->addWidget(priceLabel);
                productLayout->addWidget(quanityLabel);
                productLayout->setAlignment(Qt::AlignTop);

                sellerProductsLayout->addLayout(productLayout, row, col);

                itemsInRow++;

                if (itemsInRow >= maxItemsInRow) {
                    row++;
                    col = 0;
                    itemsInRow = 0;
                } else {
                    col++;
                }
                productCount++;
                displayedProducts.push_back(product);
            } else {
                qDebug() << "Invalid image path for product: " << name;
            }
        }
    }

    if (addedNewProduct) {
        for (Products* product : sellerNewProducts) {
            if (productCount >= 20 || row >= 2) {
                break;
            }
            if (!isProductDisplayed(product)) {
                QString name;
                QPixmap imagePath;
                double price;
                int quantity;

                Books* book = dynamic_cast<Books*>(product);
                Accessories* accessory = dynamic_cast<Accessories*>(product);
                Techs* tech = dynamic_cast<Techs*>(product);

                if (book) {
                    name = book->getName();
                    imagePath = book->getImage();
                    price = book->getPrice();
                    quantity = book->getQuantity();
                } else if (accessory) {
                    name = accessory->getName();
                    imagePath = accessory->getImage();
                    price = accessory->getPrice();
                    quantity = accessory->getQuantity();
                } else if (tech) {
                    name = tech->getName();
                    imagePath = tech->getImage();
                    price = tech->getPrice();
                    quantity = tech->getQuantity();
                }

                if (!imagePath.isNull()) {
                    // Create widgets for the product
                    QVBoxLayout* productLayout = new QVBoxLayout();
                    QLabel* imageLabel = new QLabel();
                    imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                    imageLabel->setScaledContents(true);
                    QLabel* nameLabel = new QLabel(name);
                    nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                    nameLabel->setMaximumWidth(imageLabel->width());
                    nameLabel->setWordWrap(true);
                    QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                    priceLabel->setFont(QFont("Optima", 12));
                    QLabel* quanityLabel = new QLabel(QString::number(quantity) + " Avaliable");
                    quanityLabel->setFont(QFont("Optima", 12, QFont::ExtraLight));

                    productLayout->addWidget(imageLabel);
                    productLayout->addWidget(nameLabel);
                    productLayout->addWidget(priceLabel);
                    productLayout->addWidget(quanityLabel);
                    productLayout->setAlignment(Qt::AlignTop);

                    sellerProductsLayout->addLayout(productLayout, row, col);

                    itemsInRow++;

                    if (itemsInRow >= maxItemsInRow) {
                        row++;
                        col = 0;
                        itemsInRow = 0;
                    } else {
                        col++;
                    }
                    productCount++;
                    displayedProducts.push_back(product);
                } else {
                    qDebug() << "Invalid image path for product: " << name;
                }
            }
        }
        addedNewProduct=false;
    }

    ui->recsLayout->addLayout(sellerProductsLayout);
}

void ProductManager::onCartClicked(){
    qDebug() << "cart clicked, moving to shopping cart ui.";

    cart->resize(widthFull, heightFull);
    cart->show();
    hide();
}

void ProductManager::onSignOutClicked(){
    qDebug() << "signing out!";

    Customer *customer = dynamic_cast<Customer *>(user);
    if(customer){
        for(const auto& item : ShoppingCart::Cart){
            Customer::UserCart cart(item.name, item.quantity);
            customer->addToCartVec(cart);

        }
    }

    Seller *sell = dynamic_cast<Seller *>(user);
    if(sell){
        loadNewProduct();
    }

    LoginWindow* login = new LoginWindow(nullptr, allusers);
    login-> resize(widthFull, heightFull); //resizing according to the QScreen measurements
    login-> setWindowTitle("Login");
    login -> show();
    allusers-> SaveUsers();
    hide();
}

void ProductManager::onAddToCartClicked(){
    qDebug() << "sending product data to shopping cart";
    //Rawan, your part
}

void ProductManager::onNextClicked(){
    beforeCallProducts.clear();
    ui->searchLineEdit->setVisible(false);
    if(!secondPage)
        makeSecondPage();
    else if(!thirdPage)
        makeThirdPage();
    else if(!fourthPage)
        makeFourthPage();
}

void ProductManager::onPrevClicked(){
    remarkItemsBeforeCall();
    ui->searchLineEdit->setVisible(true);
    showPrevious();
}

void ProductManager::remarkItemsBeforeCall(){
    for(Products* prod: beforeCallProducts){
        //remove_if to move the items to be removed to the end of the vector
        displayedProducts.erase(remove_if(displayedProducts.begin(), displayedProducts.end(),
                                          [&](Products* p) { return p == prod; }), displayedProducts.end());
    }
}

Books* ProductManager::createBook(const QString& name, double price, int quantity, bool availability, const QString& imagePath, const QString& seller, const QString& genre, const QString& author, const QString& ISBN){
    QPixmap image(imagePath);
    return new Books(name, price, quantity, availability, image, seller, genre, author, ISBN);
}

Accessories* ProductManager::createAccessory(const QString& name, double price, int quantity, bool availability, const QString& imagePath, const QString& seller, const QString& type, QString size) {
    QPixmap image(imagePath);
    return new Accessories(name, price, quantity, availability, image, seller, type, size);
}

Techs* ProductManager::createTech(const QString& name, double price, int quantity, bool availability, const QPixmap& imagePath, const QString& seller, int type){
    QPixmap image(imagePath);
    return new Techs(name, price, quantity, availability, image, seller, type);
}

/*
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

void ProductManager::loadProducts(){
    //load all user data
    qDebug() << "loading users:";

    QFile bookData (cachedResource(":/Books/bookData.txt"));

    if (bookData.setPermissions(QFile::ReadOwner))
        qDebug() << "Permissions updated successfully for file:";
    else
        qDebug() << "Error updating permissions for file:" ;

    bookData.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&bookData);
    while(!in.atEnd()) {
        QString data = in.readLine();
        qDebug()<< data;
        QStringList splitdata = data.split ("{");
        qDebug()<< splitdata[0];
    }
}
*/
void ProductManager::initializeProducts() {
    qDebug()<< "Initializing...";
    QString productsData[][9] = {
        {"Anna Karenina", "12.2", "23", "true", ":/Books/assets/anna kare.jpeg", "Classics", "Leo Tolstoy", "9780393042771", "ReadersCorner"},
        {"A Tale of Two Cities", "89.5", "2", "true", ":/Books/assets/tale of two.jpeg", "Classics", "Charles Dickens", "9780582400115", "AUCBookstore"},
        {"Oliver Twist", "100", "6", "true", ":/Books/assets/oliver.jpeg", "Classics", "Charles Dickens", "9780140430172", "AUCBookstore"},
        {"Julius Caesar", "64", "5", "true", ":/Books/assets/ceaser.jpeg", "Plays", "William Shakespeare", "9780743482745", "AUCBookstore"},
        { "The Days", "93", "2", "true", ":/Books/assets/days.jpeg" , "Arabic Literature" , "Taha Hussein" , "9781617971310", "ReadersCorner"},
        { "Doaa Al-Karawan", "50", "21", "true", ":/Books/assets/karawan.jpeg" , "Arabic Literature" , "Taha Hussein" , "9789771497011", "ReadersCorner"},
        { "1984", "120", "1", "true", ":/Books/assets/1984.jpeg" , "Classics" , "George Orwell" , "9780155658110", "ReadersCorner"},
        { "Animal Farm", "125.6", "0", "true", ":/Books/assets/animal farm.jpeg" , "Classics" , "George Orwell" , "9788129116123", "ReadersCorner"},
        { "The Da Vinci Code", "78", "12", "true", ":/Books/assets/davinci code.jpeg" , "Classics" , "Dan Brown" , "9780307277671", "ReadersCorner"},
        { "Angels and Demons", "43", "9", "true", ":/Books/assets/angels anddemons.jpeg" , "Classics" , "Dan Brown" , "9780743486224", "ReadersCorner"},
        { "Mrs. Dalloway", "65", "6", "true", ":/Books/assets/room of ones.jpeg" , "Classics" , "Virginia Woolf" , "9780199536009", "VirginBookstore"},
        { "A Room of One’s Own", "43", "5", "true", ":/Books/assets/dalloway.jpeg" , "Classics" , "Virginia Woolf" , "9780199536009", "ReadersCorner"},
        { "Wuthering Heights", "64", "7", "true", ":/Books/assets/wutheruing heights.jpeg" , "Classics" , "Emily Bronte" , "9780175565757", "VirginBookstore"},
        { "Jane Eyre", "78", "34", "true", ":/Books/assets/jane eyre.jpeg" , "Classics" , "Charlotte Bronte" , "9780785294788", "ReadersCorner"},
        { "Villette", "46", "6", "true", ":/Books/assets/villette.jpeg" , "Classics" , "Charlotte Bronte" , "9781853260193","ReadersCorner"},
        { "The Great Gatsby", "73", "3", "true", ":/Books/assets/gatsby.jpeg" , "Classics" , "F. Scott Fitzgerald" , "9780393042375", "VirginBookstore"},
        { "Tender is The Night", "44", "6", "true", ":/Books/assets/tender is.jpeg" , "Classics" , "F. Scott Fitzgerald" , "9780684151519", "ReadersCorner"},
        { "The Stranger", "67", "5", "true", ":/Books/assets/stranger.png" , "Philosophy" , "Albert Camus" , "9780679720201", "ReadersCorner"},
        { "The Plague", "72", "8", "true", ":/Books/assets/plague.jpeg" , "Philosophy" , "Albert Camus" , "9780307827807", "ReadersCorner"},
        { "The Old Man and The Sea", "30", "19", "true", ":/Books/assets/old man.jpeg" , "Classics" , "Ernest Hemingway" , "9787201046440", "AUCBookstore"},
        { "For whom the Bell Tolls", "31", "20", "true", ":/Books/assets/the bell tolls.jpeg" , "Classics" , "Ernest Hemingway" , "9780307273789", "ReadersCorner"},
        { "The Three Musketeers", "87", "6", "true", ":/Books/assets/musketeers.jpeg" , "Classics" , "Leo Tolstoy" , "9783954183531", "ReadersCorner"},
        { "The Count of Monte Cristo", "100", "2", "true", ":/Books/assets/monte cristo.jpeg" , "Classics" , "Alexander Dumas" , "9780199219650", "AUCBookstore"},
        { "The Prophet", "87", "10", "true", ":/Books/assets/prophet.jpeg" , "Poetry" , "Khalil Gibran" , "9783530268003", "AUCBookstore"},
        { "Broken Wings", "32", "23", "true", ":/Books/assets/broken wings.jpeg" , "Arabic Literature" , "Khalil Gibran" , "9788177697025", "AUCBookstore"},
        { "Granada", "40", "5", "true", ":/Books/assets/granada.jpeg" , "Classics" , "Leo Tolstoy" , "9780393042375", "ReadersCorner"},
        { "Al Tantouriah", "50", "2", "true", ":/Books/assets/tantouriah.jpeg" , "Palestine" , "Radwa Ashour" , "9789770928295", "VirginBookstore"},
        { "Fi Al-Quds", "26", "4", "true", ":/Books/assets/fi alquds.jpeg" , "Palestine" , "Tamim Al-Barghouthi" , "", "AUCBookstore"},
        { "Ya Masr Hanet", "20", "20", "true", ":/Books/assets/ya masr hanet.jpeg" , "Poetry" , "Tamim Al-Barghouthi" , "", "VirginBookstore"},
        { "I saw Ramallah", "45", "2", "true", ":/Books/assets/i saw ramallah.jpeg" , "Palestine" , "Mourid Al-Barghouthi" , "9789774247552", "ReadersCorner"},
        { "I Was Born There, I Was Born Here", "40", "15", "true", ":/Books/assets/i was born.jpeg" , "Palestine" , "Mourid Al-Barghouthi" , "9781408829097", "VirginBookstore"},
        { "Returning To Haifa", "39", "14", "true", ":/Books/assets/haifa.jpeg" , "Palestine" , "Ghassan Kanafani" , "9780571347827", "AUCBookstore"},
        { "Men in The Sun", "37", "18", "true", ":/Books/assets/men in the sun.jpeg" , "Palestine" , "Ghassan Kanafani" , "9780894108570", "VirginBookstore"},
        { "Beirut Nightmares", "29", "10", "true", ":/Books/assets/beirut nightmares.jpeg" , "Arabic Literature" , "Ghada Al-Samman" , "9780704380653", "VirginBookstore"},
        { "No Sea in Beirut", "28", "23", "true", ":/Books/assets/no sea in beirut.jpg" , "Arabic Literature" , "Ghada Al-Samman" , "", "AUCBookstore"},
        { "The Hundred Years’ War on Palestine", "45", "5", "true", ":/Books/assets/the hundred years war on palestine.jpeg" , "Palestine" , "Rashid Khalidi" , "9781627798549", "AUCBookstore"},
        { "The Iron Cage", "43", "4", "true", ":/Books/assets/iron cage.jpeg" , "Palestine" , "Rashid Khalidi" , "9780807003084", "AUCBookstore"},
        { "Huda F Are You?", "20", "23", "true", ":/Books/assets/huda f.jpeg" , "Comic {" , "Huda Fahmy" , "9780593324318", "AUCBookstore"},
        { "Yes, I’m Hot in This", "23", "3", "true", ":/Books/assets/hot in this.jpeg" , "Comic {" , "Huda Fahmy" , "9781507209349", "AUCBookstore"},
        { "The Kite Runner", "42", "6", "true", ":/Books/assets/kite runner.jpeg" , "Arab-American" , "Khaled Hosseini" , "9781594631931", "AUCBookstore"},
        { "A Thousand Splendid Suns", "41", "2", "true", ":/Books/assets/splendid suns.jpeg" , "Arab-American" , "Khaled Hosseini" , "9780143180654", "AUCBookstore"}
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
        QString seller = data[8];
        qDebug() << "Seller: " << seller;

        Books* product = createBook(name, price, quantity, availability, imagePath, seller, genre, author, ISBN);
        bookProducts->push_back(product);
        allProducts.push_back(product);
        Customer *customer = dynamic_cast<Customer*>(user);
        if(customer){
        for(const auto &item : customer->getShopingCart()){
            if(item.name == name){
                if(quantity > 0){
                    cart->AddItemToCart(imagePath, name, price,item.quant);
                }else{

                     QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));
                }

            }


        }}
    }

    QFile sellerBooks(cached(":/UsersInfo/sellerEnteredProducts.txt"));
    if (sellerBooks.setPermissions(QFile::ReadOwner))
        qDebug() << "Permissions updated successfully for file:";
    else
        qDebug() << "Error updating permissions for file:" ;

    sellerBooks.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&sellerBooks);
    QString bookData = in.readLine();
    qDebug()<< bookData;
    QStringList data = bookData.split ("\", \"");
    bool atEnd = false;
    while(!atEnd) {
        if (data [0] == "book")
        {QString name = data[1];
        double price = data[2].toDouble();
        int quantity = data[3].toInt();
        bool availability = (data[4].compare("true", Qt::CaseInsensitive) == 0);
        QString imagePath = data[5];
        QString genre = data[6];
        QString author = data[7];
        QString ISBN = data[8];
        QString seller = data[9];
        qDebug()<< "seller :"<< seller;
        Books* product = createBook(name, price, quantity, availability, imagePath, seller, genre, author, ISBN);
        bookProducts->push_back(product);
        allProducts.push_back(product);
        Customer *customer = dynamic_cast<Customer*>(user);
        if(customer){
            for(const auto &item : customer->getShopingCart()){
                if(item.name == name){
                    if(quantity > 0){
                        cart->AddItemToCart(imagePath, name, price,item.quant);
                    }else{

                        QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));
                    }


                }


        }}
        }

        if (in.atEnd())
            atEnd = true;
    }

    sellerBooks.close();

    QString accessoriesData[][8] = {
                                    {"Books Defense Tshirt", "25", "5", "true", ":/Tshirts/assets/Books Defense Tshirt.jpeg", "T-shirt", "M", "MedadBookstore"},
                                    {"Cool Kids Tshirt", "20", "5", "true", ":/Tshirts/assets/Cool Kids Are Reading.jpeg", "T-shirt", "L", "MedadBookstore"},
                                    { "I’d Rather Be Reading Tshirt","30", "5", "true", ":/Tshirts/assets/I'd Rather tshirt.jpeg"  ,  "T-shirt",   "S", "MedadBookstore"},
                                    { " Reading TicketTshirt","30", "5", "true", ":/Tshirts/assets/Reading Ticket Tshirst.jpeg"  ,  "T-shirt",   "XS", "MedadBookstore"},
                                    { "Raising Readers Tote Bag","36", "5", "true", ":/Bags/assets/Raising Readers Tote Bag.jpeg"  ,  "Bag",   " ", "VirginBookstore"},
                                    { "Book Stack Tote Bag","38", "5", "true", ":/Bags/assets/Book Stack Tote Bag.jpeg"  ,  "Bag",   " ", "MedadBookstore"},
                                    { "Medad Merchandise Tote Bag","40", "5", "true", ":/Bags/assets/Screenshot 2024-05-01 145322.png"  ,  "Bag",   " ", "MedadBookstore"},
                                    { " Bookmark Set","10", "5", "true", ":/BookMarks/assets/Bookmark Set1.jpeg"  ,  "BookMarks",   " ", "VirginBookstore"},
                                    { " Bookmark Set","10", "5", "true", ":/BookMarks/assets/Bookmark Set3.jpeg"  ,  "BookMarks",   " ", "MedadBookstore"},
                                    { " Bookmark Set","10", "5", "true", ":/BookMarks/assets/Bookmark Set2.jpeg"  ,  "BookMarks",   " ", "MedadBookstore"},
                                    { " Bookmark Palestine","15", "5", "true", ":/BookMarks/assets/Bookmark Set Plaestine 1.jpeg"  ,  "BookMarks",   " ", "MedadBookstore"},
                                    { " Bookmark Palestine","15", "5", "true", ":/BookMarks/assets/Bookmark Set Palestine2.jpeg"  ,  "BookMarks",   " ", "MedadBookstore"},
                                    { " Bookmark Harry Potter","20", "5", "true", ":/BookMarks/assets/Bookmark Set Harry Potter2.jpeg"  ,  "BookMarks",   " ", "MedadBookstore"},
                                    { " Bookmark Egyptian","25", "5", "true", ":/BookMarks/assets/Bookmark Set Egyptian 2.jpeg"  ,  "BookMarks"," ", "VirginBookstore"},
                                    { " Bookmark Arabic","30", "5", "true", ":/BookMarks/assets/Bookmark Set Arabic 2.jpeg"  ,  "BookMarks", " ", "MedadBookstore"},
                                    };

    for (const auto& data : accessoriesData) {
        QString name = data[0];
        double price = data[1].toDouble();
        int quantity = data[2].toInt();
        bool availability = (data[3].compare("true", Qt::CaseInsensitive) == 0);
        QString imagePath = data[4];
        QString type = data[5];
        QString size = data[6];
        QString seller = data[7];
        qDebug() << "Seller: " << seller;

        Accessories* accessory = createAccessory(name, price, quantity, availability, imagePath, seller, type, size);
        accessoryProducts->push_back(accessory);
        allProducts.push_back(accessory);

        Customer *customer = dynamic_cast<Customer*>(user);
        if(customer){
        for(const auto &item : customer->getShopingCart()){

            if(item.name == name){
                cart->AddItemToCart(imagePath, name, price,item.quant);
            }



        }}
    }

    QString techsData[][7] = {
        {"Kindle", "500", "5", "true", ":/Techs/assets/Kindle.jpeg", "1", "VirginBookstore"},
        {"BookLight", "200", "5", "true", ":/Techs/assets/Book Light.jpeg", "2", "VirginBookstore"},
        {"ReadingLight", "250", "5", "true", ":/Techs/assets/Reading Light.jpeg", "3", "VirginBookstore"}
    };

    for (const auto& data : techsData) {
        QString name = data[0];
        double price = data[1].toDouble();
        int quantity = data[2].toInt();
        bool availability = (data[3].compare("true", Qt::CaseInsensitive) == 0);
        QString imagePath = data[4];
        int type = data[5].toInt();
        QString seller = data[6];
        qDebug() << "Seller: " << seller;

        Techs* tech = createTech(name, price, quantity, availability, QPixmap(imagePath), seller, type);
        techyProducts->push_back(tech);
        allProducts.push_back(tech);

        Customer *customer = dynamic_cast<Customer*>(user);
        if(customer){
        for(const auto &item : customer->getShopingCart()){

                if(item.name == name){
                    if(quantity > 0){
                        cart->AddItemToCart(imagePath, name, price,item.quant);
                    }else{

                        QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));
                    }


                }


        }}
    }
}

vector<Products*> ProductManager::getSellerProducts(){
    qDebug() << "Getting Seller Products...";
    qDebug() << "Found " << allProducts.size();
    Seller* seller = dynamic_cast<Seller*>(user);
    if (seller) {
        vector<Products*> sellerProducts;
        QString username = seller->getUsername();
        qDebug() << "User's username: " << user->getUsername();
        for (Products* product : allProducts) {
            qDebug() << "Product seller: " << product->getSeller();
            if (product->getSeller() == username) {
                sellerProducts.push_back(product);
            }
        }
        qDebug() << "Found " << sellerProducts.size() << " products for seller " << username;
        if (sellerProducts.size() == 0)
            ui -> sellerError -> setVisible(true);
        else
            ui -> sellerError -> setVisible(false);
        return sellerProducts;
    } else {
        qDebug() << "User is not a seller";
        return vector<Products*>(); //return empty vector
    }
}

vector<Products*> ProductManager::suggestSimilarItems(){
    if (!user) {
        qDebug() << "Error: No user logged in.";
        return {};
    }

    Customer* customer = dynamic_cast<Customer*>(user);

    if (!customer) {
        qDebug() << "Error: User is not a Customer.";
        return {};
    }

    vector<Products*> suggestions;
    const vector<QString>& preferredGenres = customer->getPreferredGenres();

    //if the product genre matches any preferred genre
    for (const QString& genre : preferredGenres) {
        for (const auto& book : *bookProducts) {
            if (book->getGenre() == genre) {
                suggestions.push_back(book); //add the book to suggestions
                if (suggestions.size() >= 8) {
                    return suggestions; //only taking five suggestions
                }
                break;
            }
        }
    }
    //fill the rest with random books if suggestions less than 5
    while (suggestions.size() < 8 && !bookProducts->empty()) {
        suggestions.push_back(bookProducts->back());
        bookProducts->pop_back();
    }

    return suggestions;
}

void ProductManager::makeFirstPage(){


    displayedProducts.clear();
    firstPage = true;
    showSuggestions();

    firstPageProducts.clear();

    int productLayoutHeight = heightFull + 10;

    ui->allproductsLayout->parentWidget()->resize(widthFull-100, productLayoutHeight);

    int maxIteminRow = 10;
    int iteminRow = 0;
    QHBoxLayout* currentRowLayout = new QHBoxLayout();

    for (Products* product : *bookProducts) {
        Books* book = dynamic_cast<Books*>(product);
        if (book) {
            QString name = book->getName();
            QPixmap imagePath = book->getImage();
            double price = book->getPrice();
            if (!imagePath.isNull()) {
                QVBoxLayout* bookLayout = new QVBoxLayout();

                QLabel* imageLabel = new QLabel();
                imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));

                QLabel* nameLabel = new QLabel(name);
                nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                nameLabel->setMaximumWidth(imageLabel->width());
                nameLabel->setWordWrap(true);

                QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                priceLabel->setFont(QFont("Optima", 12));

                ClickableLabels* addtoCart = new ClickableLabels(this);
                QPixmap addPix(":/logos/assets/addtoCart.png");
                addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                connect(addtoCart, &ClickableLabels::clicked, [this, book, imagePath, name, price](){
                    if(book->getQuantity() > 0){
                        this->cart->AddItemToCart(imagePath,name, price, 1);
                    }else{
                        QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));

                    }
                });
                //add the labels to the book layout
                bookLayout->addWidget(imageLabel);
                bookLayout->addWidget(nameLabel);
                bookLayout->addWidget(priceLabel);
                bookLayout->addWidget(addtoCart);

                //set alignment for the book layout
                bookLayout->setAlignment(Qt::AlignTop);

                //add the book layout to the current row layout
                currentRowLayout->addLayout(bookLayout);
                displayedProducts.push_back(book);
                firstPageProducts.push_back(book);
                beforeCallProducts.push_back(book);

                //increment the number of books in the current row
                iteminRow++;

                //check if we need to start a new row
                if (iteminRow >= maxIteminRow) {
                    break;
                }
            } else {
                qDebug() << "Invalid image path for book: " << name;
            }
        }
    }

    //add the last row layout to the main layout
    ui->allproductsLayout->addLayout(currentRowLayout);

}

void ProductManager::searchProducts(const QString &keyword) {


    ui->allproductsLayout->parentWidget()->raise();
    ui->basedonyouLogo->setVisible(false);
    ui->ourproductsLogo->setVisible(false);
    ui->basedonsearchLogo->setVisible(true);

    clearLayout(ui->recsLayout);
    clearLayout(ui->allproductsLayout);

    ClickableLabels* nextButton= new ClickableLabels(this);
    QPixmap nextPix(":/logos/assets/nextLogo.png");
    nextButton->setPixmap(nextPix.scaled(70, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    nextButton->move(widthFull/2, 800);
    connect(nextButton, &ClickableLabels::clicked, this, &ProductManager::onNextClicked);

    if (keyword.isEmpty()) {
        ui->basedonsearchLogo->setVisible(false);
        ui->basedonyouLogo->setVisible(true);
        ui->ourproductsLogo->setVisible(true);
        nextButton->setVisible(true);
        prevButton->setVisible(true);
        makeFirstPage(); //display the default layout when the keyword is empty
        return;
    }

    QSet<QString> displayedBooks; //track displayed books to ensure uniqueness
    int displayedCountinRecs = 0;
    int displayedCountinAll = 0;
    int max = 10;

    for (Products* product : *bookProducts) {
        Books* book = dynamic_cast<Books*>(product);
        if (book && (book->getName().contains(keyword, Qt::CaseInsensitive) || book->getGenre().contains(keyword, Qt::CaseInsensitive))){
            if (displayedBooks.contains(book->getName())) {
                continue; //skip, book already displayed
            }
            if (displayedCountinRecs < max) {
                if (book) {
                    QString name = book->getName();
                    QPixmap imagePath = book->getImage();
                    double price = book->getPrice();
                    if (!imagePath.isNull()) {
                        QVBoxLayout* bookLayout = new QVBoxLayout();

                        QLabel* imageLabel = new QLabel();
                        imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));

                        QLabel* nameLabel = new QLabel(name);
                        nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                        nameLabel->setMaximumWidth(imageLabel->width());
                        nameLabel->setWordWrap(true);

                        QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                        priceLabel->setFont(QFont("Optima", 12));

                        ClickableLabels* addtoCart = new ClickableLabels(this);
                        QPixmap addPix(":/logos/assets/addtoCart.png");
                        addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));

                        connect(addtoCart, &ClickableLabels::clicked, [this, book, imagePath, name, price](){
                            if(book->getQuantity() > 0){
                                this->cart->AddItemToCart(imagePath,name, price, 1);
                            }else{
                                QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));

                            }
                        });
                        //connect(addtoCart, &ClickableLabels::clicked, this, &ProductManager::onAddToCartClicked);

                        bookLayout->addWidget(imageLabel);
                        bookLayout->addWidget(nameLabel);
                        bookLayout->addWidget(priceLabel);
                        bookLayout->addWidget(addtoCart);

                        bookLayout->setAlignment(Qt::AlignTop);

                        ui->recsLayout->addLayout(bookLayout);
                        displayedBooks.insert(name);
                        displayedCountinRecs++;
                    } else {
                        qDebug() << "Invalid image path for book: " << name;
                    }
                }
            } else {
                if (displayedCountinAll < max) {
                    if (book) {
                        QString name = book->getName();
                        QPixmap imagePath = book->getImage();
                        double price = book->getPrice();
                        if (!imagePath.isNull()) {
                            QVBoxLayout* bookLayout = new QVBoxLayout();

                            QLabel* imageLabel = new QLabel();
                            imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));

                            QLabel* nameLabel = new QLabel(name);
                            nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                            nameLabel->setMaximumWidth(imageLabel->width());
                            nameLabel->setWordWrap(true);

                            QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                            priceLabel->setFont(QFont("Optima", 12));

                            ClickableLabels* addtoCart = new ClickableLabels(this);
                            QPixmap addPix(":/logos/assets/addtoCart.png");
                            addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                            connect(addtoCart, &ClickableLabels::clicked, [this, book, imagePath, name, price](){

                                if(book->getQuantity() > 0){
                                    this->cart->AddItemToCart(imagePath,name, price, 1);
                                }else{
                                    QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));

                                }
                            });

                            bookLayout->addWidget(imageLabel);
                            bookLayout->addWidget(nameLabel);
                            bookLayout->addWidget(priceLabel);
                            bookLayout->addWidget(addtoCart);

                            bookLayout->setAlignment(Qt::AlignTop);

                            ui->allproductsLayout->addLayout(bookLayout);
                            displayedBooks.insert(name);
                            displayedCountinAll++;
                        } else {
                            qDebug() << "Invalid image path for book: " << name;
                        }
                    }
                } else {
                    break; //limit reached, stop displaying more in allproductsLayout
                }
            }
        }
    }
    ui->recsLayout->setAlignment(Qt::AlignHCenter);
    ui->allproductsLayout->setAlignment(Qt::AlignHCenter);
    ui->allproductsLayout->parentWidget()->lower();
    ui->recsLayout->parentWidget()->raise();
    nextButton->setVisible(true);
    prevButton->raise();
    nextButton->raise();



}


void ProductManager::showSuggestions(){
    ui->basedonsearchLogo->setVisible(false);
    ui->basedonyouLogo->setVisible(true);

    initializeProducts();
    vector<Products*> recommendations;
    recommendations = suggestSimilarItems();

    int recsLayoutHeight = ui->recsLayout->parentWidget()->height() + 40;

    //adjusting the size of the parent widget of recsLayout
    ui->recsLayout->parentWidget()->resize(widthFull-100, recsLayoutHeight);

    int column = 0; //track the column index for the current book

    for (Products* product : recommendations) {
        Books* book = dynamic_cast<Books*>(product);
        if (book) {
            //retrieve book information from the bookProducts vector
            QString name = book->getName();
            QPixmap imagePath = book->getImage();
            double price = book->getPrice();

            if (!imagePath.isNull()) {
                QVBoxLayout* bookLayout = new QVBoxLayout();
                //create a QLabel for displaying the book's image
                QLabel* imageLabel = new QLabel();
                imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));

                //create QLabel for name
                QLabel* nameLabel = new QLabel(name);
                nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                nameLabel->setMaximumWidth(imageLabel->width());
                nameLabel->setWordWrap(true);

                //create QLabel for price
                QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                priceLabel->setFont(QFont("Optima", 12));

                //create add to cart label
                ClickableLabels* addtoCart = new ClickableLabels(this);
                QPixmap addPix(":/logos/assets/addtoCart.png");
                addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                connect(addtoCart, &ClickableLabels::clicked, [this, book, imagePath, name, price](){

                    if(book->getQuantity() > 0){
                        this->cart->AddItemToCart(imagePath,name, price, 1);
                    }else{
                        QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));

                    }
                });
                //connect(addtoCart, &ClickableLabels::clicked, this, &ProductManager::onAddToCartClicked);

                //add the labels to the book layout
                bookLayout->addWidget(imageLabel);
                bookLayout->addWidget(nameLabel);
                bookLayout->addWidget(priceLabel);
                bookLayout->addWidget(addtoCart);

                //set alignment for the book layout
                bookLayout->setAlignment(Qt::AlignTop);

                //add the book layout to the main layout
                ui->recsLayout->addLayout(bookLayout);

                //increment the column index for the next book
                column++;
            } else {
                qDebug() << "Invalid image path for book: " << name;
            }
        }
    }
    ui->recsLayout->setAlignment(Qt::AlignHCenter);
}


void ProductManager::showPrevious() {
    int startIndex = 0;
    int endIndex = 0;

    if (secondPage) {
        secondPage = false;
        firstPage = true;
        nextButton->setVisible(true);
        prevButton->setVisible(true);

        clearLayout(ui->recsLayout);
        clearLayout(ui->allproductsLayout);
        displayedProducts.clear();

        ui->ourproductsLogo->move(67, 480);
        ui->recsLayout->parentWidget()->lower();
        ui->allproductsLayout->Down;
        makeFirstPage();
        return;
    }
    if (thirdPage) {

        thirdPage = false;
        secondPage = true;

        startIndex = 10;
        endIndex = 29;

        secondPageProducts.clear();

        qDebug() << "Start Index: " << startIndex << ", End Index: " << endIndex;

        //populate secondPageProducts with products from allProducts
        for (int i = startIndex; i <= endIndex && i < allProducts.size(); ++i) {
            secondPageProducts.push_back(allProducts.at(i));
        }

        qDebug() << "Number of products in secondPageProducts: " << secondPageProducts.size();

        //show the products based on the second page vector
        ui->allproductsLayout->Down;
        ui->recsLayout->parentWidget()->raise();
        showProductsBasedonPage(secondPageProducts);
        return;
    }
    if(fourthPage){
        fourthPage = false;
        thirdPage = true;

        startIndex = 30;
        endIndex = 49;

        thirdPageProducts.clear();

        qDebug() << "Start Index: " << startIndex << ", End Index: " << endIndex;

        //populate secondPageProducts with products from allProducts
        for (int i = startIndex; i <= endIndex && i < allProducts.size(); ++i) {
            thirdPageProducts.push_back(allProducts.at(i));
        }

        qDebug() << "Number of products in secondPageProducts: " << thirdPageProducts.size();

        //show the products based on the second page vector
        ui->allproductsLayout->Down;
        ui->recsLayout->parentWidget()->raise();
        showProductsBasedonPage(thirdPageProducts);
        return;
    }
}

void ProductManager::showProductsBasedonPage(vector<Products*> neededProducts){
    //clear existing layouts and widgets
    clearLayout(ui->recsLayout);
    clearLayout(ui->allproductsLayout);

    nextButton->setVisible(true);
    prevButton->setVisible(true);
    nextButton->raise();
    prevButton->raise();

    ui->ourproductsLogo->move(67, 150);
    ui->basedonyouLogo->setVisible(false);
    ui->basedonsearchLogo->setVisible(false);

    int recsLayoutHeight = ui->recsLayout->parentWidget()->height() + 40;

    //adjusting the size of the parent widget of recsLayout
    ui->recsLayout->parentWidget()->resize(widthFull-100, recsLayoutHeight);

    // Create a grid layout for displaying the remaining products
    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setAlignment(Qt::AlignTop);

    int maxIteminRow = 10;
    int iteminRow = 0;
    int row = 0;
    int col = 0;
    int productCount = 0;

    for(Products* product: neededProducts){
        if (productCount >= 20 || row >= 2) {
            break;
        }
        if(Books* book = dynamic_cast<Books*>(product)){
            QString name = book->getName();
            QPixmap imagePath = book->getImage();
            double price = book->getPrice();
            if (!imagePath.isNull()) {
                // Create widgets for the book
                QVBoxLayout* bookLayout = new QVBoxLayout();
                QLabel* imageLabel = new QLabel();
                imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                QLabel* nameLabel = new QLabel(name);
                nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                nameLabel->setMaximumWidth(imageLabel->width());
                nameLabel->setWordWrap(true);
                QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                priceLabel->setFont(QFont("Optima", 12));
                ClickableLabels* addtoCart = new ClickableLabels(this);
                QPixmap addPix(":/logos/assets/addtoCart.png");
                addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                connect(addtoCart, &ClickableLabels::clicked, [this, book , imagePath, name, price](){

                    if(book->getQuantity() > 0){
                        this->cart->AddItemToCart(imagePath,name, price, 1);
                    }else{
                        QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));

                    }
                });

                //connect(addtoCart, &ClickableLabels::clicked, this, &ProductManager::onAddToCartClicked);

                bookLayout->addWidget(imageLabel);
                bookLayout->addWidget(nameLabel);
                bookLayout->addWidget(priceLabel);
                bookLayout->addWidget(addtoCart);
                bookLayout->setAlignment(Qt::AlignTop);

                gridLayout->addLayout(bookLayout, row, col);

                iteminRow++;

                //check if we need to start a new row
                if (iteminRow >= maxIteminRow) {
                    row++;
                    col = 0;
                    iteminRow = 0;
                } else {
                    col++;
                }
                productCount++;
            }
        }else if(Accessories* accessory = dynamic_cast<Accessories*>(product)){
            QString name = accessory->getName();
            QPixmap imagePath = accessory->getImage();
            double price = accessory->getPrice();
            if (!imagePath.isNull()) {
                QVBoxLayout* accessoryLayout = new QVBoxLayout();
                QLabel* imageLabel = new QLabel();
                imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                QLabel* nameLabel = new QLabel(name);
                nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                nameLabel->setMaximumWidth(imageLabel->width());
                nameLabel->setWordWrap(true);
                QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                priceLabel->setFont(QFont("Optima", 12));
                ClickableLabels* addtoCart = new ClickableLabels(this);
                QPixmap addPix(":/logos/assets/addtoCart.png");
                addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                connect(addtoCart, &ClickableLabels::clicked, [this, accessory, imagePath, name, price](){
                    if(accessory->getQuantity() > 0){
                        this->cart->AddItemToCart(imagePath,name, price, 1);
                    }else{
                        QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));

                    }
                });

                //connect(addtoCart, &ClickableLabels::clicked, this, &ProductManager::onAddToCartClicked);

                accessoryLayout->addWidget(imageLabel);
                accessoryLayout->addWidget(nameLabel);
                accessoryLayout->addWidget(priceLabel);
                accessoryLayout->addWidget(addtoCart);
                accessoryLayout->setAlignment(Qt::AlignTop);

                gridLayout->addLayout(accessoryLayout, row, col);
                iteminRow++;

                if (iteminRow >= 8) {
                    row++;
                    col = 0;
                    iteminRow = 0;
                } else {
                    col++;
                }
                productCount++;
            }
        }else if(Techs* tech = dynamic_cast<Techs*>(product)){
            QString name = tech->getName();
            QPixmap imagePath = tech->getImage();
            double price = tech->getPrice();
            if (!imagePath.isNull()) {
                QVBoxLayout* techLayout = new QVBoxLayout();
                QLabel* imageLabel = new QLabel();
                imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                QLabel* nameLabel = new QLabel(name);
                nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                nameLabel->setMaximumWidth(imageLabel->width());
                nameLabel->setWordWrap(true);
                QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                priceLabel->setFont(QFont("Optima", 12));
                ClickableLabels* addtoCart = new ClickableLabels(this);
                QPixmap addPix(":/logos/assets/addtoCart.png");
                addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                connect(addtoCart, &ClickableLabels::clicked, [this, tech, imagePath, name, price](){
                    if(tech->getQuantity() > 0){
                        this->cart->AddItemToCart(imagePath,name, price, 1);
                    }else{
                        QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));

                    }
                });

                //connect(addtoCart, &ClickableLabels::clicked, this, &ProductManager::onAddToCartClicked);

                techLayout->addWidget(imageLabel);
                techLayout->addWidget(nameLabel);
                techLayout->addWidget(priceLabel);
                techLayout->addWidget(addtoCart);
                techLayout->setAlignment(Qt::AlignTop);

                gridLayout->addLayout(techLayout, row, col);
                iteminRow++;

                if (iteminRow >= 8) {
                    row++;
                    col = 0;
                    iteminRow = 0;
                } else {
                    col++;
                }
                productCount++;
            }
        }
    }
    ui->recsLayout->addLayout(gridLayout);


}


void ProductManager::makeSecondPage(){
    firstPage = false;
    secondPage = true;
    thirdPage = false;
    fourthPage = false;
    secondPageProducts.clear();
    ui->searchLineEdit->setVisible(true);
    clearLayout(ui->recsLayout);
    clearLayout(ui->allproductsLayout);
    ui->allproductsLayout->Down;
    ui->recsLayout->parentWidget()->raise();
    nextButton->raise();
    prevButton->raise();
    showRemainingProducts();
}

void ProductManager::makeThirdPage(){
    firstPage = false;
    secondPage = false;
    thirdPage = true;
    fourthPage = false;
    thirdPageProducts.clear();
    ui->searchLineEdit->setVisible(true);
    clearLayout(ui->recsLayout);
    clearLayout(ui->allproductsLayout);
    ui->allproductsLayout->Down;
    ui->recsLayout->parentWidget()->raise();
    nextButton->raise();
    prevButton->raise();
    showRemainingProducts();
}

void ProductManager::makeFourthPage(){
    qDebug() << "Entering makeFourthPage()";
    firstPage = false;
    secondPage = false;
    thirdPage = false;
    fourthPage = true;
    fourthPageProducts.clear();
    nextButton->setVisible(false);
    ui->searchLineEdit->setVisible(true);
    clearLayout(ui->recsLayout);
    clearLayout(ui->allproductsLayout);

    qDebug() << "Cleared layouts for fourth page";

    showRemainingProducts();

    qDebug() << "Executed showRemainingProducts() for fourth page";
    qDebug() << "Number of products in fourthPageProducts:" << fourthPageProducts.size();
}

QPixmap ProductManager::resizeImage(const QPixmap& originalPixmap, int maxWidth, int maxHeight) {
    if (originalPixmap.isNull()) {
        qDebug() << "Invalid image provided for resizing";
        return QPixmap(); // Return a null pixmap if the original is invalid
    }

    // Scale the pixmap to fit within the specified maximum width and height while maintaining aspect ratio
    return originalPixmap.scaled(maxWidth, maxHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}
void ProductManager::showRemainingProducts() {
    //clear existing layouts and widgets
    clearLayout(ui->recsLayout);
    clearLayout(ui->allproductsLayout);

    ui->ourproductsLogo->move(67, 150);
    ui->basedonyouLogo->setVisible(false);
    ui->basedonsearchLogo->setVisible(false);

    ui->allproductsLayout->parentWidget()->lower();

    int recsLayoutHeight = ui->recsLayout->parentWidget()->height() + 40;

    //adjusting the size of the parent widget of recsLayout
    ui->recsLayout->parentWidget()->resize(widthFull-100, recsLayoutHeight);

    // Create a grid layout for displaying the remaining products
    QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setAlignment(Qt::AlignTop);

    int maxIteminRow = 10;
    int iteminRow = 0;
    int row = 0;
    int col = 0;
    int productCount = 0; //counter for the number of displayed products
    int total = 0;

    //add remaining products to the grid layout
    for (Products* product : *bookProducts) {
        if (productCount >= 20 || row >= 2) {
            break;
        }

        Books* book = dynamic_cast<Books*>(product);
        if (book && !isProductDisplayed(book)) {
            QString name = book->getName();
            QPixmap imagePath = book->getImage();
            double price = book->getPrice();
            if (!imagePath.isNull()) {
                // Create widgets for the book
                QVBoxLayout* bookLayout = new QVBoxLayout();
                QLabel* imageLabel = new QLabel();
                imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                imageLabel->setScaledContents(true);
                QLabel* nameLabel = new QLabel(name);
                nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                nameLabel->setMaximumWidth(imageLabel->width());
                nameLabel->setWordWrap(true);
                QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                priceLabel->setFont(QFont("Optima", 12));
                ClickableLabels* addtoCart = new ClickableLabels(this);
                QPixmap addPix(":/logos/assets/addtoCart.png");
                addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                connect(addtoCart, &ClickableLabels::clicked, [this, book, imagePath, name, price](){

                    if(book->getQuantity() > 0){
                        this->cart->AddItemToCart(imagePath,name, price, 1);
                    }else{
                        QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));

                    }
                });

                //connect(addtoCart, &ClickableLabels::clicked, this, &ProductManager::onAddToCartClicked);

                bookLayout->addWidget(imageLabel);
                bookLayout->addWidget(nameLabel);
                bookLayout->addWidget(priceLabel);
                bookLayout->addWidget(addtoCart);
                bookLayout->setAlignment(Qt::AlignTop);

                gridLayout->addLayout(bookLayout, row, col);

                iteminRow++;

                //check if we need to start a new row
                if (iteminRow >= maxIteminRow) {
                    row++;
                    col = 0;
                    iteminRow = 0;
                } else {
                    col++;
                }
                productCount++;
                total++;
                displayedProducts.push_back(book);
                beforeCallProducts.push_back(book);
                if(fourthPage)
                    fourthPageProducts.push_back(book);
                if(thirdPage)
                    thirdPageProducts.push_back(book);
                if(secondPage)
                    secondPageProducts.push_back(book);
            } else {
                qDebug() << "Invalid image path for book: " << name;
            }
        }
    }

    for (Products* product : *accessoryProducts){
        //check maximum number of products for the page is filled
        if (productCount >= 16 || row >= 2) {
            break;
        }
        Accessories* accessory = dynamic_cast<Accessories*>(product);
        //check if the product is not displayed
        if (accessory && !isProductDisplayed(accessory)){
            QString name = accessory->getName();
            QPixmap imagePath = accessory->getImage();
            double price = accessory->getPrice();
            if (!imagePath.isNull()) {
                QVBoxLayout* accessoryLayout = new QVBoxLayout();
                QLabel* imageLabel = new QLabel();
                imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                imageLabel->setScaledContents(true);
                QLabel* nameLabel = new QLabel(name);
                nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                nameLabel->setMaximumWidth(imageLabel->width());
                nameLabel->setWordWrap(true);
                QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                priceLabel->setFont(QFont("Optima", 12));
                ClickableLabels* addtoCart = new ClickableLabels(this);
                QPixmap addPix(":/logos/assets/addtoCart.png");
                addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                connect(addtoCart, &ClickableLabels::clicked, [this, accessory, imagePath, name, price](){

                    if(accessory->getQuantity() > 0){
                        this->cart->AddItemToCart(imagePath,name, price, 1);
                    }else{
                        QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));

                    }
                });
                //connect(addtoCart, &ClickableLabels::clicked, this, &ProductManager::onAddToCartClicked);

                accessoryLayout->addWidget(imageLabel);
                accessoryLayout->addWidget(nameLabel);
                accessoryLayout->addWidget(priceLabel);
                accessoryLayout->addWidget(addtoCart);
                accessoryLayout->setAlignment(Qt::AlignTop);

                gridLayout->addLayout(accessoryLayout, row, col);
                iteminRow++;

                if (iteminRow >= 8) {
                    row++;
                    col = 0;
                    iteminRow = 0;
                } else {
                    col++;
                }
                productCount++;
                total++;
                displayedProducts.push_back(accessory);
                beforeCallProducts.push_back(accessory);
                if(fourthPage)
                    fourthPageProducts.push_back(accessory);
                if(thirdPage)
                    thirdPageProducts.push_back(accessory);
                if(secondPage)
                    secondPageProducts.push_back(accessory);
            } else {
                qDebug() << "Invalid image path for book: " << name;
            }
        }
    }

    for (Products* product : *techyProducts){
        //check maximum number of products for the page is filled
        if (productCount >= 16 || row >= 2) {
            break;
        }
        Techs* tech = dynamic_cast<Techs*>(product);
        //check if the product is not displayed
        if (tech && !isProductDisplayed(tech)){
            QString name = tech->getName();
            QPixmap imagePath = tech->getImage();
            double price = tech->getPrice();
            if (!imagePath.isNull()) {
                QVBoxLayout* techLayout = new QVBoxLayout();
                QLabel* imageLabel = new QLabel();
                imageLabel->setPixmap(imagePath.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                imageLabel->setScaledContents(true);
                QLabel* nameLabel = new QLabel(name);
                nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                nameLabel->setMaximumWidth(imageLabel->width());
                nameLabel->setWordWrap(true);
                QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                priceLabel->setFont(QFont("Optima", 12));
                ClickableLabels* addtoCart = new ClickableLabels(this);
                QPixmap addPix(":/logos/assets/addtoCart.png");
                addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                connect(addtoCart, &ClickableLabels::clicked, [this, tech, imagePath, name, price](){

                    if(tech->getQuantity() > 0){
                        this->cart->AddItemToCart(imagePath,name, price, 1);
                    }else{
                        QMessageBox::warning(this, "Item out of stock", QString("%1 out of stock").arg(name));

                    }
                });

                //connect(addtoCart, &ClickableLabels::clicked, this, &ProductManager::onAddToCartClicked);

                techLayout->addWidget(imageLabel);
                techLayout->addWidget(nameLabel);
                techLayout->addWidget(priceLabel);
                techLayout->addWidget(addtoCart);
                techLayout->setAlignment(Qt::AlignTop);

                gridLayout->addLayout(techLayout, row, col);
                iteminRow++;

                if (iteminRow >= 8) {
                    row++;
                    col = 0;
                    iteminRow = 0;
                } else {
                    col++;
                }
                productCount++;
                total++;
                displayedProducts.push_back(tech);
                beforeCallProducts.push_back(tech);
                if(fourthPage)
                    fourthPageProducts.push_back(tech);
                if(thirdPage)
                    thirdPageProducts.push_back(tech);
                if(secondPage)
                    secondPageProducts.push_back(tech);
            } else {
                qDebug() << "Invalid image path for book: " << name;
            }
        }
    }

    if(total < 8)
        nextButton->setVisible(false);

    ui->recsLayout->addLayout(gridLayout);
    ui->allproductsLayout->addLayout(gridLayout);
}


bool ProductManager::isProductDisplayed(Products* product) {
    //dynamic cast to Books
    Books* book = dynamic_cast<Books*>(product);
    if (book) {
        //book is displayed?
        for (Products* displayedProduct : displayedProducts) {
            Books* displayedBook = dynamic_cast<Books*>(displayedProduct);
            if (displayedBook && book == displayedBook) {
                return true;
            }
        }
    } else {
        //dynamic cast to Accessories
        Accessories* accessory = dynamic_cast<Accessories*>(product);
        if (accessory) {
            //accessory is displayed?
            for (Products* displayedProduct : displayedProducts) {
                Accessories* displayedAccessory = dynamic_cast<Accessories*>(displayedProduct);
                if (displayedAccessory && accessory == displayedAccessory) {
                    return true;
                }
            }
        } else {
            //dynamic cast to Techs
            Techs* tech = dynamic_cast<Techs*>(product);
            if (tech) {
                //tech is displayed?
                for (Products* displayedProduct : displayedProducts) {
                    Techs* displayedTech = dynamic_cast<Techs*>(displayedProduct);
                    if (displayedTech && tech == displayedTech) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


void ProductManager::onRegisterAdminClicked()
{
    Admin* ad = dynamic_cast<Admin*> (user);

    RegisterWindow *reg = new RegisterWindow(nullptr, allusers, AllUsers::admin, ad);
    reg->resize(widthFull, heightFull);
    reg -> setWindowTitle("Register new Admin");
    reg->show();
    hide();
}
void ProductManager::onRegisterSellerClicked(){
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();

    Admin* ad = dynamic_cast<Admin*> (user);

    RegisterWindow *reg = new RegisterWindow(nullptr, allusers, AllUsers::seller, ad);
    reg->resize(screenGeometry.width(), screenGeometry.height());
    reg -> setWindowTitle("Register new Seller");
    reg->show();
    hide();
}

QWidget* ProductManager::createProductWidget(Products* product) {
    // Create a widget to display product information
    QWidget* productWidget = new QWidget;

    // Create labels for product name and price
    QLabel* nameLabel = new QLabel(product->getName());
    nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
    nameLabel->setWordWrap(true);

    QLabel* priceLabel = new QLabel(QString::number(product->getPrice()) + " EGP");
    priceLabel->setFont(QFont("Optima", 12));
    // Create a QLabel to display the product image
    QLabel* imageLabel = new QLabel();
    QPixmap imagePixmap = product->getImage();
    imageLabel->setPixmap(imagePixmap); // Set the pixmap to the label

    // Scale the pixmap to fit the label while preserving aspect ratio
    imageLabel->setScaledContents(true);


    // Define the maximum width and height for the image label
    int maxImageWidth = 200; // Adjust as needed
    int maxImageHeight = 200; // Adjust as needed

    // Scale the image to fit within the maximum size while preserving aspect ratio
    QPixmap scaledImagePixmap = imagePixmap.scaledToWidth(maxImageWidth, Qt::SmoothTransformation);
    if (scaledImagePixmap.height() > maxImageHeight) {
        scaledImagePixmap = imagePixmap.scaledToHeight(maxImageHeight, Qt::SmoothTransformation);
    }


    // Set the scaled pixmap to the image label
    imageLabel->setPixmap(scaledImagePixmap);

    // Assuming you have a QLabel for "Add to Cart" button
    QLabel* addToCartLabel = new QLabel();
    QPixmap addToCartPixmap(":/logos/assets/addtoCart.png");
    addToCartLabel->setPixmap(addToCartPixmap.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Set up a layout for the product widget
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(imageLabel);
    layout->addWidget(nameLabel);
    layout->addWidget(priceLabel);
    layout->addWidget(addToCartLabel);

    // Set alignment and spacing for the layout
    layout->setAlignment(Qt::AlignTop);
    layout->setSpacing(10);

    // Set up the product widget
    productWidget->setLayout(layout);

    return productWidget;


}

void ProductManager::sortPage(QLayout* layout, const QString &arg1, vector<Products*> &products, int startIndex, int maxBooksToShow) {
    qDebug() << "Processing page...";

    // Clear the layout
    clearLayout(layout);

    // Raise navigation buttons above the layout
    nextButton->raise();
    prevButton->raise();

    // Sort the products based on the selected filter criteria
    if (arg1 == "Lowest to Highest Price") {
        sort(products.begin(), products.end(), [](Products* a, Products* b) {
            return a->getPrice() < b->getPrice();
        });
    } else if (arg1 == "Highest to Lowest Price") {
        sort(products.begin(), products.end(), [](Products* a, Products* b) {
            return a->getPrice() > b->getPrice();
        });
    } else if (arg1 == "A-Z") {
        sort(products.begin(), products.end(), [](Products* a, Products* b) {
            return a->getName().toLower() < b->getName().toLower();
        });
    } else if (arg1 == "Z-A") {
        sort(products.begin(), products.end(), [](Products* a, Products* b) {
            return a->getName().toLower() > b->getName().toLower();
        });
    }

    int booksShown = 0;

    // Iterate over the products and add them to the layout
    for (int i = startIndex; i < products.size(); ++i) {
        // Break if the maximum count of books to show is reached
        if (booksShown >= maxBooksToShow) {
            break;
        }

        // Create a widget for the product
        QWidget* productWidget = createProductWidget(products[i]);
        layout->addWidget(productWidget);

        qDebug() << "Added product to layout";

        // Increment the counter for books shown
        booksShown++;

        // Update the layout
        layout->parentWidget()->update();
        // Raise the layout above other widgets if it's allproductsLayout
        if (layout == ui->allproductsLayout) {
            layout->parentWidget()->raise();
            layout->parentWidget()->update();
            nextButton->raise();
            prevButton->raise();
        }
    }

    qDebug() << "Layout updated.";
}
void ProductManager::sortProducts(vector<Products*>& products, const QString& arg1) {
    if (arg1 == "Lowest to Highest Price") {
        std::sort(products.begin(), products.end(), [](Products* a, Products* b) {
            return a->getPrice() < b->getPrice();
        });
    } else if (arg1 == "Highest to Lowest Price") {
        std::sort(products.begin(), products.end(), [](Products* a, Products* b) {
            return a->getPrice() > b->getPrice();
        });
    } else if (arg1 == "A-Z") {
        std::sort(products.begin(), products.end(), [](Products* a, Products* b) {
            return a->getName().toLower() < b->getName().toLower();
        });
    } else if (arg1 == "Z-A") {
        std::sort(products.begin(), products.end(), [](Products* a, Products* b) {
            return a->getName().toLower() > b->getName().toLower();
        });
    }
}
void ProductManager::updateLayout(QLayout* layout) {
    layout->parentWidget()->update();
    if (layout == ui->allproductsLayout) {
        layout->parentWidget()->raise();
        layout->parentWidget()->update();
        nextButton->raise();
        prevButton->raise();
    }
}
void ProductManager::on_filterBox_currentTextChanged(const QString &arg1) {
    filteractivated = true;
    qDebug() << "filteractivated true";

    if (firstPage) {
        clearLayout(ui->allproductsLayout);
        sortProducts(firstPageProducts, arg1);
        int maxBooksToShow = 9;
        int booksShown = 0;
        for (Products* product : firstPageProducts) {
            if (booksShown >= maxBooksToShow) {
                break;
            }
            QWidget* productWidget = createProductWidget(product);
            ui->allproductsLayout->addWidget(productWidget);
            booksShown++;
        }
        ui->allproductsLayout->update();
    }

    if (secondPage) {
        qDebug() << "Processing second page...";
        clearLayout(ui->recsLayout);
        clearLayout(ui->allproductsLayout);
        nextButton->raise();
        prevButton->raise();
        sortProducts(secondPageProducts, arg1);
        int maxBooksToShow = 9;
        int booksShownInRecs = 0;
        int booksShownInAllProducts = 0;
        for (int i = 0; i < secondPageProducts.size(); ++i) {
            if (booksShownInRecs >= maxBooksToShow && booksShownInAllProducts >= maxBooksToShow) {
                break;
            }
            if (booksShownInRecs < maxBooksToShow) {
                QWidget* productWidgetForRecs = createProductWidget(secondPageProducts[i]);
                ui->recsLayout->addWidget(productWidgetForRecs);
                qDebug() << "Added product to recsLayout";
                booksShownInRecs++;
            } else {
                QWidget* productWidgetForAllProducts = createProductWidget(secondPageProducts[i]);
                ui->allproductsLayout->addWidget(productWidgetForAllProducts);
                qDebug() << "Added product to allproductsLayout";
                booksShownInAllProducts++;
            }
        }
        updateLayout(ui->recsLayout);
        updateLayout(ui->allproductsLayout);
        qDebug() << "Layouts updated.";
    }

    if (thirdPage) {
        qDebug() << "Processing second page...";
        clearLayout(ui->recsLayout);
        clearLayout(ui->allproductsLayout);
        nextButton->raise();
        prevButton->raise();
        sortProducts(thirdPageProducts, arg1);
        int maxBooksToShow = 9;
        int booksShownInRecs = 0;
        int booksShownInAllProducts = 0;
        for (int i = 0; i < thirdPageProducts.size(); ++i) {
            if (booksShownInRecs >= maxBooksToShow && booksShownInAllProducts >= maxBooksToShow) {
                break;
            }
            if (booksShownInRecs < maxBooksToShow) {
                QWidget* productWidgetForRecs = createProductWidget(thirdPageProducts[i]);
                ui->recsLayout->addWidget(productWidgetForRecs);
                qDebug() << "Added product to recsLayout";
                booksShownInRecs++;
            } else {
                QWidget* productWidgetForAllProducts = createProductWidget(thirdPageProducts[i]);
                ui->allproductsLayout->addWidget(productWidgetForAllProducts);
                qDebug() << "Added product to allproductsLayout";
                booksShownInAllProducts++;
            }
        }
        updateLayout(ui->recsLayout);
        updateLayout(ui->allproductsLayout);
        qDebug() << "Layouts updated.";
    }
    if (fourthPage) {
        // Clear the layouts
        clearLayout(ui->recsLayout);
        clearLayout(ui->allproductsLayout);

        // Raise navigation buttons above the layout
        nextButton->raise();
        prevButton->raise();

        // Sort the products based on the selected filter criteria
        if (arg1 == "Lowest to Highest Price") {
            sort(fourthPageProducts.begin(), fourthPageProducts.end(), [](Products* a, Products* b) {
                return a->getPrice() < b->getPrice();
            });
        } else if (arg1 == "Highest to Lowest Price") {
            sort(fourthPageProducts.begin(), fourthPageProducts.end(), [](Products* a, Products* b) {
                return a->getPrice() > b->getPrice();
            });
        } else if (arg1 == "A-Z") {
            sort(fourthPageProducts.begin(), fourthPageProducts.end(), [](Products* a, Products* b) {
                return a->getName().toLower() < b->getName().toLower();
            });
        } else if (arg1 == "Z-A") {
            sort(fourthPageProducts.begin(), fourthPageProducts.end(), [](Products* a, Products* b) {
                return a->getName().toLower() > b->getName().toLower();
            });
        }

        int maxBooksToShow = 9;
        int booksShownInRecs = 0;
        int booksShownInAllProducts = 0;

        // Iterate over the fourth page products
        for (int i = 0; i < fourthPageProducts.size(); ++i) {
            // Break if both layouts have reached their maximum count
            if (booksShownInRecs >= maxBooksToShow && booksShownInAllProducts >= maxBooksToShow) {
                break;
            }

            // Create a widget for the product in recsLayout
            if (booksShownInRecs < maxBooksToShow) {
                QWidget* productWidgetForRecs = createProductWidget(fourthPageProducts[i]);
                ui->recsLayout->addWidget(productWidgetForRecs);
                qDebug() << "Added product to recsLayout";
                booksShownInRecs++;
            } else {
                // Create a widget for the product in allproductsLayout
                QWidget* productWidgetForAllProducts = createProductWidget(fourthPageProducts[i]);
                ui->allproductsLayout->addWidget(productWidgetForAllProducts);
                qDebug() << "Added product to allproductsLayout";
                booksShownInAllProducts++;
            }
        }

        // Update the layouts
        ui->recsLayout->parentWidget()->update();
        ui->allproductsLayout->parentWidget()->raise();
        ui->allproductsLayout->parentWidget()->update();
        nextButton->raise();
        prevButton->raise();

        qDebug() << "Layouts updated.";
    }

}
void ProductManager::on_addProductButton_clicked()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Add Product");

    //create layout for the dialog
    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    //add radio buttons for product type selection
    QGroupBox *groupBox = new QGroupBox("Product Type");
    QVBoxLayout *radioLayout = new QVBoxLayout;
    QRadioButton *bookRadioButton = new QRadioButton("Book");
    QRadioButton *accessoryRadioButton = new QRadioButton("Accessory");
    QRadioButton *techRadioButton = new QRadioButton("Tech");

    radioLayout->addWidget(bookRadioButton);
    radioLayout->addWidget(accessoryRadioButton);
    radioLayout->addWidget(techRadioButton);
    groupBox->setLayout(radioLayout);
    layout->addWidget(groupBox);

    //add input fields for common product details
    QLineEdit *nameLineEdit = new QLineEdit(&dialog);
    nameLineEdit->setPlaceholderText("Name");
    layout->addWidget(nameLineEdit);

    QDoubleSpinBox *priceSpinBox = new QDoubleSpinBox(&dialog);
    priceSpinBox->setSuffix(" EGP");
    priceSpinBox->setMinimum(1);
    priceSpinBox->setMaximum(1000);
    priceSpinBox->setSingleStep(1);
    priceSpinBox->setAccelerated(true);
    layout->addWidget(priceSpinBox);

    QSpinBox *quantitySpinBox = new QSpinBox(&dialog);
    quantitySpinBox->setMinimum(1);
    quantitySpinBox->setMaximum(1000);
    layout->addWidget(quantitySpinBox);

    QLineEdit *imagePathLineEdit = new QLineEdit(&dialog);
    imagePathLineEdit->setPlaceholderText("Image Path");
    layout->addWidget(imagePathLineEdit);

    //additional fields for all products
    QLabel *isbnLabel = new QLabel("ISBN", &dialog);
    QLineEdit *isbnLineEdit = new QLineEdit(&dialog);
    layout->addWidget(isbnLabel);
    layout->addWidget(isbnLineEdit);
    isbnLabel->setVisible(false);
    isbnLineEdit->setVisible(false);

    QCheckBox *availabilityCheckBox = new QCheckBox("Availability", &dialog);
    layout->addWidget(availabilityCheckBox);

    //additional fields for books
    QLabel *genreLabel = new QLabel("Genre", &dialog);
    QComboBox *genreCombo = new QComboBox(&dialog);
    genreCombo ->addItem("Classics");
    genreCombo ->addItem("Philosophy");
    genreCombo ->addItem("Arabic-Literature");
    genreCombo ->addItem("Poetry");
    genreCombo ->addItem("Palestine");
    genreCombo ->addItem("Arab-American");
    genreCombo ->addItem("Comic-Books");

    layout->addWidget(genreLabel);
    layout->addWidget(genreCombo);
    genreLabel->setVisible(false);
    genreCombo->setVisible(false);

    QLabel *authorLabel = new QLabel("Author", &dialog);
    QLineEdit *authorLineEdit = new QLineEdit(&dialog);
    layout->addWidget(authorLabel);
    layout->addWidget(authorLineEdit);
    authorLabel->setVisible(false);
    authorLineEdit->setVisible(false);

    //additional fields for accessories
    QLabel *typeLabel = new QLabel("Type", &dialog);
    QLineEdit *typeLineEdit = new QLineEdit(&dialog);
    layout->addWidget(typeLabel);
    layout->addWidget(typeLineEdit);
    typeLabel->setVisible(false);
    typeLineEdit->setVisible(false);

    QLabel *sizeLabel = new QLabel("Size", &dialog);
    QLineEdit *sizeLineEdit = new QLineEdit(&dialog);
    layout->addWidget(sizeLabel);
    layout->addWidget(sizeLineEdit);
    sizeLabel->setVisible(false);
    sizeLineEdit->setVisible(false);

    //additional fields for tech
    QLabel *warrantyLabel = new QLabel("Warranty", &dialog);
    QSpinBox *warrantySpinBox = new QSpinBox(&dialog);
    warrantySpinBox->setMinimum(0);
    warrantySpinBox->setMaximum(10); // Adjust the range as needed
    layout->addWidget(warrantyLabel);
    layout->addWidget(warrantySpinBox);
    warrantyLabel->setVisible(false);
    warrantySpinBox->setVisible(false);

    //connect signals and slots for radio buttons
    connect(bookRadioButton, &QRadioButton::toggled, [&]() {
        isbnLabel->setVisible(true);
        isbnLineEdit->setVisible(true);
        genreLabel->setVisible(true);
        genreCombo->setVisible(true);
        authorLabel->setVisible(true);
        authorLineEdit->setVisible(true);

        typeLabel->setVisible(false);
        typeLineEdit->setVisible(false);
        sizeLabel->setVisible(false);
        sizeLineEdit->setVisible(false);
        warrantyLabel->setVisible(false);
        warrantySpinBox->setVisible(false);
    });

    connect(accessoryRadioButton, &QRadioButton::toggled, [&]() {
        typeLabel->setVisible(true);
        typeLineEdit->setVisible(true);
        sizeLabel->setVisible(true);
        sizeLineEdit->setVisible(true);

        isbnLabel->setVisible(false);
        isbnLineEdit->setVisible(false);
        genreLabel->setVisible(false);
        genreCombo->setVisible(false);
        authorLabel->setVisible(false);
        authorLineEdit->setVisible(false);
        warrantyLabel->setVisible(false);
        warrantySpinBox->setVisible(false);
    });

    connect(techRadioButton, &QRadioButton::toggled, [&]() {
        warrantyLabel->setVisible(true);
        warrantySpinBox->setVisible(true);

        isbnLabel->setVisible(false);
        isbnLineEdit->setVisible(false);
        genreLabel->setVisible(false);
        genreCombo->setVisible(false);
        authorLabel->setVisible(false);
        authorLineEdit->setVisible(false);
        typeLabel->setVisible(false);
        typeLineEdit->setVisible(false);
        sizeLabel->setVisible(false);
        sizeLineEdit->setVisible(false);
    });

    //add buttons for adding and canceling
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *addButton = new QPushButton("Add", &dialog);
    QPushButton *cancelButton = new QPushButton("Cancel", &dialog);
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);

    //connect signals and slots
    connect(addButton, &QPushButton::clicked, [&]() {
        QString name = nameLineEdit->text();
        double price = priceSpinBox->value();
        int quantity = quantitySpinBox->value();
        QString imagePath = imagePathLineEdit->text();
        QString isbn = isbnLineEdit->text();
        bool availability = availabilityCheckBox->isChecked();
        QString seller = user->getUsername();

        //if image path is empty, use the placeholder image path
        if (imagePath.isEmpty()) {
            imagePath = ":/logos/assets/imagePlaceHolder.png";
        }

        //validate input
        if (name.isEmpty() || price <= 0 || quantity <= 0 || (bookRadioButton->isChecked() && isbn.isEmpty())) {
            QMessageBox::warning(&dialog, "Error", "Please fill in all required fields.");
            return;
        }

        //additional fields based on selected product type
        QString genre, author, type, size;
        int warranty = 0;

        if (bookRadioButton->isChecked()) {
            genre = genreCombo->currentText();
            author = authorLineEdit->text();
            Books* newBook = new Books(name, price, quantity, availability, imagePath, seller, genre, author, isbn);
            sellerNewProducts.push_back(newBook);
            allProducts.push_back(newBook);
            bookProducts->push_back(newBook);
        } else if (accessoryRadioButton->isChecked()) {
            type = typeLineEdit->text();
            size = sizeLineEdit->text();
            Accessories* newAccessory = new Accessories(name, price, quantity, availability, imagePath, seller, type, size);
            sellerNewProducts.push_back(newAccessory);
            allProducts.push_back(newAccessory);
            accessoryProducts->push_back(newAccessory);
        } else if (techRadioButton->isChecked()) {
            warranty = warrantySpinBox->value();
            Techs* newTech = new Techs(name, price, quantity, availability, QPixmap(imagePath), seller, warranty);
            sellerNewProducts.push_back(newTech);
            allProducts.push_back(newTech);
            techyProducts->push_back(newTech);
        }
        loadNewProduct();
        addedNewProduct = true;
        createSellerView();
        //close the dialog
        dialog.close();
    });

    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::close);

    //set dialog size and show
    dialog.setMinimumSize(400, 300);
    dialog.exec();
}

void ProductManager::loadNewProduct()
{
    qDebug()<< "entering load products";
    //open the file for writing
    QFile file(cached(":/UsersInfo/sellerEnteredProducts.txt"));
    if (file.setPermissions(QFile::WriteOwner))
        qDebug() << "Permissions updated successfully for file:";
    else
        qDebug() << "Error updating permissions for file:" ;

    //create a QTextStream to write to the file
    QTextStream out(&file);

    //iterate over the sellerNewProducts vector and write each product's data to the file
    for (Products* product : sellerNewProducts) {
        if (Books* book = dynamic_cast<Books*>(product)) {
            out << "book\", \"" <<book->getName() << "\", \"" << book->getPrice() << "\", \"" << book->getQuantity() << "\", \"" << book->getImagePath() << "\", \"" << book->getSeller() << "\", \""
                << book->getISBN() << "\", \"" << book->getGenre() << "\", \"" << book->getAuthor() << "\n";
        } else if (Accessories* accessory = dynamic_cast<Accessories*>(product)) {
            out << "acc\", \""<< accessory->getName() << "\", \"" << accessory->getPrice() << "\", \"" << accessory->getQuantity() << "\", \"" << accessory->getImagePath() << "\", \""
                << accessory->getSeller() << "\", \"" << accessory->getType() << "\", \"" << accessory->getSize() << "\n";
        } else if (Techs* tech = dynamic_cast<Techs*>(product)) {
            out << "techs\", \""<<tech->getName() << "\", \"" << tech->getPrice() << "\", \"" << tech->getQuantity() << "\", \"" << tech->getImagePath() << "\", \""
                << tech->getSeller() << "\", \"" << tech->getWarranty() << "\n";
        }
    }

    //close the file
    file.close();
}



