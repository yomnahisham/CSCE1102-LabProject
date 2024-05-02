#include "customer.h"


Customer::Customer() {}
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
