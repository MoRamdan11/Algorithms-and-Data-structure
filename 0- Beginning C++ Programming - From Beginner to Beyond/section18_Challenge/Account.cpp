#include "Account.h"

Account::Account(string name, double balance) 
  : name{name}, balance{balance} {
    if(balance < 0.0)
      throw IllegalBalanceException();
}

Account::~Account()=default;

Account::Account(const Account &source)
  : Account{source.name, source.balance} {}
void Account::print(std::ostream &os) const {
  os << "Account [\"" << name << "\", balance: " << balance << "]" << endl;
}

void Account::withdraw(double amount) {
  if(balance < amount) 
    throw IllegalSufficientFund();
  balance -= amount;
}

void Account::deposit(double amount) {
  if(amount < 0) 
    throw IllegalSufficientFund();
  balance += amount;
}