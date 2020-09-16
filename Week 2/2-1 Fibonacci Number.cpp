#include <iostream>
using namespace std;

int Fibonacci_fast(int n)
{
    int x[n];
    x[0] = 0;
    x[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        x[i] = x[i-1] + x[i-2];
    }
    return x[n];
}

int main()
{
    int n;
    cin >> n;
    cout << Fibonacci_fast(n) << endl;
}
