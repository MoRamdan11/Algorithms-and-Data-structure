#include <iostream>
using namespace std;

int DPChange(int amount, int coins[], int n)
{
    int d[amount + 1];
    for(int i = 0; i <= amount; i++)
        d[i] = amount + 1;
    d[0] = 0;
    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i >= coins[j])
            {
                if(d[i - coins[j]] + 1 < d[i])
                    d[i] = d[i - coins[j]] + 1;
            }
            else
                break;
        }
    }
    return d[amount];
}

int main()
{
    int amount;
    cin >> amount;
    int coins[3]{1, 3, 4};
    cout << DPChange(amount, coins, 3);
}
