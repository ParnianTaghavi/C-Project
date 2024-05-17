#include "bank.h"
#include <iostream>
#include <fstream>
#include <regex>

Bank::Bank(const std::string& fileName) : fileName(fileName) {}

void Bank::signUp() {
    std::string name, email, accountNumber, password, phoneNumber;

    std::cout << "Enter your name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    do {
        std::cout << "Enter your email: ";
        std::cin >> email;
    } while (!isValidEmail(email));

    std::cout << "Enter your account number: ";
    std::cin >> accountNumber;

    do {
        std::cout << "Create a password: ";
        std::cin >> password;
    } while (!isValidPassword(password));

    do {
        std::cout << "Enter your phone number: ";
        std::cin >> phoneNumber;
    } while (!isValidPhoneNumber(phoneNumber));

    User newUser(name, email, accountNumber, password, phoneNumber, 0.0);
    users.push_back(newUser);

    std::cout << "Sign up successful. Please log in to continue.\n";
}

void Bank::login() {
    std::string email, password;

    std::cout << "Enter your email: ";
    std::cin >> email;

    std::cout << "Enter your password: ";
    std::cin >> password;

    for (auto& user : users) {
        if (user.validateCredentials(email, password)) {
            user.displayMenu();
            return;
        }
    }

    std::cout << "Invalid email or password. Please try again.\n";
}

bool Bank::isValidEmail(const std::string& email) {
    // Basic email validation using regular expression
    std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if (!std::regex_match(email, pattern)) {
        std::cout << "Invalid email. Please enter a valid email address.\n";
        return false;
    }
    return true;
}

bool Bank::isValidPassword(const std::string& password) {
    // Password should have at least 8 characters
    if (password.length() < 8) {
        std::cout << "Invalid password. Password should have at least 8 characters.\n";
        return false;
    }
    return true;
}

bool Bank::isValidPhoneNumber(const std::string& phoneNumber) {
    // Basic phone number validation using regular expression
    std::regex pattern("\\d{10}");  // 10-digit phone number
    if (!std::regex_match(phoneNumber, pattern)) {
        std::cout << "Invalid phone number. Please enter a 10-digit phone number.\n";
        return false;
    }
    return true;
}

void Bank::saveToFile() {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file.\n";
        return;
    }

    file << users.size() << std::endl;
    for (const auto& user : users) {
        user.saveToFile(file);
    }

    file.close();
    std::cout << "User information saved to file: " << fileName << std::endl;
}

void Bank::loadFromFile() {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Error: Unable to open file.\n";
        return;
    }

    users.clear();
    int numUsers;
    file >> numUsers;

    std::string name, email, accountNumber, password, phoneNumber;
    double balance;
    int numTransactions;
    std::string transaction;

    for (int i = 0; i < numUsers; ++i) {
        file.ignore();
        std::getline(file, name);
        file >> email >> accountNumber >> password >> phoneNumber >> balance >> numTransactions;
        User loadedUser(name, email, accountNumber, password, phoneNumber, balance);
        for (int j = 0; j < numTransactions; ++j) {
            file.ignore();
            std::getline(file, transaction);
            loadedUser.addTransaction(transaction);
        }
        users.push_back(loadedUser);
    }

    file.close();
    std::cout << "User information loaded from file: " << fileName << std::endl;
}