#ifndef _ACCOUNTS_UTLITI_
#define _ACCOUNTS_UTLITI_

#include <vector>
#include "Account.h"
#include "Saving_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

void display(const vector<Account *> &accounts);
void withdraw(vector<Account *> &accounts, double amount);
void deposit(vector<Account *> &accounts, double amount);

#endif