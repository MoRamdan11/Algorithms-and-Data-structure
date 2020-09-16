#include <iostream>
#include <iomanip>
using namespace std;

void Knapsack(int W, int n, int w[], int v[], double v_w[])
{
    double res = 0;
    int max_index = 0;
    double max_v_w = 0;
    int count = 0;
    while(W > 0 && count < n)
    {
        for(int i = 0; i < n; i++)
        {
            if(max_v_w < v_w[i])
            {
                max_v_w = v_w[i];
                max_index = i;
            }
        }
        max_v_w = 0;
        if(W <= w[max_index])
        {
            res += W * v_w[max_index];
            W = 0;
        }
        else
        {
            res += v[max_index];
            W -= w[max_index];
            w[max_index] = 0;
            v[max_index] = 0;
            v_w[max_index] = 0;
            count++;
        }
    }
    cout << setprecision(10) << res;
}

int main()
{
    int W, n;
    cin >> n >> W;
    int w[n];
    int v[n];
    double v_w[n];
    for(int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
        v_w[i] = (double)v[i] / w[i];
    }
    Knapsack(W, n, w, v, v_w);
}
