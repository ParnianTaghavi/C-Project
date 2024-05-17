#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Bank.h"

int main() {
    Bank bank;
    int choice;
    std::string currency;
    double amount;

    while (true) {
        std::cout << "1. Create wallet\n2. Increase balance\n3. Display transactions\n4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        try {
            switch (choice) {
                case 1:
                    std::cout << "Enter currency: ";
                    std::cin >> currency;
                    bank.createUserWallet(currency);
                    break;
                case 2:
                    std::cout << "Enter currency: ";
                    std::cin >> currency;
                    std::cout << "Enter amount: ";
                    std::cin >> amount;

                    if (std::cin.fail()) {
                        throw std::runtime_error("Invalid amount! Please enter a numeric value.");
                    }

                    bank.increaseBalance(currency, amount);
                    break;
                case 3:
                    std::cout << "Enter currency: ";
                    std::cin >> currency;
                    bank.displayTransactions(currency);
                    break;
                case 4:
                    std::cout << "Exiting..." << std::endl;
                    return 0;
                default:
                    std::cout << "Invalid choice! Please try again." << std::endl;
                    break;
            }
        } catch (const std::runtime_error& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << std::endl;
    }

    system("pause");
    return 0;
}