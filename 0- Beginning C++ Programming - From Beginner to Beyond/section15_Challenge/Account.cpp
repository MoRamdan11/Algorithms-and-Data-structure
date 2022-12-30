#include "Account.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

Account::Account(string name, double balance)
  : name{name}, balance{balance} {
}
// Account::Account()
//   : Account{"NoName", 0} {
// }
Account::Account(const Account &source)
  : Account{source.name, source.balance} {
}
Account::~Account() {
}
Account &Account::operator =(const Account &rhs) {
  if(this == &rhs)
    return *this;
  this->name = rhs.name;
  this->balance = rhs.balance;
  return *this;
}
bool Account::withdraw(double amount) {
  if(balance < amount)
    return false;
  balance -= amount;
  return true;
}
bool Account::deposit(double amount) {
  if(amount <= 0)
    return false;
  balance += amount;
  return true;
}
std::ostream &operator <<(std::ostream &os, const Account &rhs) {
  os << "[Account: \"" << rhs.name << "\", balance: " 
    << rhs.balance << "]" << endl;
  return os;
}