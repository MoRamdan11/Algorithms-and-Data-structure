#include <iostream>
using namespace std;

int mini_coins(int m)
{
    int count = 0;
    while(m >= 10)
    {
        m -= 10;
        count++;
    }
    while(m >= 5 && m < 10)
    {
        m -= 5;
        count++;
    }
    while(m >= 1 && m < 5)
    {
        m -= 1;
        count++;
    }
    return count;
}

int main()
{
    int m;
    cin >> m; 
    cout << mini_coins(m) << endl;
}
