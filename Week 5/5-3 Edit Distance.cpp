#include <iostream>
#include <string>
using namespace std;

int EditDistance(string str1, string str2, int m, int n)
{
    int d[m + 1][n + 1];
    for(int i = 0; i <= m; i++)
        d[i][0] = i;
    for(int j = 0; j <= n; j++)
        d[0][j] = j;
    int insert, deletion, subs;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                d[i][j] = d[i - 1][j - 1];
                continue;
            }
            insert = d[i - 1][j] + 1;
            deletion = d[i][j - 1] + 1;
            subs = d[i - 1][j - 1] + 1;
            if(insert <= deletion && insert <= subs)
                d[i][j] = insert;
            else if(deletion <= insert && deletion <= subs)
                d[i][j] = deletion;
            else
                d[i][j] = subs;
        }
    }
    return d[m][n];
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int m = str1.length();
    int n = str2.length();
    cout << EditDistance(str1, str2, m, n);
}
