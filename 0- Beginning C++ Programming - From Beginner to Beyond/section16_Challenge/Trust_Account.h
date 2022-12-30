#ifndef _TRUST_ACCOUNT_H
#define _TRUST_ACCOUNT_H
#include "Saving_Account.h"

class Trust_Account : public Saving_Account {
private:
    static constexpr const char* def_name = "Unnamed Trust Account";
    static constexpr const double def_balance = 0.0;
    static constexpr const double def_interest_rate = 0.0;
    static constexpr const double def_threshold_deposit_bonus = 5000.0;
    static constexpr const double def_bonus_amount = 50.00;
    static constexpr const int max_allowed_withdrawals = 3;
    static constexpr const int def_num_of_withdrawals = 0;
protected:  
    int num_of_withdrawals; 
public:
    Trust_Account(string name=def_name, double balance=def_balance, double interest_rate=def_interest_rate, int num_of_withdrawals=def_num_of_withdrawals);
    virtual ~Trust_Account() = default;
    Trust_Account(const Trust_Account &source);
    Trust_Account &operator =(const Trust_Account &rhs);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
};

#endif