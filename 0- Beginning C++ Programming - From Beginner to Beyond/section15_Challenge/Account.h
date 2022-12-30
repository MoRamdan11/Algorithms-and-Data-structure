#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
using std::string;

class Account {
friend std::ostream &operator <<(std::ostream &os, const Account &rhs);
private:
  static constexpr const char* def_name = {"Unamed Account"};
  static constexpr const double def_balance = 0;
protected:
  string name;
  double balance;
public:
  // Account();
  Account(string name=def_name, double balacne=def_balance);
  ~Account();
  Account(const Account &source);
  Account &operator =(const Account &rhs);
  bool withdraw(double amount);
  bool deposit(double amount);
};

#endif