#include "admin_panel.h"
#include "database.h"
#include <iostream>

void Admin::menu(Database& database)
{
    for (int i = 0; i < database.productNamesVector.size(); i++) {
        std::cout << i << "." << database.productNamesVector[i] << " | Price: " << database.productPricesVector[i] << "$ | " << database.productQuantitiesVector[i] << " Units\n";
        database.totalPrice += database.productPricesVector[i] * database.productQuantitiesVector[i];
    }
    std::cout << "\nTotal price: " << database.totalPrice << "$\n\n";
    std::cout << "[1] Add new product\n";
    std::cout << "[2] Edit product\n";
    std::cout << "[3] Delete product\n";
    std::cout << "[4] Sign out\n\n";
    std::cout << "Select: ";
    std::cin >> choice;

    if (choice == '1') {
        Admin::add_new_product(database);
    } else if (choice == '2') {

    } else if (choice == '3') {

    } else if (choice == '4') {
    }
}

void Admin::add_new_product(Database& database)
{
    std::cout << "Product name: ";
    std::cin >> productName;
    std::cout << "Product price: ";
    std::cin >> productPrice;
    std::cout << "Product quantity: ";
    std::cin >> productQuantity;

    database.productNamesVector.push_back(productName);
    database.productPricesVector.push_back(productPrice);
    database.productQuantitiesVector.push_back(productQuantity);
    database.totalPrice += productPrice * productQuantity;

    std::cout << "\033[2J\033[H";
}

void Admin::edit_product(Database& database)
{
}

void Admin::delete_product(Database& database)
{
}
