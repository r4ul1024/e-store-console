#include "account.h"
#include "admin_panel.h"
#include "database.h"
#include "purchase.h"
#include <iostream>

int main()
{
    Account account;
    Database database;
    Purchase purchase;
    Admin admin;

    std::cout << "\033[2J\033[H";
    account.main(database, purchase, admin);
}
