#include "purchase.h"
#include "database.h"

#include <algorithm>
#include <iostream>

void Purchase::main(Database& database)
{
    purchaseLoop = true;

    while (purchaseLoop) {
        std::cout << "### Purchase ###\n\n";
        for (int i = 0; i < database.productNamesVector.size(); i++) {
            std::cout << i << "." << database.productNamesVector[i] << " | Price: " << database.productPricesVector[i] << "$ | " << database.productQuantitiesVector[i] << " Units\n";
        }
        std::cout << "\n[1] Select product\n";
        std::cout << "[2] Cart\n";
        std::cout << "[3] Sign out\n\n";
        std::cout << "Select: ";
        std::cin >> choice;

        if (choice == '1') {
            std::cout << "\nProduct index: ";
            std::cin >> productIndex;

            if (productIndex >= 0 && productIndex < database.productNamesVector.size()) {
                std::cout << "\n[1] Add to cart\n";
                std::cout << "[Any] Back\n\n";
                std::cout << "Select: ";
                std::cin >> choice;

                if (choice == '1') {
                    std::cout << "\nQuantity: ";
                    std::cin >> productQuantity; // Нужно прилумать логику вычитания товара про добавлениив корзину.Еще сделать очистку кор
                    if (database.productQuantitiesVector[productIndex] - productQuantity >= 0) {
                        database.productQuantitiesVector[productIndex] -= productQuantity;
                        database.cartProductNamesVector.push_back(database.productNamesVector[productIndex]);
                        database.cartProductPricesVector.push_back(database.productPricesVector[productIndex]);
                        database.cartProductQuantitiesVector.push_back(productQuantity);
                        database.totalPrice += database.productPricesVector[productIndex] * productQuantity;
                        database.productIndexesVector.push_back(productIndex);
                        std::cout << "\033[2J\033[H";
                        std::cout << "Added to cart\n\n";
                    } else {
                        std::cout << "\033[2J\033[H";
                        std::cout << "* That quantity is not available *\n\n";
                    }
                } else {
                    std::cout << "\033[2J\033[H";
                }
            } else {
                std::cout << "\033[2J\033[H";
            }

        } else if (choice == '2') {
            std::cout << "\033[2J\033[H";
            Purchase::cart(database);
        } else if (choice == '3') {
            purchaseLoop = false;
            std::cout << "\033[2J\033[H";
        } else {
            std::cout << "\033[2J\033[H";
        }
    }
}

void Purchase::cart(Database& database)
{
    std::cout << "### Cart ###\n\n";
    if (database.cartProductNamesVector.size() == 0) {
        std::cout << "\033[2J\033[H";
        std::cout << "--- Cart is empty ---\n\n";
    } else {
        for (int i = 0; i < database.cartProductNamesVector.size(); i++) {
            std::cout << i << "." << database.cartProductNamesVector[i] << " | Price: " << database.cartProductPricesVector[i] << "$ | " << database.cartProductQuantitiesVector[i] << " Units\n";
        }
        std::cout << "\nTotal price: " << database.totalPrice << "$\n\n";
        std::cout << "[1] Order\n";
        std::cout << "[2] Clear cart\n";
        std::cout << "[Any] Back\n\n";
        std::cout << "Select: ";
        std::cin >> choice;

        if (choice == '1') {
            std::cout << "\033[2J\033[H";
            Purchase::order(database);
        } else if (choice == '2') {
            for (int i = 0; i < database.cartProductNamesVector.size(); i++) {
                for (int j = 0; j < database.productNamesVector.size(); j++) {
                    if (j == database.productIndexesVector[i]) {
                        database.productQuantitiesVector[j] += database.cartProductQuantitiesVector[i];
                    }
                }
            }
            database.cartProductNamesVector.clear();
            database.cartProductPricesVector.clear();
            database.cartProductQuantitiesVector.clear();
            database.totalPrice = 0;
            database.productIndexesVector.clear();
            std::cout << "\033[2J\033[H";
        } else {
            std::cout << "\033[2J\033[H";
        }
    }
}

void Purchase::order(Database& database)
{
    std::cout << "### Order ###\n\n";
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

    std::cout << "\nTotal price: " << database.totalPrice << "$\n\n";
    std::cout << "[1] Confrim order\n";
    std::cout << "[Any] Cancel\n\n";
    std::cout << "Select: ";
    std::cin >> choice;

    if (choice == '1') {
        std::cout << "\033[2J\033[H";
        database.cartProductNamesVector.clear();
        database.cartProductPricesVector.clear();
        database.cartProductQuantitiesVector.clear();
        database.totalPrice = 0;
        database.productIndexesVector.clear();
        std::cout << "Order completed\n\n";
    } else {
        std::cout << "\033[2J\033[H";
    }
}
