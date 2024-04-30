#include "productmanager.h"
#include "ui_productmanager.h"

ProductManager::ProductManager(QWidget *parent, User* loggedUser)
    : QWidget(parent)
    , ui(new Ui::ProductManager)
{
    ui->setupUi(this);
}

ProductManager::~ProductManager()
{
    delete ui;
}
