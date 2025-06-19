#ifndef ACCOUNT
#define ACCOUNT

#include "admin_panel.h"
#include "database.h"
#include "purchase.h"

#include <string>

class Account {
private:
    bool programLoop;
    char choice;
    std::string username, password, rePassword;
    bool result;

public:
    void main(Database& database, Purchase& purchase, Admin& admin);
    bool sign_in(Database& database);
    bool sign_up(Database& database);
    bool admin_sign_in(Database& database);
};

#endif
