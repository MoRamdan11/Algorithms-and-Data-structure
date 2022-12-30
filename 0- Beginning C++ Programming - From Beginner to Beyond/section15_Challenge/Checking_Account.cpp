#include "Checking_Account.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

Checking_Account::Checking_Account(string name, double balance)
  : Account{name, balance} {}

Checking_Account::~Checking_Account() {}

Checking_Account::Checking_Account(const Checking_Account &source)
  : Account(source) {}

bool Checking_Account::withdraw(double amount) {
  if(amount + fee <= balance && Account::withdraw(amount)) {
    balance -= fee;
    return true;
  } else
    return false;
}
std::ostream &operator <<(std::ostream &os, const Checking_Account &rhs) {
  os << "[Account: \"" << rhs.name << "\", balance: " 
    << rhs.balance << ", Fee: $" << rhs.fee << "]" << endl;
  return os;
}