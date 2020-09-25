#include <iostream>
#include <vector>
using namespace std;

void max_prizes(long long n)
{
    vector <long long> v(0);
    long long sum = 0;
    int index = 0;
    int count = 0;
    for(int i = 1; i <= n && sum <= n; i++)
    {
        if(sum + i <= n && ((n - (sum + i) > i) || (sum + i == n) ))
        {
            sum += i;
            v.push_back(i);
            //v[index++] = i;
            count++;
        }
    }
    cout << count << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}

int main()
{
    long long n;
    cin >> n;
    max_prizes(n);
}
