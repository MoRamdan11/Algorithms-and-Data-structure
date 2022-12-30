#ifndef _TRUST_ACCOUNT_H
#define _TRUST_ACCOUNT_H
#include "Saving_Account.h"
#include <string>
using std::string;

class Trust_Account : public Saving_Account{
friend std::ostream &operator <<(std::ostream &os, const Trust_Account &rhs);
private:
  static constexpr const char* def_name = "Unamed Trust Account";
  static constexpr const double def_balance = 0;
  static constexpr const int def_interest_rate = 0;
  static constexpr const int def_num_of_withdraws = 0;
  static constexpr const double bonus_amount = 50;
  static constexpr const double bonus_threshold = 5000;
  static constexpr const int max_withdraws = 3;
protected:
  int num_of_withdraws;
public:
  Trust_Account(string name=def_name, double balance=def_balance, int interest_rate=def_interest_rate);
  ~Trust_Account();
  bool deposit(double amount);
  bool withdraw(double amount);
};


#endif