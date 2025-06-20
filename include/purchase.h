#ifndef PURCHASE
#define PURCHASE

#include "database.h"

#include <string>

class Purchase {
private:
    bool purchaseLoop;
    char choice;
    int productIndex;
    int quantity;
    std::string name, address, phoneNumber, cardNumber, expiryDate, cvv;
    float totalPrice;

public:
    void menu(Database& database);
    void products(Database& database);
    void order(Database& database);
};

#endif
