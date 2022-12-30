#include "Accounts_Utiliti.h"

void display(const vector<Account*> &accounts) {
    cout << "\n=================ACCOUNTS=================" << endl;
    for(const auto account : accounts)
        cout << *account;
    cout << "==========================================" << endl;
}

void withdraw(vector<Account*> &accounts, double amount) {
    cout << "\n=================WITHDRAW_ACCOUNTS=================" << endl;
    for(auto account : accounts) {
        if(account->withdraw(amount))
            cout << "Witdraw [" << amount << "] from " << *account;
        else
            cout << "FAILLED Witdraw [" << amount << "] from " << *account;
    }
    cout << "=====================================================" << endl;
}

void deposit(vector<Account*> &accounts, double amount) {
    cout << "\n=================DEPOSIT_ACCOUNTS=================" << endl;  
    for(auto account : accounts) {
        if(account->deposit(amount))
            cout << "Deposit [" << amount << "] from " << *account;
        else
            cout << "FAILLED Deposit [" << amount << "] from " << *account;
    }
    cout << "====================================================" << endl;
}