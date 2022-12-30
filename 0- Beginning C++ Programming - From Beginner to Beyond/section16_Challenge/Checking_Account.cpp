#include "Checking_Account.h"
Checking_Account::Checking_Account(string name, double balance)
    : Account{name, balance}, fee{def_fee} {}


Checking_Account::Checking_Account(const Checking_Account &source)
    : Account{source}, fee{source.fee} {}

Checking_Account &Checking_Account::operator =(const Checking_Account &rhs) {
    if(this == &rhs)
        return *this;
    Account::operator=(rhs);
    this->fee = rhs.fee;
    return *this;
}

bool Checking_Account::withdraw(double amount) {
    amount += fee;
    return (Account::withdraw(amount));
}

bool Checking_Account::deposit(double amount) {
    return (Account::deposit(amount));
}
void Checking_Account::print(std::ostream &os) const {
     os << "[Checking_Account: " << name << ", balance: " << balance
        << ", fee: " << fee <<"]" << endl;
}

