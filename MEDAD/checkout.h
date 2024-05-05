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

        CreditCard(int c, const QString& card, int m, int y) : CVV(c), CardNum(card), Month(m), Year(y){};


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
   void AddressSystem();
   void SaveAddressInfo();
   void updateAddressTable();
   QTableWidgetItem *areaTableItem;
   QTableWidgetItem *phoneTableItem;

   ShoppingCart *cartt;

private slots:
    void on_pushButton_clicked();

    void on_enterCredit_clicked();

    void on_ReTurnHome_clicked();

    void on_enterAddress_clicked();

protected:
    vector<CreditCard> userCreditCards;
    vector<Address> userAddress;
private:
    Ui::Checkout *ui;
    double Total;
    double subTotal;
    double deliveryFee;
    User *user ;
    AllUsers *users;



};

#endif // CHECKOUT_H
