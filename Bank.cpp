#include "Bank.h"
#include <iostream>

Bank::Bank() {}

Bank::~Bank() {
    for (Wallet* wallet : wallets) {
        delete wallet;
    }
}

void Bank::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

void Bank::createUserWallet(const string& currency) {
    for (const Wallet* wallet : wallets) {
        if (wallet->getCurrency() == currency) {
            throw runtime_error("You already have a wallet with currency: " + currency);
        }
    }

    Wallet* newWallet = new Wallet(currency);
    wallets.push_back(newWallet);
    cout << "Wallet created with currency: " << currency << std::endl;
}

void Bank::increaseBalance(const std::string& currency, double amount) {
    Wallet* wallet = findWallet(currency);
    if (wallet) {//???
        wallet->increaseBalance(amount);
        addTransaction(Transaction(currency, amount, "Deposit"));
    } else {
        throw std::runtime_error("Wallet for currency '" + currency + "' not found!");
    }
}

void Bank::displayTransactions(const std::string& currency) const {
    Wallet* wallet = findWallet(currency);
    if (wallet == nullptr) {
        throw std::runtime_error("You need to create a wallet first!");
    }
    wallet->displayTransactions();
}

Wallet* Bank::findWallet(const std::string& currency) const {
    for (Wallet* wallet : wallets) {
        if (wallet->getCurrency() == currency) {
            return wallet;
        }
    }
    return nullptr;
}