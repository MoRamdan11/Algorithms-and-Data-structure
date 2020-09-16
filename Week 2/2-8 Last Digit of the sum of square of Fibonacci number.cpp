#include <iostream>
using namespace std;

long long Last_digit_square_fibonacci(long long n)
{
    long long x[10000];
    x[0] = 0;
    x[1] = 1;
    long long sum = 0;
    int count = 2;
    for(int i = 2; i < 10000; i++)
    {
        x[i] = (x[i-1] + x[i-2]) % 10;
        if(x[i] >= 10)
            x[i] -= 10;
        if(x[i] ==1 && x[i-1] == 0)
        {
            count --;
            break;
        }
        count ++;
    }
    for(int i = 0; i <= n % count; i++)
    {
        sum += x[i] * x[i];
    }
    return sum % 10;
}

int main()
{
    long long n;
    cin >> n;
    cout << Last_digit_square_fibonacci(n) << endl;
}
