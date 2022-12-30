#ifndef _ACCOUNT_UTILITI_H_
#define _ACCOUNT_UTILITI_H_

#include <memory>
#include <iostream>
#include <vector>
#include "Account.h"
#include "Saving_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
using std::cout;
using std::endl;
void display(std::vector<std::shared_ptr<Account>> accounts);
void deposit(std::vector<std::shared_ptr<Account>> accounts, double amount);
void withdraw(std::vector<std::shared_ptr<Account>> accounts, double amount);
#endif