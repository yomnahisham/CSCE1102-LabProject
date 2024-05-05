#include "customer.h"
#include "products.h"

Customer::Customer() {
    emptyCart =true;
}
Customer::~Customer() {}


void Customer::setPreferredGenres(const vector<QString>& genres){
    preferredGenres = genres;
}

const vector<QString>& Customer::getPreferredGenres() const {
    return preferredGenres;
}

void Customer::virtualfunc()
{

}

void Customer::setShopingCart(const vector <Customer::UserCart> Cart){
    userCart = Cart;


}
const vector<Customer::UserCart>& Customer::getShopingCart() const{
    return userCart;
}

void Customer::addToCartVec(const UserCart& items){
    userCart.push_back(items);

}


void Customer::setCreditCards(const vector<UserCreditCard> Credit){
    userCredit = Credit;
}
const vector <Customer::UserCreditCard>& Customer::getCreditCards() const{
    return userCredit;
}
void Customer::addToCreditVec(const UserCreditCard& creditItems){
    userCredit.push_back(creditItems);
}

void Customer::setAddress(const vector<UserAddress> Address){
    userAddress = Address;

}
const vector<Customer::UserAddress>& Customer::getAddress() const{
    return userAddress;
}
void Customer::addToAddressVec(const UserAddress &addressItems){
    userAddress.push_back(addressItems);
}

/*void Customer::setShopingCart(const QVector <ShoppingCart::CartItems> Cart){
    cart = Cart;
}

const QVector <ShoppingCart::CartItems>& Customer::getShopingCart() const {
    return cart;
}*/
