#include "Trust_Account.h"

Trust_Account::Trust_Account(string name, double balance, double interest_rate)
  : Saving_Account{name, balance, interest_rate}, num_of_withdrawls{0} {}

Trust_Account::~Trust_Account()=default;

Trust_Account::Trust_Account(const Trust_Account &source)
  : Saving_Account(source) {}

void Trust_Account::print(std::ostream &os) const {
  os << "Trust_Account [\"" << name << "\", balance: " <<
    balance << ", interest rate: " << interest_rate << "%]" << endl;
}

void Trust_Account::withdraw(double amount) {
  if(num_of_withdrawls >= max_num_of_withdrawls)
    throw MaxNumberOfWithdrwals();
  Saving_Account::withdraw(amount);
  num_of_withdrawls++;
}
void Trust_Account::deposit(double amount) {
  if(amount >= bonus_threshold)
    amount += bonus_amount;
  return Saving_Account::deposit(amount);
}