#ifndef _CHECKING_ACCOUNT_H
#define _CHECKING_ACCOUNT_H
#include "Account.h"
#include <string>
using std::string;
/*
1. Add a Checking account class to the Account hierarchy
A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
Every withdrawal transaction will be assessed this flat fee.
*/
class Checking_Account : public Account{
friend std::ostream &operator <<(std::ostream &os, const Checking_Account &rhs);
private:
  static constexpr const char* def_name = "NoName";
  static constexpr const double def_balance = 0;
  static constexpr const double fee = 1.5;
protected:
  //double fee = 1.5;
public:
  Checking_Account(string name=def_name, double balance=def_balance);
  ~Checking_Account();
  Checking_Account(const Checking_Account &source);
  bool withdraw(double amount);
};


#endif