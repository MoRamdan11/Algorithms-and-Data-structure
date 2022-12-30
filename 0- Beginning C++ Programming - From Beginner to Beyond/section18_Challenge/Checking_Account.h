#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"

class Checking_Account : public Account {
private:
  static constexpr const char* def_name = "Unnamed Account";
  static constexpr const double def_balance = 0.0;
  static constexpr const double fee = 1.5;
public:
  Checking_Account(string name=def_name, double balance=def_balance);
  virtual ~Checking_Account();
  Checking_Account(const Checking_Account &rhs);
  void print(std::ostream &os) const override;
  void withdraw(double amount) override;
  void deposit(double amount) override;
};


#endif