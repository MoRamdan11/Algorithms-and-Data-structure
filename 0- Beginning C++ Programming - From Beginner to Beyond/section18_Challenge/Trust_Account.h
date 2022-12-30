#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Saving_Account.h"
#include "Exceptions/MaxNumberOfWithdrwals.h"

class Trust_Account : public Saving_Account {
private:
  static constexpr const char *def_name = "Unnamed Saving Account";
  static constexpr const double def_balance = 0.0;
  static constexpr const double def_interest_rate = 0.0;
  static constexpr const double bonus_threshold = 5000;
  static constexpr const double bonus_amount = 50;
  static constexpr const int max_num_of_withdrawls = 3;
protected:
  int num_of_withdrawls;
public:
  Trust_Account(string name=def_name, double balance=def_balance, double interest_rate=def_interest_rate);
  virtual ~Trust_Account();
  Trust_Account(const Trust_Account &source);
  virtual void print(std::ostream &os) const;
  virtual void withdraw(double amount) override;
  virtual void deposit(double amount) override;
};

#endif