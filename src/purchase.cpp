#include "purchase.h"
#include "database.h"

#include <iostream>

void Purchase::menu(Database& database)
{
    std::cout << "[1] Products\n";
    std::cout << "[2] Sign out\n\n";
    std::cout << "Select: ";
    std::cin >> choice;

    if (choice == '1') {
        std::cout << "\033[2J\033[H";
        Purchase::products(database);
    } else if (choice == '2') {
        std::cout << "\033[2J\033[H";
    }
}

void Purchase::products(Database& database)
{
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
            std::cout << "net takoqo v nalicii";
        }
    } else {
        std::cout << "vvedi pravilniy index";
    }
}

void Purchase::order(Database& database)
{
    totalPrice = database.productPricesVector[productIndex] * quantity;
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
    std::cout << cvv;

    std::cout << "totalPrice: " << totalPrice << "$ podtverdit?\n";
    std::cout << "[1] order\n";
    std::cout << "[2] menu\n";
    std::cout << "select:?";
    std::cin >> choice;

    if (choice == '1') {
        database.productQuantitiesVector[productIndex] -= quantity;
        std::cout << "order oformlen";
        database.totalPrice -= totalPrice;
        database.totalPrice = 0;

    } else {
        database.totalPrice = 0;
    }
}
