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

    //creating custom clickable label
    ClickableLabels* cartLabel = new ClickableLabels(this);

    //setting image of the clickable shopping cart label
    QPixmap cartPix(":/backandlogos/assets/shoppingcartlogo.png");
    cartLabel->setPixmap(cartPix.scaled(cartLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    //connecting cartLabel, its signal from ClickableLabels, this ui, and the function onCartClicked to handle what happens after cart is clicked
    connect(cartLabel, &ClickableLabels::clicked, this, &ProductManager::onCartClicked);

    int widthFull = screenGeometry.width();

    int cartLabelWidth = cartLabel->width();
    cartLabel->move(widthFull - cartLabelWidth, 30);
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
