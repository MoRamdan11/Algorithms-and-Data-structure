#include <iostream>
using namespace std;

int partion(int a[], int l, int r, int *m1, int *m2)
{
    int j = l;
    int x = a[l];
    for(int i = l + 1; i <= r; i++)
    {
        if(a[i] < x)
            swap(a[i], a[++j]);
    }
    swap(a[j], a[l]);
    (*m1) = j;
    (*m2) = j;
    for(int i = l; i < j; i++)
    {
        if(a[i] == a[j])
            (*m1) -= 1;
    }
}

void quicksort(int a[], int l, int r)
{
    if(l >= r)
        return;
    int index = l + rand() % (r - l);
    swap(a[l], a[index]);
    int m1, m2;
    partion(a, l, r, &m1, &m2);
    quicksort(a, l, m1 - 1);
    quicksort(a, m2 + 1, r);
}

int main()
{
    int n;
    cin >> n;
    int x[n];
    for(int i = 0; i < n; i++)
        cin >> x[i];
    quicksort(x, 0, n - 1);
    for(int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << "\n";
}
