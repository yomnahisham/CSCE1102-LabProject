#include "customer.h"

vector<string> Customer::preferredGenres;

Customer::Customer() {}

void Customer::setPreferredGenres(const vector<string>& genres) {
    preferredGenres = genres;
}
