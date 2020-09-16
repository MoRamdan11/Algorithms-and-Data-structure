#include <iostream>
using namespace std;

int get_max(int a1, int a2, int a3)
{
    if(a1 >= a2 && a1 >= a3)
        return a1;
    else if(a2 >= a1 && a2 >= a3)
        return a2;
    return a3;
}

int sequence(int a[], int n1, int b[], int n2, int c[], int n3)
{
    int d[n1 + 1][n2 + 1][n3 + 1];
    for(int i = 0; i <= n1; i++)
    {
        for(int j = 0; j <= n2; j++)
        {
            for(int k = 0; k <= n3; k++)
                d[i][j][k] = 0;
        }
    }
    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            for(int k = 1; k <= n3; k++)
            {
                if(a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                    d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
                else
                    d[i][j][k] = get_max(d[i - 1][j][k], d[i][j][k-1], d[i][j-1][k]);
            }
        }
    }
    return d[n1][n2][n3];
}

int main()
{
    int n1, n2, n3;
    cin >> n1;
    int a[n1];
    for(int  i = 0; i < n1; i++)
        cin >> a[i];
    cin >> n2;
    int b[n2];
    for(int j = 0; j < n2; j++)
        cin >> b[j];
    cin >> n3;
    int c[n3];
    for(int i = 0; i < n3; i++)
        cin >> c[i];
    cout << sequence(a, n1, b, n2, c, n3);
}
