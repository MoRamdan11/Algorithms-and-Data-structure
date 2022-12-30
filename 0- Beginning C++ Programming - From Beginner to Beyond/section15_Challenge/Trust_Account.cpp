#include "Trust_Account.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

Trust_Account::Trust_Account(string name, double balance, int interest_rate) 
  : Saving_Account{name, balance, interest_rate}, num_of_withdraws{0} {
}

Trust_Account::~Trust_Account(){}

bool Trust_Account::deposit(double amount) {
  if(Saving_Account::deposit(amount)) {
    if(amount >= bonus_threshold)
      balance += bonus_amount;
    return true;
  } else
    return false;
}

bool Trust_Account::withdraw(double amount) {
  if(num_of_withdraws > max_withdraws || amount > 0.2 * balance || !Saving_Account::withdraw(amount))
    return false;
  num_of_withdraws++;
  return true;
}

std::ostream &operator <<(std::ostream &os, const Trust_Account &rhs) {
  os << "[Saving Account: \"" << rhs.name << "\", balance: " 
    << rhs.balance << ", Increase rate: " << rhs.interest_rate 
    << "%, Max_number_withdraws: " << rhs.num_of_withdraws << "]" << endl;
  return os;
}