#ifndef PURCHASE
#define PURCHASE

#include "database.h"

#include <string>

class Purchase {
private:
    bool purchaseLoop;
    char choice;
    int productIndex;
    int productQuantity;
    std::string name, address, phoneNumber, cardNumber, expiryDate, cvv;

public:
    void main(Database& database);
    void cart(Database& database);
    void order(Database& database);
};

#endif
