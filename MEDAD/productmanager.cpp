#include "productmanager.h"
#include "ui_productmanager.h"
#include "clickablelabels.h"
#include "shoppingcart.h"

#include <QScreen>

ProductManager::ProductManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProductManager)
{
    ui->setupUi(this);

    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int widthFull = screenGeometry.width();

    //creating custom clickable label
    ClickableLabels* cartLabel = new ClickableLabels(this);

    //setting logo in the corner of the shop app
    QPixmap logoPix (":/logos/assets/nameonlyLogo.png");
    int w = ui->logoCorner->width();
    int h = ui->logoCorner->height();
    ui-> logoCorner -> setPixmap(logoPix.scaled(w,h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->logoCorner->move(50, 50);

    //setting image of the clickable shopping cart label
    QPixmap cartPix(":/logos/assets/shoppingcartlogo.png");
    cartLabel->setPixmap(cartPix.scaled(cartLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    int cartLabelWidth = cartLabel->width();
    int headerLevel = widthFull - (2*cartLabelWidth);
    cartLabel->move(headerLevel, 89);

    //connecting cartLabel, its signal from ClickableLabels, this ui, and the function onCartClicked to handle what happens after cart is clicked
    connect(cartLabel, &ClickableLabels::clicked, this, &ProductManager::onCartClicked);

}

void ProductManager::setUser(User* loggedUser){
    user = loggedUser;
    if (user)
        qDebug() << "User transferred successfully";
}

ProductManager::~ProductManager()
{
    delete ui;
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
