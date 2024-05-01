#include "productmanager.h"
#include "ui_productmanager.h"

ProductManager::ProductManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProductManager)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap bgImage(":/backandlogos/assets/whitebackground.png");

    // Set the background image to cover the entire widget
    setStyleSheet("QWidget { background-image: url(:/backandlogos/assets/whitebackground.png); }");
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
