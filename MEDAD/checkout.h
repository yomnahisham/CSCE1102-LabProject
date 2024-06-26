#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "shoppingcart.h"
#include "user.h"
#include "allusers.h"
#include "shoppingcart.h"
#include <QWidget>
#include <QVector>

namespace Ui {
class Checkout;
}

class Checkout : public QWidget
{
    Q_OBJECT

public:
    explicit Checkout(QWidget *parent, ShoppingCart *cart, QVector<ShoppingCart::CartItems>itemsInCart, User *logged, AllUsers *all);
    ~Checkout();

    void setTotal(double);
    double getTotal() const;
    void setDeliveryFee(double);
    double getDeliveryFee() const;
    void setSubTotal(double) ;
    double getSubTotal() const;
    struct CreditCard{
        int CVV;
        QString CardNum;
        int Month;
        int Year;

        CreditCard(int c = -1 , const QString& card = QString(), int m = 0, int y = 0) : CVV(c), CardNum(card), Month(m), Year(y){};
        bool isNull() const {return (CVV == -1 && CardNum.isEmpty() && Month == 0 && Year == 0);}

    };
    QTableWidgetItem *cardTableItem;
    QTableWidgetItem *cvvTableItem;
    void SaveCreditInfo();
    void CreditCardSystem();
    void updateCreditTable();
    struct Address{
        QString Province;
        QString Area;
        QString Street;
        QString Building;
        int Floor;
        int Apartment;
        QString PhoneNumber;

        Address(const QString& p, const QString& a,const QString& s, const QString& b, int f, int ap, const QString& ph):
            Province(p) , Area(a), Street(s), Building(b), Floor(f), Apartment(ap), PhoneNumber(ph) {};

    };
    vector<CreditCard> userCreditCards;
    vector<Address> userAddress;
   void AddressSystem();
   void SaveAddressInfo();
   void updateAddressTable();
   QTableWidgetItem *areaTableItem;
   QTableWidgetItem *phoneTableItem;
   void LoadDataIntoCreditCard(Customer *customer);
   void LoadDataIntoAddress(Customer *customer);
   ShoppingCart *cartt;
   Customer *customer;
   bool isCredit;
   void userDiscount();



private slots:


    void on_enterCredit_clicked();

    void on_ReTurnHome_clicked();

    void on_enterAddress_clicked();

    void on_ConfirmButton_clicked();


    void on_enterDiscount_clicked();

private:
    Ui::Checkout *ui;
    double Total;
    double subTotal;
    double deliveryFee;
    User *user ;
    AllUsers *users;
    bool isApplied = false;
    double discountPercentage;
    QStringList PromoCodes = {"HHXB", "PPOX", "UAFX", "VBBS", "XYSA", "AVXG", "VBWQ", "HAJQ", "VZBQ", "QBAI"};
    QMap<QString, double> discounts = {
                            {"HHXB",0.10}, {"PPOX", 0.20}, {"UAFX", 0.30} ,{"VBBS", 0.49} , {"XYSA", 0.50},
                            {"AVXG", 0.60}, {"VBWQ", 0.70}, {"HAJQ", 0.80} , {"VZBQ" , 0.90} , {"QBAI", 1.00}
    };


};

#endif // CHECKOUT_H
