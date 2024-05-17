#include "Transaction.h"

Transaction::Transaction(std::string currency, double amount, std::string type)
    : currency(std::move(currency)), amount(amount), type(std::move(type)) {}//move??

std::string Transaction::getCurrency() const {
    return currency;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getType() const {
    return type;
}