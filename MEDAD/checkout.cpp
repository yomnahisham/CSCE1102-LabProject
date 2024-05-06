#include "checkout.h"
#include "ui_checkout.h"
#include "productmanager.h"
#include "shoppingcart.h"
#include "customer.h"


#include <QVector>
#include <QVBoxLayout>
#include <QHBoxLayout>

Checkout::Checkout(QWidget *parent, ShoppingCart *cart, QVector<ShoppingCart::CartItems>itemsInCart, User *logged, AllUsers *all)
    : QWidget(parent)
    , ui(new Ui::Checkout)
{
    ui->setupUi(this);
    user = logged ;
    users = all;
    cartt = cart;

    ui->savedAddressTable->setVisible(false);
    ui->savedAddressTable->setColumnCount(2);
    QStringList AddressHeaders = {"Area", "Phone Number"};
    ui->savedAddressTable->setHorizontalHeaderLabels(AddressHeaders);

    ui->CreditCardsTableWidget->setVisible(false);
    ui->CreditCardsTableWidget->setColumnCount(2);
    QStringList CreditHeaders = {"Card Num", "CVV"};
    ui->CreditCardsTableWidget->setHorizontalHeaderLabels(CreditHeaders);
    ui->CreditCardsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->CreditCardsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->CreditCardsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->CreditAddOrSaveGroup->setVisible(false);
    ui->CreditCardsGroup->setVisible(false);
    ui->SavedAddressGroup->setVisible(false);
    ui->AddressWidget->setVisible(false);

    deliveryFee = 20.00;

    for(const auto& item: itemsInCart){
        subTotal += item.price * item.quantity ;

    }
    Total = subTotal + deliveryFee;

    ui->Total->setText("Total: " + QString("EGP %1").arg(Total, 0, 'f', 2));
    ui->DeliveryFee->setText("Delivery Fee: " + QString("EGP %1").arg(deliveryFee, 0, 'f', 2));
    ui->subTotal->setText("SubTotal: " + QString("EGP %1").arg(subTotal, 0, 'f', 2));

    QVBoxLayout *creditLayout = new QVBoxLayout;
    creditLayout->setAlignment(Qt::AlignLeft);
    ui->CreditWidget->setVisible(false);
    ui->CreditWidget->setLayout(creditLayout);


    QVBoxLayout *paymentLayout = new QVBoxLayout;
    paymentLayout->setAlignment(Qt::AlignLeft);
    ui->PaymentWidget->setVisible(true);
    ui->PaymentWidget->setLayout(paymentLayout);

    QHBoxLayout *addressLayout = new QHBoxLayout;
    addressLayout->setAlignment(Qt::AlignLeft);
    ui->AddressWidget->setLayout(addressLayout);



    ui->CVV->setPlaceholderText("E.g 123");
    ui->CreditNum->setPlaceholderText("E.g 7788277383225678");
    ui->Area->setPlaceholderText("E.g Rehab City 1");
    ui->Street->setPlaceholderText("E.g Othman Ibn Affan");
    ui->Apt->setPlaceholderText("E.g 1");
    ui->Floor->setPlaceholderText("E.g 1");
    ui->Building->setPlaceholderText("E.g BuildingName");
    ui->PhoneNum->setPlaceholderText("E.g 101 234 432 7");

    connect(ui->CashButton, &QRadioButton::toggled, [this](bool checked){
       if(!checked){
           this->ui->CreditWidget->setVisible(true);
       }
   });

    if (Customer *customer = dynamic_cast<Customer *>(user)) {
        LoadDataIntoCreditCard(customer);
        LoadDataIntoAddress(customer);
    }

    CreditCardSystem();
    AddressSystem();





}

void Checkout::AddressSystem(){
    connect(ui->AddNewAddressButton, &QRadioButton::toggled, [this](bool checked){
        this->ui->AddressWidget->setVisible(checked);

    });

    connect(ui->SavedAddressButton, &QRadioButton::toggled, [this](bool checked){
        this->ui->SavedAddressGroup->setVisible(checked);
    });
}
//void SaveAddressInfo();
void Checkout::SaveAddressInfo(){

    QString province = ui->Province->currentText();
    QString area = ui->Area->text();
    QString street = ui->Street->text();
    QString building = ui->Building->text();
    int floor = ui->Floor->text().toInt();
    int apt = ui->Apt->text().toInt();
    QString phone = ui->PhoneNum->text();


    Address newAddress(province, area, street, building, floor, apt, phone );
    userAddress.push_back(newAddress);

}
//void updateAddressTable();
void Checkout::updateAddressTable(){

    for(const auto& add : userAddress){
        int currentRow = ui->savedAddressTable->rowCount();
        ui->savedAddressTable->insertRow(currentRow);
        QString displayedNum = "+20" + add.PhoneNumber;
        areaTableItem = new QTableWidgetItem(add.Area);
        phoneTableItem = new QTableWidgetItem(displayedNum);
        ui->savedAddressTable->setItem(currentRow, 0, areaTableItem);
        ui->savedAddressTable->setItem(currentRow, 1, phoneTableItem);
    }


}

