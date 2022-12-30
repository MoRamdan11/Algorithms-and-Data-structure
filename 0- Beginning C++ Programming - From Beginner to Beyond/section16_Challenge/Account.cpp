#include "Account.h"

Account::Account(string name, double balance) 
    : name{name}, balance{balance} {}

Account::Account(const Account &source)
    : name{source.name}, balance{source.balance} {}

Account &Account::operator =(const Account &rhs) {
    if(this == &rhs)
        return *this;
    this->name = rhs.name;
    this->balance = rhs.balance;
    return *this;
}   

bool Account::deposit(double amount) {
    if(amount <= 0)
        return false;
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if(balance < amount)
        return false;
    balance -= amount;
    return true;
}

double Account::get_balance() const {
    return balance;
}

void Account::print(std::ostream &os) const {
    os << "[Account: " << name << ", balance: " << balance << "]" << endl;
}