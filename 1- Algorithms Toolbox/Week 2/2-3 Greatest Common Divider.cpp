#include <iostream>
using namespace std;

long long GCD_Rec(long long a, long long b)
{
    long long rem = a % b;
    if(rem == 0)
        return b;
    return GCD_Rec(b, rem);
}

int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    cout << GCD_Rec(a, b) << endl;
}
