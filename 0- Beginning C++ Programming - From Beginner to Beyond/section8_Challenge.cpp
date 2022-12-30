// Section 8: Statements and Operators
// Challenge
#include <iostream>
using namespace std;

int main() {
  const int cents_per_dollar{100};
  const int cents_per_quarter{25};
  const int cents_per_dime = {10};
  const int cents_per_nickel = {5};
  const int cents_per_penny = {1};
  cout << "Enter an amount in cents: ";
  int balance {}, dollars{}, quarters{}, dimes{}, nickels{}, pennys{};
  cin >> balance;
  dollars = balance / cents_per_dollar;
  balance %= cents_per_dollar;
  quarters = balance / cents_per_quarter;
  balance %= cents_per_quarter;
  dimes = balance / cents_per_dime;
  balance %= cents_per_dime;
  nickels = balance / cents_per_nickel;
  balance %= cents_per_nickel;
  pennys = balance / cents_per_penny;
  balance %= cents_per_penny;
  cout << "dollars: " << dollars << endl;
  cout << "quarters: " << quarters << endl;
  cout << "dimes: " << dimes << endl;
  cout << "nickels: " << nickels << endl;
  cout << "pennys: " << pennys << endl;
  cout << "pennys: " << balance << endl;
  return 0;
}
