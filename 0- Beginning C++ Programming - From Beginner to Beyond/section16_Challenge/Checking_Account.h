#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"
class Checking_Account : public Account {
private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr const double def_balance = 0.0;
    static constexpr const double def_fee = 1.5;
protected:
    double fee;
public:
    Checking_Account(string name=def_name, double balance=def_balance);
    virtual ~Checking_Account() = default;
    Checking_Account(const Checking_Account &source);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    Checking_Account &operator =(const Checking_Account &rhs);
    virtual void print(std::ostream &os) const override;
};

#endif