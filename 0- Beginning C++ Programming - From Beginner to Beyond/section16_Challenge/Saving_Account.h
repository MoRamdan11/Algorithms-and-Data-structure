#ifndef _SAVING_ACCOUNT_H
#define _SAVING_ACCOUNT_H
#include "Account.h"

class Saving_Account : public Account {
private:
    static constexpr const char* def_name = "Unnamed Saving_Account";
    static constexpr const double def_balance = 0.0;
    static constexpr const double def_interest_rate = 0.0;
protected:
    double interest_rate;
public:
    Saving_Account(string name = def_name, double balance = def_balance, double interest_rate = def_interest_rate);
    virtual ~Saving_Account() = default;
    Saving_Account(const Saving_Account &source);
    Saving_Account &operator =(const Saving_Account &rhs);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
};

#endif