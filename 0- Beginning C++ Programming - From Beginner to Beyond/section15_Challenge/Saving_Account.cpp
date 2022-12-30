#include "Saving_Account.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

Saving_Account::Saving_Account(string name, double balance, int interest_rate)
  : Account{name, balance}, interest_rate{interest_rate} {
}
// Saving_Account::Saving_Account()
//   : Account{}, increase_rate{0} {
// }
Saving_Account::~Saving_Account() {
}
Saving_Account::Saving_Account(const Saving_Account &source)
  : Account(source), interest_rate{source.interest_rate} {
}
Saving_Account &Saving_Account::operator=(const Saving_Account &rhs) {
  if(this == &rhs)
    return *this;
  Account::operator=(rhs);
  this->interest_rate = rhs.interest_rate;
  return *this;
}
bool Saving_Account::deposit(double amount) {
  amount += amount * (static_cast<float>(interest_rate) / 100);
  return Account::deposit(amount);
}

std::ostream &operator <<(std::ostream &os, const Saving_Account &rhs) {
  os << "[Saving Account: \"" << rhs.name << "\", balance: " 
    << rhs.balance << ", Increase rate: " << rhs.interest_rate << "%]" << endl;
  return os;
}