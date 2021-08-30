#include <iostream>
using namespace std;

long long least_multiple(long long a, long long b)
{
    long long max = (a > b) ? a : b;
    int i =1;
    while((max * i) % a != 0 || (max * i) % b != 0)
    {
        i++;
    }
    return max * i;
}

long long Rec(long long a, long long b, long long n)
{
    if((n * a) % b == 0)
        return n * a;
    return Rec( a, b, n+1);
}

int main()
{
    long long a, b;
    cin >> a;
    cin >> b;
    cout << least_multiple(a, b) << endl;
}
