#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, int n, vector<int> w)
{
    vector<vector<int> > d(n + 1, vector<int> (W + 1));
    for(int i = 0; i <= n; i++)
        d[i][0] = 0;
    for(int j = 0; j <= W; j++)
        d[0][j] = 0;
    int val;
    for(int j = 1; j <= W; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            d[i][j] = d[i - 1][j];
            if(w[i - 1] <= j)
            {
                val = d[i - 1][j - w[i - 1]] + w[i - 1];
                if(d[i][j] < val)
                    d[i][j] = val;
            }
        }
    }
    return d[n][W];
}

int main()
{
    int W, n;
    cin >> W >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++)
        cin >> w[i];
    cout << knapsack(W, n, w);
}
