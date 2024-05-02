#include "productmanager.h"
#include "ui_productmanager.h"
#include "clickablelabels.h"
#include "customer.h"
#include "shoppingcart.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"

#include <QScreen>
#include <QVector>
#include <QString>
#include <QVBoxLayout>


ProductManager::ProductManager(QWidget *parent, User* loggedUser)
    : QWidget(parent)
    , ui(new Ui::ProductManager)
    , bookProducts(new QVector<Books*>())
    , accessoryProducts(new QVector<Accessories*>())
    , techyProducts(new QVector<Techs*>())
    , user(loggedUser)
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

    makeFirstPage();
}

ProductManager::~ProductManager()
{
    delete ui;
    //delete vectors and their elements
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


/*void ProductManager::setUser(User* loggedUser){
    user = loggedUser;
    if (user)
        qDebug() << "User transferred successfully";
}*/


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
        { "The Days", "25", "5", "true", ":/{/assets/days.jpeg" , "Arabic Literature" , "Taha Hussein" , "9781617971310"},
        { "Doaa Al-Karawan", "20", "5", "true", ":/{/assets/karawan.jpeg" , "Arabic Literature" , "Taha Hussein" , "9789771497011"},
        { "1984", "19", "5", "true", ":/{/assets/1984.jpeg" , "Classics" , "George Orwell" , "9780155658110"},
        { "Animal Farm", "18.5", "5", "true", ":/{/assets/animal farm.jpeg" , "Classics" , "George Orwell" , "9788129116123"},
        { "The Da Vinci Code", "17", "5", "true", ":/{/assets/davinci code.jpeg" , "Classics" , "Dan Brown" , "9780307277671"},
        { "Angels and Demons", "16.5", "5", "true", ":/{/assets/davinci code.jpeg" , "Classics" , "Dan Brown" , "9780743486224"},
        { "Mrs. Dalloway", "23", "5", "true", ":/{/assets/room of ones.jpeg" , "Classics" , "Virginia Woolf" , "9780199536009"},
        { "A Room of One’s Own", "24", "5", "true", ":/{/assets/dalloway.jpeg" , "Classics" , "Virginia Woolf" , "9780199536009"},
        { "Wuthering Heights", "26", "5", "true", ":/{/assets/wutheruing heights.jpeg" , "Classics" , "Emily Bronte" , "9780175565757"},
        { "Jane Eyre", "27", "5", "true", ":/{/assets/jane eyre.jpeg" , "Classics" , "Charlotte Bronte" , "9780785294788"},
        { "Villette", "24", "5", "true", ":/{/assets/villette.jpeg" , "Classics" , "Charlotte Bronte" , "9781853260193"},
        { "The Great Gatsby", "27", "5", "true", ":/{/assets/gatsby.jpeg" , "Classics" , "F. Scott Fitzgerald" , "9780393042375"},
        { "Tender is The Night", "34", "5", "true", ":/{/assets/tender is.jpeg" , "Classics" , "F. Scott Fitzgerald" , "9780684151519"},
        { "The Stranger", "16", "5", "true", ":/{/assets/stranger.png" , "Philosophy" , "Albert Camus" , "9780679720201"},
        { "The Plague", "17", "5", "true", ":/{/assets/plague.jpeg" , "Philosophy" , "Albert Camus" , "9780307827807"},
        { "The Old Man and The Sea", "30", "5", "true", ":/{/assets/old man.jpeg" , "Classics" , "Ernest Hemingway" , "9787201046440"},
        { "For whom the Bell Tolls", "31", "5", "true", ":/{/assets/the bell tolls.jpeg" , "Classics" , "Ernest Hemingway" , "9780307273789"},
        { "The Three Musketeers", "36", "5", "true", ":/{/assets/musketeers.jpeg" , "Classics" , "Leo Tolstoy" , "9783954183531"},
        { "The Count of Monte Cristo", "37", "5", "true", ":/{/assets/monte cristo.jpeg" , "Classics" , "Alexander Dumas" , "9780199219650"},
        { "The Prophet", "38", "5", "true", ":/{/assets/prophet.jpeg" , "Poetry" , "Khalil Gibran" , "9783530268003"},
        { "Broken Wings", "32", "5", "true", ":/{/assets/broken wings.jpeg" , "Arabic Literature" , "Khalil Gibran" , "9788177697025"},
        { "Granada", "40", "5", "true", ":/{/assets/granada.jpeg" , "Classics" , "Leo Tolstoy" , "9780393042375"},
        { "Al Tantouriah", "42", "5", "true", ":/{/assets/tantouriah.jpeg" , "Palestine" , "Radwa Ashour" , "9789770928295"},
        { "Fi Al-Quds", "26", "5", "true", ":/{/assets/fi alquds.jpeg" , "Palestine" , "Tamim Al-Barghouthi" , ""},
        { "Ya Masr Hanet", "20", "5", "true", ":/{/assets/ya masr hanet.jpeg" , "Poetry" , "Tamim Al-Barghouthi" , ""},
        { "I saw Ramallah", "45", "5", "true", ":/{/assets/i saw ramallah.jpeg" , "Palestine" , "Mourid Al-Barghouthi" , "9789774247552"},
        { "I Was Born There, I Was Born Here", "40", "5", "true", ":/{/assets/i was born.jpeg" , "Palestine" , "Mourid Al-Barghouthi" , "9781408829097"},
        { "Returning To Haifa", "39", "5", "true", ":/{/assets/haifa.jpeg" , "Palestine" , "Ghassan Kanafani" , "9780571347827"},
        { "Men in The Sun", "37", "5", "true", ":/{/assets/men in the sun.jpeg" , "Palestine" , "Ghassan Kanafani" , "9780894108570"},
        { "Beirut Nightmares", "29", "5", "true", ":/{/assets/beirut nightmares.jpeg" , "Arabic Literature" , "Ghada Al-Samman" , "9780704380653"},
        { "No Sea in Beirut", "28", "5", "true", ":/{/assets/no sea in beirut.jpg" , "Arabic Literature" , "Ghada Al-Samman" , ""},
        { "The Hundred Years’ War on Palestine", "45", "5", "true", ":/{/assets/the hundred years war on palestine.jpeg" , "Palestine" , "Rashid Khalidi" , "9781627798549"},
        { "The Iron Cage", "43", "5", "true", ":/Books/assets/iron cage.jpeg" , "Palestine" , "Rashid Khalidi" , "9780807003084"},
         { "Huda F Are You?", "20", "5", "true", ":/{/assets/huda f.jpeg" , "Comic {" , "Huda Fahmy" , "9780593324318"},
         { "Yes, I’m Hot in This 23", "23", "5", "true", ":/{/assets/hot in this.jpeg" , "Comic {" , "Huda Fahmy" , "9781507209349"},
         { "The Kite Runner", "42", "5", "true", ":/{/assets/kite runner.jpeg" , "Arab-American" , "Khaled Hosseini" , "9781594631931"},
         { "A Thousand Splendid Suns", "41", "5", "true", ":/{/assets/splendid suns.jpeg" , "Arab-American" , "Khaled Hosseini" , "9780143180654"}


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
        {"Cool Kids Tshirt", "20", "5", "true", ":/Tshirts/assets/Cool Kids Are Reading.jpeg", "T-shirt", "L"},
        { "I’d Rather Be Reading Tshirt","30", "5", "true", ":/Tshirts/assets/I'd Rather tshirt.jpeg"  ,  "T-shirt",   "S"},
        { " Reading TicketTshirt","30", "5", "true", ":/Tshirts/assets/Reading Ticket Tshirst.jpeg"  ,  "T-shirt",   "XS"},
        { "Raising Readers Tote Bag","36", "5", "true", ":/Bags/assets/Raising Readers Tote Bag.jpeg"  ,  "Bag",   " "},
        { "Book Stack Tote Bag","38", "5", "true", ":/Bags/assets/Book Stack Tote Bag.jpeg"  ,  "Bag",   " "},
        { "Medad Merchandise Tote Bag","40", "5", "true", ":/Bags/assets/Screenshot 2024-05-01 145322.png"  ,  "Bag",   " "},
        { " Bookmark set1","10", "5", "true", ":/BookMarks/assets/Bookmark Set1.jpeg"  ,  "BookMarks",   " "},
        { " Bookmark set2","10", "5", "true", ":/BookMarks/assets/Bookmark Set3.jpeg"  ,  "BookMarks",   " "},
        { " Bookmark set3","10", "5", "true", ":/BookMarks/assets/Bookmark Set2.jpeg"  ,  "BookMarks",   " "},
        { " Bookmark Palestine1","15", "5", "true", ":/BookMarks/assets/Bookmark Set Plaestine 1.jpeg"  ,  "BookMarks",   " "},
        { " Bookmark Palestine2","15", "5", "true", ":/BookMarks/assets/Bookmark Set Palestine2.jpeg"  ,  "BookMarks",   " "},
        { " Bookmark HarryPotter","20", "5", "true", ":/BookMarks/assets/Bookmark Set Harry Potter2.jpeg"  ,  "BookMarks",   " "},
        { " Bookmark Egyptian","25", "5", "true", ":/BookMarks/assets/Bookmark Set Egyptian 2.jpeg"  ,  "BookMarks"," "},
        { " Bookmark Arabic","30", "5", "true", ":/BookMarks/assets/Bookmark Set Arabic 2.jpeg"  ,  "BookMarks", " "},
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
                if (suggestions.size() >= 5) {
                    return suggestions; //only taking five suggestions
                }
                break;
            }
        }
    }
    return suggestions;
}

void ProductManager::makeFirstPage(){
    initializeProducts();
    vector<Products*> recommendations;
    recommendations = suggestSimilarItems();

    int column = 0; //track the column index for the current book

    for (Products* product : recommendations) {
        Books* book = dynamic_cast<Books*>(product);
        if (book) {
            //retrieve book information from the bookProducts vector
            QString name = book->getName();
            QPixmap imagePath = book->getImage();
            double price = book->getPrice();

            //create a QLabel for displaying the book's image
            QLabel* imageLabel = new QLabel();
            imageLabel->setPixmap(imagePath.scaled(100, 100)); // Size might need adjusting

            //create QLabel for name and price
            QLabel* nameLabel = new QLabel(name);
            QLabel* priceLabel = new QLabel(QString::number(price));

            //add the labels to the horizontal layout
            ui->recsLayout->addWidget(imageLabel, 0, Qt::AlignTop);
            ui->recsLayout->addWidget(nameLabel, 1, Qt::AlignTop);
            ui->recsLayout->addWidget(priceLabel, 2, Qt::AlignTop);

            //increment the column index for the next book
            column++;
        }
    }
}


