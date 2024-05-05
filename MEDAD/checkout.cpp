#include "checkout.h"
#include "ui_checkout.h"

#include <QVector>
#include <QVBoxLayout>

Checkout::Checkout(QWidget *parent, QVector<ShoppingCart::CartItems>itemsInCart)
    : QWidget(parent)
    , ui(new Ui::Checkout)
{
    ui->setupUi(this);
    for(const auto& item: itemsInCart){
        Total += item.price * item.quantity;

    }
    QVBoxLayout *creditLayout = new QVBoxLayout;
    creditLayout->setAlignment(Qt::AlignLeft);
    ui->CreditWidget->setVisible(false);
    ui->CreditWidget->setLayout(creditLayout);

    ui->PaymentLayout->setAlignment(Qt::AlignLeft);
    ui->PaymentWidget->setLayout(ui->PaymentLayout);
    ui->PaymentWidget->setVisible(true);

    ui->subTotal->setText("SubTotal: " + QString("$%1").arg(Total, 0, 'f', 2));

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

    if(ui->SaveCredit->isChecked()){
      //  saveCreditInfo();
    }

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

}

