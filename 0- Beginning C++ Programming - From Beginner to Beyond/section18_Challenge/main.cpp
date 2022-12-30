// Section 18: Exception Handling
// Challenge
#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Saving_Account.h"
#include "Trust_Account.h"
#include "Account_utiliti.h"

using namespace std;

int main() {
    std::unique_ptr<Account> moes_account;
    std::unique_ptr<Account> larrys_account;
    try {
        larrys_account = std::make_unique<Saving_Account>("Larry", -2000.0);
        std::cout << *larrys_account << std::endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }

    try {
        moes_account = std::make_unique<Saving_Account>("Moe", 1000.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(500.0);
        std::cout << *moes_account << std::endl;
        moes_account->withdraw(1000.0);
        std::cout << *moes_account << std::endl;
        
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch (const IllegalSufficientFund &ex) {
        std::cerr << ex.what() << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    while(true);
    return 0;
}

