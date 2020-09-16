#include <iostream>
#include <vector>
using namespace std;

void min_op(int n, vector <int> x)
{
    int d[n + 1];
    d[0] = 0;
    d[1] = 0;
    for(int i = 2; i <= n; i++)
        d[i] = n + 1;
    for(int i = 2; i <= n; i++)
    {
        if(d[i - 1] < d[i])
            d[i] = d[i - 1] + 1;
        if(i % 2 == 0 && d[i / 2] < d[i])
            d[i] = d[i / 2] + 1;
        if(i % 3 == 0 && d[i / 3] < d[i])
            d[i] = d[i / 3] + 1;
    }
    cout << d[n] << endl;
    for(int i = n; i >= 1;)
    {
        x.push_back(i);
        if(i % 3 == 0)
            i /= 3;
        else if(i % 2 == 0)
            i /= 2;
        else
            i -= 1;
    }
    for(int i = x.size() - 1; i >= 0; i--)
        cout << x[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    vector <int> x(0);
    min_op(n, x);
}
