#include "productmanager.h"
#include "ui_productmanager.h"

ProductManager::ProductManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProductManager)
{
    ui->setupUi(this);
}

void ProductManager::setUser(User* loggedUser){
    user = loggedUser;
    if (user)
        qDebug()<<"user transfered succesfully";
}


ProductManager::~ProductManager()
{
    delete ui;
}
