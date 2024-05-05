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

/*void Customer::setShopingCart(const QVector <ShoppingCart::CartItems> Cart){
    cart = Cart;
}

const QVector <ShoppingCart::CartItems>& Customer::getShopingCart() const {
    return cart;
}*/
