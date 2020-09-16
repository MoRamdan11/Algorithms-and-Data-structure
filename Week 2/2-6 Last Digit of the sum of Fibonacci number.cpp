#include <iostream>
using namespace std;

long long sum_last_digit(long long n)
{
    long long x[10000];
    long long count = 2;
    long long sum = 0;
    x[0] = 0;
    x[1] = 1;
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
    long long len = n % count;
    for(int i = 0; i <= len; i++)
        sum += x[i];
    return sum % 10;
}

int main()
{
    long long n;
    cin >> n;
    cout << sum_last_digit(n) << endl;
}
