#include <iostream>
#include <algorithm>
using namespace std;

long long max_advs(int n, long long a[], long long b[])
{
    long long res = 0;
    for(int i = 0; i < n; i ++)
    {
        res += a[i] * b[i];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    long long a[n];
    long long b[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    cout << max_advs(n, a, b) << endl; 
}
