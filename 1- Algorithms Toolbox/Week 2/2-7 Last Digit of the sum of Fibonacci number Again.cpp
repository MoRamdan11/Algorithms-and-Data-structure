#include <iostream>
using namespace std;

long long last_digit_sum(long long n, long long m)
{
    long long x[10000];
    x[0] = 0;
    x[1] = 1;
    long long sum = 0;
    int count =2;
    for(int i = 2; i < 10000; i++)
    {
        x[i] = (x[i-1] + x[i-2]) % 10;
        if(x[i] >= 10)
            x[i] -= 10;
        if(x[i] == 1 && x[i-1] == 0)
        {
            count --;
            break;
        }
        count ++;
    }
    int m_it = m % count;
    int n_it = n % count;
    if(m_it > n_it)
    {
        for(int i = m_it; i <= count; i++)
            sum += x[i];
        for(int i = 0; i <= n_it; i++)
            sum += x[i];
    }
    else
    {
        for(int i = m % count; i <= n % count; i++)
        {
            sum += x[i];
        }
    }
    return sum % 10;
}

int main()
{
    long long n, m;
    cin >> m >> n;
    cout << last_digit_sum(n, m) << endl;
}
