#include "Trust_Account.h"

Trust_Account::Trust_Account(string name, double balance, double interest_rate, int num_of_withdrawals)
    : Saving_Account{name, balance, interest_rate}, num_of_withdrawals{num_of_withdrawals} {}

Trust_Account::Trust_Account(const Trust_Account &source)
    : Saving_Account(source), num_of_withdrawals{source.num_of_withdrawals} {}

Trust_Account &Trust_Account::operator =(const Trust_Account &rhs) {
    if(this == &rhs)
        return *this;
    Saving_Account::operator=(rhs);
    this->num_of_withdrawals = rhs.num_of_withdrawals;
    return *this;
}

bool Trust_Account::deposit(double amount) {
    if(amount >= def_threshold_deposit_bonus)
        amount += def_bonus_amount;
    return (Saving_Account::deposit(amount));
}

bool Trust_Account::withdraw(double amount) {
    if(num_of_withdrawals < max_allowed_withdrawals && amount < (balance * 0.2) ) {
        num_of_withdrawals++;
        return Saving_Account::withdraw(amount);
    } else
        return false;
}

void Trust_Account::print(std::ostream &os) const {
    os << "[Trust_Account: " << name <<
        ", balance: " << balance <<
        ", interest_rate: " << interest_rate << "%, num_of_withdrawals: " <<
        num_of_withdrawals << "]" << endl;
}