#include <iostream>
using namespace std;

int get_max(int a1, int a2)
{
    if(a1 >= a2)
        return a1;
    else if(a2 >= a1)
        return a2;
}

int SubSequence(int a[], int n1, int b[], int n2)
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
    int lcs1, lcs2, lcs3;
    lcs1 = SubSequence(a, n1, b, n2);
    lcs2 = SubSequence(b, n2, c, n3);
    lcs3 = SubSequence(a, n1, c, n3);
    if(lcs1 <= lcs2 && lcs1 <= lcs3)
        cout << lcs1 << endl;
    else if(lcs2 <= lcs1 && lcs2 <= lcs3)
        cout << lcs2 << endl;
    else
        cout << lcs3 << endl;
}
