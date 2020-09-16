#include <iostream>
using namespace std;

int binarysearch(int a[], int e, int l, int r)
{
    if(l > r)
        return -1;
    if(r == l)
    {
        if(a[l] == e)
            return l;
        else
            return -1;
    }
    int mid = (l + r) / 2;
    if(a[mid] == e)
        return mid;
    if(e < a[mid])
        return binarysearch(a, e, l, mid - 1);
    return binarysearch(a, e, mid + 1, r);
}
int main()
{
    int n, k;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    cin >> k;
    int e[k];
    for(int i = 0; i < k; i++)
        cin >> e[i];
    for(int i = 0; i < k; i++)
    {
        cout << binarysearch(x, e[i], 0, n - 1) << endl;
    }
}
