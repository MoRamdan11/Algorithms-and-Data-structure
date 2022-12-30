#include "Account_utiliti.h"

void display(std::vector<std::shared_ptr<Account>> accounts) {
  cout << "====================ACCOUNTS====================" << endl;
  for(auto const &account : accounts)
    std::cout << *account;
  cout << "================================================" << endl;
}

void withdraw(std::vector<std::shared_ptr<Account>> accounts, double amount) {
  cout << "====================WITHDRAWING====================" << endl;
  for(auto &account : accounts) {
    try {
      account->withdraw(amount);
      cout << "Withdraw [" << amount << "] from " << *account;
    } catch(const IllegalSufficientFund &ex) {
      cout << "Withdraw Failed => " << ex.what() << endl;
    } catch(const MaxNumberOfWithdrwals &ex) {
      cout << "Withdraw Failed => " << ex.what() << endl;
    } 
  }
  cout << "===================================================" << endl;
}

void deposit(std::vector<std::shared_ptr<Account>> accounts, double amount) {
  cout << "====================DEPOSITING====================" << endl;
  for(auto &account : accounts) {
    try {
      account->deposit(amount);
      cout << "Withdraw [" << amount << "] to " << *account;
    } catch(const IllegalSufficientFund &ex) {
      cout << "Deposit Failed => " << ex.what() << endl;
    } catch(const MaxNumberOfWithdrwals &ex) {
      cout << "Deposit Failed => " << ex.what() << endl;
    } 
  }
  cout << "===================================================" << endl;
}