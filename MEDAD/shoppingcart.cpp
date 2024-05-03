#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include<QTableWidget>
#include <QTableWidgetItem>

ShoppingCart::ShoppingCart(QWidget *parent):
    QWidget(parent)
    , ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
    ui->cartTable->setColumnCount(3);
    QStringList Headers = {"Item Name: ", "Price: ", "Quantity:"};
    ui->cartTable->setHorizontalHeaderLabels(Headers);



}

void ShoppingCart::AddItemToCart(const QString &ItemName, double price, int quantity){
    int row = ui->cartTable->rowCount();
    QTableWidgetItem *itemName = new QTableWidgetItem;
    QTableWidgetItem *itemPrice = new QTableWidgetItem;
    QTableWidgetItem *itemQuantity = new QTableWidgetItem;
    itemName->setText(ItemName);
    itemPrice->setText(QString::number(price));
    itemQuantity->setText(QString::number(quantity));
    ui->cartTable->insertRow(row);
    ui->cartTable->setItem(row, 0, itemName);
    ui->cartTable->setItem(row, 1, itemPrice);
    ui->cartTable->setItem(row, 2, itemQuantity);



}

ShoppingCart::~ShoppingCart()
{
    delete ui;
}
