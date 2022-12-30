#include "Saving_Account.h"
Saving_Account::Saving_Account(string name, double balance, double interest_rate)
  : Account{name, balance}, interest_rate{interest_rate} {}

Saving_Account::~Saving_Account()=default;

Saving_Account::Saving_Account(const Saving_Account &source)
  : Account(source), interest_rate{source.interest_rate} {}

void Saving_Account::print(std::ostream &os) const {
  os << "Saving_Account [\"" << name << "\", balance: " <<
    balance << ", interest rate: " << interest_rate << "%]" << endl;
}

void Saving_Account::withdraw(double amount) {
  return Account::withdraw(amount);
}

void Saving_Account::deposit(double amount) {
  amount += amount * (interest_rate / 100);
  return Account::deposit(amount);
}