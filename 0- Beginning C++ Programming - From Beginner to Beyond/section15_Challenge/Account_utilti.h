#ifndef _ACCOUNT_UTLITI
#define _ACCOUNT_UTLITI
#include "Account.h"
#include "Saving_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include <vector>
using std::vector;
//Account
void display(const vector<Account> &accounts);
void deposit(vector<Account> &accounts, int amount);
void withdraw(vector<Account> &accounts, int amount);
//Saving_Account
void display(const vector<Saving_Account> &saving_accounts);
void deposit(vector<Saving_Account> &saving_accounts, int amount);
void withdraw(vector<Saving_Account> &saving_accounts, int amount);
//Checking_Account
void display(const vector<Checking_Account> &checking_accounts);
void deposit(vector<Checking_Account> &checking_accounts, int amount);
void withdraw(vector<Checking_Account> &checking_accounts, int amount);
//Checking_Account
void display(const vector<Trust_Account> &trust_accounts);
void deposit(vector<Trust_Account> &trust_accounts, int amount);
void withdraw(vector<Trust_Account> &trust_accounts, int amount);
#endif