#include <iostream>
using namespace std;

int get_max(int a1, int a2)
{
    if(a1 >= a2)
        return a1;
    else if(a2 >= a1)
        return a2;
}

int SubSequence(int a[], int n1, int b[], int n2, int rep1[], int rep2[])
{
    int d[n1 + 1][n2 + 1];
    for(int i = 0; i <= n1; i++)
        d[i][0] = 0;
    for(int j = 0; j <= n2; j++)
        d[0][j] = 0;
    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            int maxi = get_max(d[i - 1][j], d[i][j - 1]);
            if(a[i - 1] == b[j - 1])
            {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else
                d[i][j] = maxi;
        }
    }
    return d[n1][n2];
}

int main()
{
    int n1, n2;
    cin >> n1;
    int a[n1];
    int rep1[n1];
    for(int  i = 0; i < n1; i++)
    {
        rep1[i] = 0;
        cin >> a[i];
        for(int m = 0; m < i; m++)
            if(a[i] == a[m])
                rep1[i] ++;
    }
    cin >> n2;
    int b[n2];
    int rep2[n2];
    for(int j = 0; j < n2; j++)
    {
        rep2[j] = 0;
        cin >> b[j];
        for(int m = 0; m < j; m++)
            if(b[j] == b[m])
                rep2[j] ++;
    }
    cout << SubSequence(a, n1, b, n2, rep1, rep2);
}
