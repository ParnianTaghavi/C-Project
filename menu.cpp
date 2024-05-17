#include "menu.h"
#include "user.cpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Menu::displayMenu() {
    std::cout << "Welcome to the Menu!" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "1. Register" << std::endl;
    std::cout << "2. Login" << std::endl;
}

int Menu::showMenu() {
    displayMenu();
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();
    return choice;
}

void Menu::registerUser() {
    User user;
    user.setFirstName();
    user.setLastName();
    user.setPhoneNumber();
    user.setEmail();
    user.setPassword();
    user.setNationalCode();
    user.setID();

    user.saveToFile();
}

User* Menu::findPerson(const std::string& ID) {
    std::ifstream inFile("users.txt");
    if (inFile.is_open()) {
        std::string line;
        while (getline(inFile, line)) {
            std::stringstream ss(line);

            // Read all values into variables
            std::string savedFirstName, savedLastName, savedPhoneNumber, savedEmail, savedPassword, savedNationalCode, savedID;
            getline(ss, savedFirstName, ',');
            getline(ss, savedLastName, ',');
            getline(ss, savedPhoneNumber, ',');
            getline(ss, savedEmail, ',');
            getline(ss, savedPassword, ',');
            getline(ss, savedNationalCode, ',');
            getline(ss, savedID, ',');

            if (savedID == ID) {
                User* user = new User(savedFirstName, savedLastName, savedPhoneNumber, savedEmail,
                                      savedPassword, savedNationalCode, savedID);
                inFile.close();
                return user;
            }
        }

        inFile.close();
    } else {
        std::cout << "Error: Unable to open file for reading." << std::endl;
    }

    return nullptr;
}