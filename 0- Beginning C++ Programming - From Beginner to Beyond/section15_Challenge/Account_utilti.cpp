#include "Account_utilti.h"
#include <iostream>
using std::cout;
using std::endl;

//Account
void display(const vector<Account> &accounts) {
  cout << "\n=======================ACCOUNTS=======================" << endl;
  for(const auto &account : accounts)
    cout << account;
  cout << "=======================================================" << endl;
}
void deposit(vector<Account> &accounts, int amount) {
  cout << "\n=======================DEPOSIT FOR ACCOUNTS=======================" << endl;
  for(auto &account : accounts) {
    if(account.deposit(amount))
      cout << "Successfull Deposit[" << amount << "] for " << account;
    else
      cout << "Failed Deposit[" << amount << "] for " << account;
  }
  cout << "==================================================================" << endl;
}
void withdraw(vector<Account> &accounts, int amount) {
  cout << "\n=======================WITHDRAW FOR ACCOUNTS=======================" << endl;
  for(auto &account : accounts) {
    if(account.withdraw(amount))
      cout << "Successfull Withdraw[" << amount << "] for " << account;
    else
      cout << "Failed Withdraw[" << amount << "] for " << account;
  }
  cout << "====================================================================" << endl;
}
//Saving_Account
void display(const vector<Saving_Account> &saving_accounts) {
  cout << "\n=======================SAVING_ACCOUNTS=======================" << endl;
  for(const auto &saving_account : saving_accounts)
    cout << saving_account;
  cout << "=============================================================" << endl;
}
void deposit(vector<Saving_Account> &saving_accounts, int amount) {
  cout << "\n=======================DEPOSIT FOR SAVING_ACCOUNTS=======================" << endl;
  for(auto &saving_account : saving_accounts) {
    if(saving_account.deposit(amount))
      cout << "Successfull Deposit[" << amount << "] for " << saving_account;
    else
      cout << "Failed Deposit[" << amount << "] for " << saving_account;
  }
  cout << "=========================================================================" << endl;
}
void withdraw(vector<Saving_Account> &saving_accounts, int amount) {
  cout << "\n=======================WITHDRAW FOR SAVING_ACCOUNTS=======================" << endl;
  for(auto &saving_account : saving_accounts) {
    if(saving_account.withdraw(amount))
      cout << "Successfull Withdraw[" << amount << "] for " << saving_account;
    else
      cout << "Failed Withdraw[" << amount << "] for " << saving_account;
  }
  cout << "============================================================================" << endl;
}
//Checking_Account
void display(const vector<Checking_Account> &checking_accounts) {
  cout << "\n=======================CHECKING_ACCOUNTS=======================" << endl;
  for(const auto &checking_account : checking_accounts)
    cout << checking_account;
  cout << "\n===============================================================" << endl;
}
void deposit(vector<Checking_Account> &checking_accounts, int amount) {
  cout << "\n=======================DEPOSIT FOR CHECKING_ACCOUNTS=======================" << endl;
  for(auto &checking_account : checking_accounts) {
    if(checking_account.deposit(amount))
      cout << "Successfull Deposit[" << amount << "] for " << checking_account;
    else
      cout << "Failed Deposit [" << amount << "] for " << checking_account;
  }
  cout << "\n===========================================================================" << endl;
}
void withdraw(vector<Checking_Account> &checking_accounts, int amount) {
  cout << "\n=======================WITHDRAW FOR CHECKING_ACCOUNTS=======================" << endl;
  for(auto &checking_account : checking_accounts) {
    if(checking_account.withdraw(amount))
      cout << "Successfull Withdraw[" << amount << "] for " << checking_account;
    else
      cout << "Failed Withdraw [" << amount << "] for " << checking_account;
  }
  cout << "\n============================================================================" << endl;
}
//Checking_Account
void display(const vector<Trust_Account> &trust_accounts) {
  cout << "\n=======================TRUST_ACCOUNTS=======================" << endl;
  for(const auto &trust_account : trust_accounts)
    cout << trust_account;
  cout << "\n============================================================" << endl;
}
void deposit(vector<Trust_Account> &trust_accounts, int amount) {
  cout << "\n=======================DEPOSIT FOR TRUST_ACCOUNTS=======================" << endl;
  for(auto &trust_account : trust_accounts) {
    if(trust_account.deposit(amount))
      cout << "Successfull Deposit[" << amount << "] for " << trust_account;
    else
      cout << "Failed Deposit [" << amount << "] for " << trust_account;
  }
  cout << "\n========================================================================" << endl;
}
void withdraw(vector<Trust_Account> &trust_accounts, int amount) {
  cout << "\n=======================WITHDRAW FOR TRUST_ACCOUNTS=======================" << endl;
  for(auto &trust_account : trust_accounts) {
    if(trust_account.withdraw(amount))
      cout << "Successfull Withdraw[" << amount << "] for " << trust_account;
    else
      cout << "Failed Withdraw [" << amount << "] for " << trust_account;
  }
  cout << "\n==========================================================================" << endl;
}