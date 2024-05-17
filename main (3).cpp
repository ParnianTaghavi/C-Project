#include "menu.h"

int main() {
    Menu menu;
    User user;
    int choice;

    do {
        choice = menu.showMenu();

        switch (choice) {
            case 1:
                menu.registerUser();
                break;
            case 2: {
                std::string ID;
                std::cout << "Enter your ID: ";
                std::cin >> ID;
                std::cin.ignore();

                User* foundUser = menu.findPerson(ID);
                if (foundUser != nullptr) {
                    foundUser->display();
                } else {
                    std::cout << "User not found." << std::endl;
                }
                break;
            }
            case 3:
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (choice != 3);

    return 0;
}