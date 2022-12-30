#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "I_Printable.h"
#include <string>
#include <iostream>
using std::string;
using std::endl;
using std::cout;

class Account : public I_Printable{
private:
    static constexpr const char* def_name = "UnnamedAccount";
    static constexpr const double def_balance = 0.0;
protected:
    string name;
    double balance;
public:
    Account(string name = def_name, double balance = def_balance);
    virtual ~Account() = default;
    Account(const Account &source);
    Account &operator =(const Account &rhs);
    // Account Class => Abstract Class
    virtual bool deposit(double amount) = 0;   //Pure Virtual Function
    virtual bool withdraw(double amount) = 0;  //Pure Virtual Function
    double get_balance() const;
    virtual void print(std::ostream &os) const override;
};

#endif