void Checkout::LoadDataIntoAddress(Customer *customer){

    ui->savedAddressTable->clear();
    ui->savedAddressTable->setRowCount(0);


    for(const auto& add : customer->getAddress()){
        int currentRow = ui->savedAddressTable->rowCount();
        ui->savedAddressTable->insertRow(currentRow);
        QString displayedNum = "+20" + add.PhoneNumber;
        areaTableItem = new QTableWidgetItem(add.Area);
        phoneTableItem = new QTableWidgetItem(displayedNum);
        ui->savedAddressTable->setItem(currentRow, 0, areaTableItem);
        ui->savedAddressTable->setItem(currentRow, 1, phoneTableItem);
    }
}

void Checkout::CreditCardSystem(){

    connect(ui->CreditButton, &QRadioButton::toggled, [this](bool checked){
        this->ui->CreditAddOrSaveGroup->setVisible(checked);
        this->ui->CreditWidget->setVisible(false);
    });

    connect(ui->AddNewCreditButton, &QRadioButton::toggled, [this](bool checked){
        this->ui->CreditWidget->setVisible(checked);
    });

    connect(ui->SavedCredtButton, &QRadioButton::toggled, [this](bool checked){
        this->ui->CreditCardsGroup->setVisible(checked);
        this->ui->CreditCardsTableWidget->setVisible(checked);
    });


}

void Checkout::SaveCreditInfo(){

    QString cvvText = ui->CVV->text();
    QString cardnum = ui->CreditNum->text();
    int Month = ui->Month->currentIndex() + 1;
    int Year = ui->Year->currentText().toInt();

    if(cardnum.length() == 16 && cvvText.length() == 3 && (Month > 0 && Month <= 12) && (Year >= 2024)){
        int cvv = cvvText.toInt();
        CreditCard newCard(cvv, cardnum, Month, Year);
        userCreditCards.push_back(newCard);

    }

}

void Checkout::updateCreditTable(){


    for(const auto& card : userCreditCards){
        int currentRow = ui->CreditCardsTableWidget->rowCount();
        ui->CreditCardsTableWidget->insertRow(currentRow);
        QString displayedNum = "****" + card.CardNum.right(4);
        cardTableItem = new QTableWidgetItem(displayedNum);
        cvvTableItem = new QTableWidgetItem(QString::number(card.CVV));
        ui->CreditCardsTableWidget->setItem(currentRow, 0, cardTableItem);
        ui->CreditCardsTableWidget->setItem(currentRow, 1, cvvTableItem);
    }



}

void Checkout::LoadDataIntoCreditCard(Customer *customer){

    ui->CreditCardsTableWidget->clear();
    ui->CreditCardsTableWidget->setRowCount(0);

    ui->CreditCardsTableWidget->setColumnCount(2);
    QStringList headers = {"Card Num", "CVV"};
    ui->CreditCardsTableWidget->setHorizontalHeaderLabels(headers);

    for(const auto &card : customer->getCreditCards()){
        int row = ui->CreditCardsTableWidget->rowCount();
        ui->CreditCardsTableWidget->insertRow(row);
        QString displayedNum = "****" + card.CardNum.right(4);
        cardTableItem = new QTableWidgetItem(displayedNum);
        cvvTableItem = new QTableWidgetItem(QString::number(card.CVV));
        ui->CreditCardsTableWidget->setItem(row, 0, cardTableItem);
        ui->CreditCardsTableWidget->setItem(row, 1, cvvTableItem);

    }

}

Checkout::~Checkout()
{
    delete ui;
}



void Checkout::setTotal(double x){
    Total =    x;
}
double Checkout::getTotal() const{
    return Total;
}
void Checkout::setDeliveryFee(double x){
    deliveryFee =  x;

}
double Checkout::getDeliveryFee() const{
    return deliveryFee;
}
void Checkout::setSubTotal(double x){
    subTotal = x;
}
double Checkout::getSubTotal() const{
    return subTotal;
}

void Checkout::on_enterCredit_clicked()
{

    if(ui->SaveCredit->isChecked()){
        SaveCreditInfo();
    }
    ui->CreditWidget->setVisible(false);
    ui->CreditCardsGroup->setVisible(true);
    ui->CreditCardsTableWidget->setVisible(true);
    updateCreditTable();

}

void Checkout::on_pushButton_clicked(){


}
void Checkout::on_ReTurnHome_clicked()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    ProductManager *productManager = new ProductManager(nullptr, user, users, cartt);
    productManager->resize(screenGeometry.width(), screenGeometry.height());
    productManager->show();
    this->hide();
}


void Checkout::on_enterAddress_clicked()
{
    if(ui->SaveAddress->isChecked()){
        SaveAddressInfo();
    }
    ui->AddressWidget->setVisible(false);
    ui->SavedAddressGroup->setVisible(true);
    updateAddressTable();
}


void Checkout::on_ConfirmButton_clicked()
{

    Customer *customer = dynamic_cast<Customer *>(user);
    if(customer){
        for(const auto& card : userCreditCards){
            Customer::UserCreditCard credit(card.CVV, card.CardNum, card.Month, card.Year);
            customer->addToCreditVec(credit);
        }

        for(const auto& add : userAddress){

            Customer::UserAddress newAdd(add.Province, add.Area, add.Street, add.Building, add.Floor, add.Apartment, add.PhoneNumber);
            customer->addToAddressVec(newAdd);

        }
    }


}

