#include "Checking_Account.h"

Checking_Account::Checking_Account(string name, double balance) 
  : Account{name, balance} {}

Checking_Account::~Checking_Account()=default;

Checking_Account::Checking_Account(const Checking_Account &source)
  : Checking_Account{source.name, source.balance} {}

void Checking_Account::print(std::ostream &os) const {
  os << "Checking_Account [\"" << name << "\", balance: " <<
    balance << ", Fee: " << fee << "]" << endl;
}

void Checking_Account::withdraw(double amount) {
  amount += amount + fee;
  return Account::withdraw(amount);
}

void Checking_Account::deposit(double amount) {
  return Account::deposit(amount);
}