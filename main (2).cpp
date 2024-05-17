#include "bank.h"
#include <iostream>

int main() {
    Bank bank("user_data.txt");
    bank.loadFromFile();

    int choice;

    do {
        std::cout << "\nWelcome to the Online Bank!\n";
        std::cout << "1. Sign Up\n";
        std::cout << "2. Login\n";
        std::cout << "3. Save User Information\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                bank.signUp();
                break;
            case 2:
                bank.login();
                break;
            case 3:
                bank.saveToFile();
                break;
            case 4:
                std::cout << "Exiting the program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}