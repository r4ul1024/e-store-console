#include "admin_panel.h"
#include "database.h"
#include <iostream>

void Admin::main(Database& database)
{
    adminPanelLoop = true;

    while (adminPanelLoop) {
        std::cout << "### Admin panel ###\n\n";
        for (int i = 0; i < database.productNamesVector.size(); i++) {
            std::cout << i << "." << database.productNamesVector[i] << " | Price: " << database.productPricesVector[i] << "$ | " << database.productQuantitiesVector[i] << " Units\n";
        }
        std::cout << "\n[1] Add new product\n";
        std::cout << "[2] Edit product\n";
        std::cout << "[3] Sign out\n\n";
        std::cout << "Select: ";
        std::cin >> choice;

        if (choice == '1') {
            Admin::add_new_product(database);
        } else if (choice == '2') {
            Admin::edit_product(database);
        } else if (choice == '3') {
            adminPanelLoop = false;
            std::cout << "\033[2J\033[H";
        } else {
            std::cout << "\033[2J\033[H";
        }
    }
}

void Admin::add_new_product(Database& database)
{
    std::cout << "\nProduct name: ";
    std::cin >> productName;
    std::cout << "Product price: ";
    std::cin >> productPrice;
    std::cout << "Product quantity: ";
    std::cin >> productQuantity;

    database.productNamesVector.push_back(productName);
    database.productPricesVector.push_back(productPrice);
    database.productQuantitiesVector.push_back(productQuantity);

    std::cout << "\033[2J\033[H";
    std::cout << "New product added\n\n";
}

void Admin::edit_product(Database& database)
{
    std::cout << "\nProduct index: ";
    std::cin >> productIndex;

    std::cout << "\n[1] Edit name\n";
    std::cout << "[2] Edit price\n";
    std::cout << "[3] Edit quantity\n";
    std::cout << "[Any] Back\n\n";
    std::cout << "Select: ";
    std::cin >> choice;

    if (choice == '1') {
        std::cout << "\nNew name: ";
        std::cin >> productName;
        database.productNamesVector[productIndex] = productName;
        std::cout << "\033[2J\033[H";
        std::cout << "Edited\n\n";
    } else if (choice == '2') {
        std::cout << "\nNew price: ";
        std::cin >> productPrice;
        database.productPricesVector[productIndex] = productPrice;
        std::cout << "\033[2J\033[H";
        std::cout << "Edited\n\n";
    } else if (choice == '3') {
        std::cout << "\nNew quantity: ";
        std::cin >> productQuantity;
        database.productQuantitiesVector[productIndex] = productQuantity;
        std::cout << "\033[2J\033[H";
        std::cout << "Edited\n\n";
    } else {
        std::cout << "\033[2J\033[H";
    }
}
