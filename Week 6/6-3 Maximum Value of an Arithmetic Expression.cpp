#include <iostream>
#include <string>
#include <climits>
using namespace std;

long long getMax(long long a, long long b, long long c, long long d, long long e)
{
    if(a >= b && a >= c && a >= d && a >= e)
        return a;
    else if(b >= a && b >= c && b >= d && b >= e)
        return b;
    else if(c >= a && c >= b && c >= d && c >= e)
        return c;
    else if(d >= a && d >= b && d >= c && d >= e)
        return d;
    else
        return e;
}

long long getmin(long long a, long long b, long long c, long long d, long long e)
{
    if(a <= b && a <= c && a <= d && a <= e)
        return a;
    else if(b <= a && b <= c && b <= d && b <= e)
        return b;
    else if(c <= a && c <= b && c <= d && c <= e)
        return c;
    else if(d <= a && d <= b && d <= c && d <= e)
        return d;
    else
        return e;
}
long long calc(long long a, long long b, char op)
{
    if(op == '+')
        return a + b;
    else if(op == '-')
        return a - b;
    else if(op == '*')
        return a * b;
}

void parthess(long long d[], int n, char op[])
{
    long long M[n][n];
    long long m[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            M[i][j] = 0;
            m[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++)//make the diagonal
    {
        M[i][i] = d[i];
        m[i][i] = d[i];
    }
    long long a, b, c, e;
    long long mini = LONG_LONG_MAX;
    long long maxi = LONG_LONG_MIN;
    int i, j;
    for(int index = 1; index < n; index++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(j - i != index)
                    continue;
                for(int k = i; k < j; k++)
                {
                    a = calc(M[i][k], M[k+1][j], op[k]);
                    b = calc(m[i][k], m[k+1][j], op[k]);
                    c = calc(M[i][k], m[k+1][j], op[k]);
                    e = calc(m[i][k], M[k+1][j], op[k]);
                    mini = getmin(a, b, c, e, mini);
                    maxi = getMax(a, b, c, e, maxi);
                }
                M[i][j] = maxi;
                m[i][j] = mini;
                mini = LONG_LONG_MAX;
                maxi = LONG_LONG_MIN;

            }
        }
    }
    cout << M[0][n-1] << endl;
}

int main()
{
    string m;
    cin >> m;
    int n;
    if(m.length() % 2 == 0)
        n = m.length() / 2;
    else
        n = (m.length() / 2) + 1;
    long long d[n];
    char op[n - 1];
    for(int i = 0, j = 0, k = 0; i < m.length();)
    {
        d[j++] = m[i++] - '0';
        if(k != m.length() - 1)
            op[k++] = m[i++];
    }
    parthess(d, n, op);
}
