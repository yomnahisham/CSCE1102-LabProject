#include "customer.h"


Customer::Customer() {}

void Customer::setPreferredGenres(const vector<string>& genres){
    preferredGenres = genres;
}

const vector<string>& Customer::getPreferredGenres() const {
    return preferredGenres;
}

void Customer::virtualfunc()
{

}
