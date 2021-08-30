#include <iostream>
using namespace std;

long long module_new(long long n, long long m)
{
    long long x[10000];
    int count = 2;
    x[0] = 0;
    x[1] = 1;
    for(int i = 2; i < 10000; i++)
    {
        x[i] = (x[i-1] + x[i-2]) % m;
        if(x[i] == 1 && x[i-1] == 0)
        {
            count --;
            break;
        }
        count ++;
    } 
    return x[n % count] ;
}

int main()
{
    long long n, m;
    cin >> n;
    cin >> m;
    cout << module_new(n, m) << endl;
}
