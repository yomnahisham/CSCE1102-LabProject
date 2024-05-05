#include "checkout.h"
#include "ui_checkout.h"

#include <QVector>
#include <QVBoxLayout>

Checkout::Checkout(QWidget *parent, QVector<ShoppingCart::CartItems>itemsInCart)
    : QWidget(parent)
    , ui(new Ui::Checkout)
{
    ui->setupUi(this);
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



    ui->CVV->setPlaceholderText("E.g 123");
    ui->CreditNum->setPlaceholderText("E.g 7788 2773 8322");

    connect(ui->CashButton, &QRadioButton::toggled, [this](bool checked){
       if(!checked){
           this->ui->CreditWidget->setVisible(true);
       }
   });

    connect(ui->CreditButton, &QRadioButton::toggled, [this](bool checked){
        this->ui->CreditWidget->setVisible(checked);
    });



}

void Checkout::SaveCreditInfo(){

    QString cvv = ui->CVV->text();
    for(int i = 0; i < 3; i++){
       QString::number(CVV[i]) = cvv[i];
    }

    Month = ui->Month->currentIndex();
    QString year = ui->Year->currentText();
    Year = year.toInt();
    CardNum = ui->CreditNum->text();


}
Checkout::~Checkout()
{
    delete ui;
}

void Checkout::on_pushButton_clicked()
{
    if(ui->SaveCredit->isChecked()){
          SaveCreditInfo();
    }
}

