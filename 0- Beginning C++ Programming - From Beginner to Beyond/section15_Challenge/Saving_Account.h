#ifndef _SAVING_ACCOUNT_H
#define _SAVING_ACCOUNT_H
#include "Account.h"

class Saving_Account : public Account {
friend std::ostream &operator <<(std::ostream &os, const Saving_Account &rhs);
private:
  static constexpr const char* def_name = "Unamed Saving Account";
  static constexpr const double def_balance = 0;
  static constexpr const int def_interest_rate = 0;
protected:
  int interest_rate;
public:
  // Saving_Account();
  Saving_Account(string name=def_name, double balance=def_balance, int interest_rate=def_interest_rate);
  ~Saving_Account();
  Saving_Account(const Saving_Account &source);
  Saving_Account &operator=(const Saving_Account &rhs);
  bool deposit(double amount);
};

#endif