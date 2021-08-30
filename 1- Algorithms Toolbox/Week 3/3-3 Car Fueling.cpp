#include <iostream>
using namespace std;

int num_refills(int d, int m, int n, int x[])
{
    int num_refills = 0;
    int current_refill = 0;
    int last_refill = 0;
    while(current_refill <= n)
    {
        last_refill = current_refill;
        while(current_refill <= n && x[current_refill + 1] - x[last_refill] <= m)
        {
            current_refill ++;
        }
        if(current_refill == last_refill)
            return -1;
        if(current_refill <= n)
        {
            num_refills ++;
        }
    }
    return num_refills;
}

int main()
{
    int d, m ,n;
    cin >> d;
    cin >> m ;
    cin >> n;
    int x[n + 2];
    x[0] = 0;
    x[n + 1] = d; 
    for(int i = 1; i < n + 1; i++)
        cin >> x[i];
    cout << num_refills(d, m, n , x) << endl;
}
