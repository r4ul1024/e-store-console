#ifndef ADMIN_PANEL
#define ADMIN_PANEL

#include "database.h"

#include <string>

class Admin {
private:
    char choice;
    int productIndex;
    std::string productName;
    int productQuantity;
    float productPrice;

public:
    void menu(Database& database);
    void add_new_product(Database& database);
    void edit_product(Database& database);
    void delete_product(Database& database);
};

#endif
