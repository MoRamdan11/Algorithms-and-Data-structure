#include <iostream>
using namespace std;

int final_digit(int n)
{
    int x[n];
    x[0] = 0;
    x[1] = 1;
    for(int i = 2; i <=n; i++)
    {
        if((x[i-1] % 10) + (x[i-2] % 10) < 10)
            x[i] = (x[i-1] % 10) + (x[i-2] % 10);
        else
            x[i] = (x[i-1] % 10) + (x[i-2] % 10) - 10;
    }
    return x[n];
}

int main()
{
    int n;
    cin >> n;
    cout << final_digit(n) << endl;
}
