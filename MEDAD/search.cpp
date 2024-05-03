#include "search.h"
#include "ui_search.h"
#include "productmanager.h"
#include "ui_productmanager.h"
#include "clickablelabels.h"
#include "customer.h"
#include "shoppingcart.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"
#include "loginwindow.h"
Search::Search(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Search)

{
    ui->setupUi(this);

    QPixmap logoPix(":/logos/assets/nameonlyLogo.png");
    int w = ui->Logo->width();
    int h = ui->Logo->height();
    ui-> Logo -> setPixmap(logoPix.scaled(w,h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->Logo->move(50, 50);

    QPixmap sublogoPix(":/logos/assets/logosubtitle.png");
    ui-> LogoSub -> setPixmap(sublogoPix.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int widthFull = screenGeometry.width();
     int heightFull = screenGeometry.height();

    int recsLayoutHeight = ui->horizontalLayout->parentWidget()->height() + 40;

    //adjusting the size of the parent widget of recsLayout
    ui->horizontalLayout->parentWidget()->resize(widthFull-100, recsLayoutHeight);

    int column = 0; //track the column index for the current book


    ClickableLabels* cartLabel = new ClickableLabels(this);
    ClickableLabels* signOutButton = new ClickableLabels(this);

    //setting image of the clickable shopping cart label
    QPixmap cartPix(":/logos/assets/shoppingcartlogo.png");
    cartLabel->setPixmap(cartPix.scaled(60, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    int cartLabelWidth = cartLabel->width();
    cartLabel->move(widthFull - (2*cartLabelWidth), 60);

    QPixmap youPix(":/logos/assets/basedonsearch.png");
    ui->Based->setPixmap(youPix.scaled(ui->Based->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->Based->setVisible(true);

    //connecting cartLabel, its signal from ClickableLabels, this ui, and the function onCartClicked to handle what happens after cart is clicked
    //connect(cartLabel, &ClickableLabels::clicked, this, &ProductManager::onCartClicked);

    //setting the button for signing out, user data should be saved in file
    QPixmap signoutPix(":/logos/assets/signoutbutton.png");
    signOutButton->setPixmap(signoutPix.scaled(100, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    int signOutButtonWidth = 135;
    signOutButton->move(widthFull - (signOutButtonWidth), 60);

    //connecting signoutbutton, its signal from ClickableLabels, this ui, and the function onSignOutClicked to handle the click
    //connect(signOutButton, &ClickableLabels::clicked, this, &ProductManager::onSignOutClicked);


    //connect(ui->filterBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ProductManager::sortProducts);*/
    int productLayoutHeight = heightFull + 10;
     ui->horizontalLayout->parentWidget()->resize(widthFull-100, productLayoutHeight);
     ui->horizontalLayout_->parentWidget()->resize(widthFull-100, productLayoutHeight);



}

Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_clicked()
{
   /* hide();
     AllUsers* allUsers = new AllUsers();
    ProductManager* productmanager=new ProductManager(nullptr , loggedUser, allUsers);
    productmanager->show();*/
}

ProductManager* productManager;

void Search::DisplaySearch(vector<Products*>& searchResults)
{
    int maxBooksPerRow = 10;
    int booksInCurrentRow1 = 0;
    int booksInCurrentRow2 = 0;

    // Clear existing layouts and widgets
    clearLayout(ui->horizontalLayout);
    clearLayout(ui->horizontalLayout_);

    // Create layouts for each section
    QHBoxLayout* layout1 = new QHBoxLayout();
    QHBoxLayout* layout2 = new QHBoxLayout();

    for (Products* product : searchResults) {
        Books* book = dynamic_cast<Books*>(product);
        if (book) {
            QString name = book->getName();
            QPixmap imagePath = book->getImage();
            double price = book->getPrice();
            if (!imagePath.isNull()) {
                // Create widgets
                QLabel* imageLabel = new QLabel();
                imageLabel->setPixmap(imagePath.scaledToHeight(200, Qt::SmoothTransformation)); // Scale image to fixed height
                imageLabel->setFixedSize(180, 180); // Set fixed size for the label

                QLabel* nameLabel = new QLabel(name);
                nameLabel->setFont(QFont("Optima", 12, QFont::Bold));
                nameLabel->setWordWrap(true);

                QLabel* priceLabel = new QLabel(QString::number(price) + " EGP");
                priceLabel->setFont(QFont("Optima", 12));

                ClickableLabels* addtoCart = new ClickableLabels(this);
                QPixmap addPix(":/logos/assets/addtoCart.png");
                addtoCart->setPixmap(addPix.scaled(30, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
                //connect(addtoCart, &ClickableLabels::clicked, this, &Search::onAddToCartClicked);

                // Create a vertical layout for each book
                QVBoxLayout* bookLayout = new QVBoxLayout();
                bookLayout->addWidget(imageLabel);
                bookLayout->addWidget(nameLabel);
                bookLayout->addWidget(priceLabel);
                bookLayout->addWidget(addtoCart);
                bookLayout->setAlignment(Qt::AlignTop);

                // Determine which section layout to add the book layout to
                if (booksInCurrentRow1 < maxBooksPerRow) {
                    layout1->addLayout(bookLayout);
                    booksInCurrentRow1++;
                }
                else if (booksInCurrentRow2 < maxBooksPerRow) {
                    layout2->addLayout(bookLayout);
                    booksInCurrentRow2++;
                }
            } else {
                qDebug() << "Invalid image path for book: " << name;
            }
        }
    }

    // Add the section layouts to the main layouts
    ui->horizontalLayout->addLayout(layout1);
    ui->horizontalLayout_->addLayout(layout2);

    // Set alignment
    ui->horizontalLayout->setAlignment(Qt::AlignTop);
    ui->horizontalLayout_->setAlignment(Qt::AlignTop);
}

void Search::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
            delete item->widget();
        }
        delete item;
    }
}
