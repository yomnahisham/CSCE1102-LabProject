#include "productmanager.h"
#include "ui_productmanager.h"

ProductManager::ProductManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProductManager)
{
    ui->setupUi(this);
    QPixmap cartpic(":/backandlogos/assets/shoppingcartlogo.png");
    int width = ui->cartpicture->width();
    int height = ui->cartpicture->height();
    ui->cartpicture->setPixmap(cartpic.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation));
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
