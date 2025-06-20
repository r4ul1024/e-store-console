#include "purchase.h"
#include "database.h"

#include <iostream>

void Purchase::menu(Database& database)
{
    purchaseLoop = true;

    while (purchaseLoop) {
        std::cout << "~~ Purchase ~~\n\n";
        std::cout << "[1] Products\n";
        std::cout << "[2] Sign out\n\n";
        std::cout << "Select: ";
        std::cin >> choice;

        if (choice == '1') {
            std::cout << "\033[2J\033[H";
            Purchase::products(database);
        } else if (choice == '2') {
            purchaseLoop = false;
            std::cout << "\033[2J\033[H";
        } else {
            std::cout << "\033[2J\033[H";
        }
    }
}

void Purchase::products(Database& database)
{
    std::cout << "~~ Products ~~\n\n";
    for (int i = 0; i < database.productNamesVector.size(); i++) {
        std::cout << i << "." << database.productNamesVector[i] << " | Price: " << database.productPricesVector[i] << "$ | " << database.productQuantitiesVector[i] << " Units\n";
    }
    std::cout << "\nProduct index: ";
    std::cin >> productIndex;

    if (productIndex >= 0 && productIndex < database.productNamesVector.size()) {
        std::cout << "Quantity: ";
        std::cin >> quantity;

        if (database.productQuantitiesVector[productIndex] - quantity >= 0) {
            std::cout << "\033[2J\033[H";
            Purchase::order(database);
        } else {
            std::cout << "\033[2J\033[H";
            std::cout << "That quantity is not available\n\n";
        }
    } else {
        std::cout << "\033[2J\033[H";
        std::cout << "Invalid index\n\n";
    }
}

void Purchase::order(Database& database)
{
    totalPrice = database.productPricesVector[productIndex] * quantity;
    std::cout << "~~ Order ~~\n\n";
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Address: ";
    std::cin >> address;
    std::cout << "Phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Card number: ";
    std::cin >> cardNumber;
    std::cout << "Card expiry date: ";
    std::cin >> expiryDate;
    std::cout << "CVV/CVC: ";
    std::cin >> cvv;

    std::cout << "\nTotal price: " << totalPrice << "$\n\n";
    std::cout << "[1] Confrim order\n";
    std::cout << "[Any] Cancel\n\n";
    std::cout << "Select: ";
    std::cin >> choice;

    if (choice == '1') {
        database.productQuantitiesVector[productIndex] -= quantity;
        std::cout << "\033[2J\033[H";
        std::cout << "Order completed\n\n";
    } else {
        std::cout << "\033[2J\033[H";
    }
}
