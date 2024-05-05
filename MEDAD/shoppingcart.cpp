#include "shoppingcart.h"
#include "productmanager.h"
#include "ui_shoppingcart.h"
#include "checkout.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QIcon>
#include <QVector>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include <QScreen>


QVector<ShoppingCart::CartItems> ShoppingCart::Cart;

ShoppingCart::ShoppingCart(QWidget *parent, User *logged, AllUsers *all):
    QWidget(parent)
    , ui(new Ui::ShoppingCart)
    ,user(logged)
    ,users (all)
{
    ui->setupUi(this);

    //Setting up Cart Table
    ui->cartTable->setColumnCount(5);
    QStringList Headers = {"Image: " , "Item Name: ", "Price: ", "Quantity:", "+/-"};

    ui->cartTable->setHorizontalHeaderLabels(Headers);
    ui->cartTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->cartTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->cartTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

}



void ShoppingCart::AddItemToCart(const QPixmap image, const QString &ItemName, double price, int quantity){

    qDebug() << "Items added in vector: " ;
    Cart.append(CartItems(image, ItemName, price , quantity));
    qDebug() << "Item add to cart" ;
    int row = ui->cartTable->rowCount();

    itemName = new QTableWidgetItem;
    itemPrice = new QTableWidgetItem;
    itemQuantity = new QTableWidgetItem;
    pic = new QTableWidgetItem;

    QIcon itemImage(image.scaled(250, 250, Qt::KeepAspectRatio, Qt::SmoothTransformation)) ;
    buttonWidget = new QWidget();
    addButton = new QPushButton("+", buttonWidget);
    subButton = new QPushButton("-", buttonWidget);
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(subButton);
    buttonLayout->setAlignment(Qt::AlignCenter);
    buttonLayout->setSpacing(0);
    buttonWidget->setLayout(buttonLayout);
    pic->setIcon(itemImage);

    itemName->setText(ItemName);
    itemPrice->setText(QString::number(price));
    itemQuantity->setText(QString::number(quantity));



    ui->cartTable->insertRow(row);
    ui->cartTable->setItem(row, 0, pic);
    ui->cartTable->setItem(row, 1, itemName);
    ui->cartTable->setItem(row, 2, itemPrice);
    ui->cartTable->setItem(row, 3, itemQuantity);
    ui->cartTable->setCellWidget(row, 4, buttonWidget);
    ui->cartTable->setRowHeight(row, 50);

    connect(addButton, &QPushButton::clicked, [this, row](){
        qDebug() <<"Plus button clicked";
        this->addQuantity(row);
    });
    connect(subButton , &QPushButton::clicked, [this, row](){
        qDebug() << "Minus button clicked";
        this->subQuantity(row);

    });


}

void ShoppingCart::addQuantity(int row){
    qDebug() << "Quantity incremented" ;
    itemQuantity = ui->cartTable->item(row,3);
    int NewQuantity = itemQuantity->text().toInt();
    ++NewQuantity;
    itemQuantity->setText(QString::number(NewQuantity));

    if(row < Cart.size()){
        Cart[row].quantity = NewQuantity;
        qDebug() << "Quantity changed in vector"  << Cart[row].quantity;
    }

}

void ShoppingCart::subQuantity(int row){
    qDebug() << "Quantity decremented";

    itemQuantity = ui->cartTable->item(row, 3);

    int NewQuantity = itemQuantity->text().toInt();

    qDebug() << "Quantity before decrementation" << NewQuantity;

    --NewQuantity;

    qDebug() << "Quantity after decrememtation" << NewQuantity;

    itemQuantity->setText(QString::number(NewQuantity));
    if(NewQuantity == 0){
        ui->cartTable->removeRow(row);
        if(row < Cart.size()){
            qDebug() << "Items removed from vector";
            Cart.removeAt(row);
        }

    }else if (row < Cart.size()){
        Cart[row].quantity = NewQuantity;
        qDebug() << "Quantity changed in vector"  << Cart[row].quantity;
    }


}
void ShoppingCart::handleItemDeletion(){

    QList<QTableWidgetItem *> selectedItems = ui->cartTable->selectedItems();
    QSet<int> NumOfRows;
    for(int i = 0; i < selectedItems.size(); i++){
        NumOfRows.insert(selectedItems[i]->row());

    }
    QList<int> RowsInCart(NumOfRows.begin(), NumOfRows.end());
    std::sort(RowsInCart.begin(), RowsInCart.end());
    std::reverse(RowsInCart.begin(), RowsInCart.end());
    for(int i = 0 ; i < RowsInCart.size(); i++){

        ui->cartTable->removeRow(RowsInCart[i]);
        if(RowsInCart[i] < Cart.size()){

            Cart.removeAt(RowsInCart[i]);
            qDebug() << "Items removed from vector" ;

        }
    }

}


ShoppingCart::~ShoppingCart()
{

    delete ui;
}




void ShoppingCart::on_DeleteItem_clicked()
{

    handleItemDeletion();

}


void ShoppingCart::on_returnHome_clicked()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    ProductManager *productManager = new ProductManager(nullptr, user, users, this);
    productManager->resize(screenGeometry.width(), screenGeometry.height());
    productManager->show();
    this->hide();
}


void ShoppingCart::on_CheckOutButton_clicked()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    Checkout *check = new Checkout(nullptr, this , Cart, user, users);
    check->resize(screenGeometry.width(), screenGeometry.height());
    check->show();
    this->hide();
}

