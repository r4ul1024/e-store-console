#include "account.h"
#include "admin_panel.h"
#include "database.h"
#include "purchase.h"

#include <iostream>

void Account::main(Database& database, Purchase& purchase, Admin& admin)
{
    programLoop = true;

    while (programLoop) {
        std::cout << "### E-Store ###\n\n";
        std::cout << "[1] Buyer\n";
        std::cout << "[2] Admin\n";
        std::cout << "[3] Exit\n\n";
        std::cout << "Select: ";
        std::cin >> choice;

        if (choice == '1') {
            std::cout << "\n[1] Sign in\n";
            std::cout << "[2] Sign up\n";
            std::cout << "[Any] Back\n\n";
            std::cout << "Select: ";
            std::cin >> choice;

            if (choice == '1') {
                std::cout << "\033[2J\033[H";
                std::cout << "~~ Sign in ~~ \n\n";
                std::cout << "Username: ";
                std::cin >> username;
                std::cout << "Password: ";
                std::cin >> password;

                result = sign_in(database);

                if (result == true) {
                    std::cout << "\033[2J\033[H";
                    purchase.menu(database);
                } else {
                    std::cout << "\033[2J\033[H";
                    std::cout << "Username or password is incorrect\n\n";
                }

            } else if (choice == '2') {
                std::cout << "\033[2J\033[H";
                std::cout << "~~ Sign up ~~ \n\n";
                std::cout << "Username: ";
                std::cin >> username;
                std::cout << "Password: ";
                std::cin >> password;
                std::cout << "Repeat password: ";
                std::cin >> rePassword;

                if (password == rePassword) {
                    result = sign_up(database);

                    if (result == true) {
                        std::cout << "\033[2J\033[H";
                        std::cout << "Registration successful. Please sign in\n\n";
                        Account::main(database, purchase, admin);
                    } else {
                        std::cout << "\033[2J\033[H";
                        std::cout << "Username is already taken\n\n";
                    }
                } else {
                    std::cout << "\033[2J\033[H";
                    std::cout << "Passwords do not match\n\n";
                }
            } else {
                std::cout << "\033[2J\033[H";
            }
        } else if (choice == '2') {
            std::cout << "\033[2J\033[H";
            std::cout << "~~ Admin sign in ~~ \n\n";
            std::cout << "Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;

            result = admin_sign_in(database);

            if (result == true) {
                std::cout << "\033[2J\033[H";
                admin.menu(database);
            } else {
                std::cout << "\033[2J\033[H";
                std::cout << "Username or password is incorrect\n\n";
            }
        } else if (choice == '3') {
            programLoop = false;
        } else {
            std::cout << "\033[2J\033[H";
        }
    }
}

bool Account::sign_in(Database& database)
{
    for (int i = 0; i < database.usernamesVector.size(); i++) {
        if (username == database.usernamesVector[i] && password == database.passwordsVector[i]) {
            return true;
        }
    }
    return false;
}

bool Account::sign_up(Database& database)
{
    for (int i = 0; i < database.usernamesVector.size(); i++) {
        if (username == database.usernamesVector[i]) {
            return false;
        }
    }
    database.usernamesVector.push_back(username);
    database.passwordsVector.push_back(password);
    return true;
}

bool Account::admin_sign_in(Database& database)
{
    if (username == database.adminUsername && password == database.adminPassword) {
        return true;
    } else {
        return false;
    }
}
