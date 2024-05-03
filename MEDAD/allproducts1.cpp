#include "allproducts1.h"
#include "ui_allproducts1.h"
#include "search.h"
#include "ui_search.h"
#include "productmanager.h"
#include "clickablelabels.h"
#include "customer.h"
#include "shoppingcart.h"
#include "books.h"
#include "accessories.h"
#include "techs.h"
#include "loginwindow.h"
#include"products.h"

#include<vector>


AllProducts1::AllProducts1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AllProducts1)
{
    ui->setupUi(this);
    QPixmap logoPix(":/logos/assets/nameonlyLogo.png");
    int w = ui->logo->width();
    int h = ui->logo->height();
    ui-> logo -> setPixmap(logoPix.scaled(w,h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->logo->move(50, 50);

    QPixmap sublogoPix(":/logos/assets/logosubtitle.png");
    ui-> sublogo -> setPixmap(sublogoPix.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int widthFull = screenGeometry.width();
    int heightFull = screenGeometry.height();

    int recsLayoutHeight = ui->firstlayout->parentWidget()->height() + 40;

    //adjusting the size of the parent widget of recsLayout
    ui->firstlayout->parentWidget()->resize(widthFull-100, recsLayoutHeight);

    int column = 0; //track the column index for the current book


    ClickableLabels* cartLabel = new ClickableLabels(this);
    ClickableLabels* signOutButton = new ClickableLabels(this);

    //setting image of the clickable shopping cart label
    QPixmap cartPix(":/logos/assets/shoppingcartlogo.png");
    cartLabel->setPixmap(cartPix.scaled(60, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    int cartLabelWidth = cartLabel->width();
    cartLabel->move(widthFull - (2*cartLabelWidth), 60);

    int productLayoutHeight = heightFull + 10;
    ui->firstlayout->parentWidget()->resize(widthFull-100, productLayoutHeight);
    ui->firstlayout->parentWidget()->resize(widthFull-100, productLayoutHeight);
}

ProductManager* ManagerObject;


void AllProducts1::allproductsdisplay(vector<Products*>& displayedProducts)
{
    int maxBooksPerRow = 10;
    int booksInCurrentRow1 = 0;
    int booksInCurrentRow2 = 0;

    // Clear existing layouts and widgets
    clearLayout(ui->firstlayout);
    clearLayout(ui->secondlayout);

    // Create layouts for each section
    QHBoxLayout* layout1 = new QHBoxLayout();
    QHBoxLayout* layout2 = new QHBoxLayout();

    for (Products* product : displayedProducts) {
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
    ui->firstlayout->addLayout(layout1);
    ui->secondlayout->addLayout(layout2);

    // Set alignment
    ui->firstlayout->setAlignment(Qt::AlignTop);
    ui->secondlayout->setAlignment(Qt::AlignTop);
}

void AllProducts1::clearLayout(QLayout *layout)
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


AllProducts1::~AllProducts1()
{
    delete ui;
}
