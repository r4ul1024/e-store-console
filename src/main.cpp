#include "account.h"
#include "admin_panel.h"
#include "database.h"
#include "purchase.h"

int main()
{
    Account account;
    Database database;
    Purchase purchase;
    Admin admin;

    account.main(database, purchase, admin);
}
