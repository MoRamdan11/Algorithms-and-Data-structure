#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include "I_Printable.h"
#include "Exceptions/IllegalBalanceException.h"
#include "Exceptions/IllegalSufficientFund.h"
using std::string;
using std::endl;

class Account : public I_Printable {
private:
  static constexpr const char* def_name = "Unnamed Account";
  static constexpr const double def_balance = 0.0;
protected:
  string name;
  double balance;
public:
  Account(string name=def_name, double balance=def_balance);
  virtual ~Account();
  Account(const Account &source);
  virtual void print(std::ostream &os) const override = 0;
  virtual void withdraw(double amount) = 0;
  virtual void deposit(double amount) = 0;
};

#endif