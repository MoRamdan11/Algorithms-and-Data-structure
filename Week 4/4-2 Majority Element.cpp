#include <iostream>
using namespace std;

void mergee(int a[], int n1, int b[], int n2, int sorted_arr[])
{
    int index1 = 0;
    int index2 = 0;
    int index = 0;
    while(index1 != n1 && index2 != n2)
    {
        if(a[index1] < b[index2])
            sorted_arr[index++] = a[index1++];
        else
            sorted_arr[index++] = b[index2++];
    }
    if(index1 != n1)
    {
        while(index1 != n1)
            sorted_arr[index++] = a[index1++];
    }
    else
    {
        while(index2 != n2)
            sorted_arr[index++] = b[index2++];
    }
}

void mergesort(int a[], int n ,int sorted_arr[])
{
    if(n == 1)
    {
        sorted_arr[0] = a[0];
        return;
    }
    int l_size = n / 2;
    int r_size = n - l_size;
    int *l_arr = new int[l_size];
    int *r_arr = new int[r_size];
    int *l_sort_arr = new int[l_size];
    int *r_sort_arr = new int[r_size];
    int i;
    for(i = 0; i < l_size; i++)
        l_arr[i] = a[i];
    for(int j = 0; i < n; j++, i++)
        r_arr[j] = a[i];
    mergesort(l_arr, l_size, l_sort_arr);
    mergesort(r_arr, r_size, r_sort_arr);
    mergee(l_sort_arr, l_size, r_sort_arr, r_size, sorted_arr);
    delete []l_arr;
    delete []r_arr;
    delete []l_sort_arr;
    delete []r_sort_arr;
}

int majelements(int a[], int n)
{
    int count = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] == a[i - 1])
            count ++;
        else
            count = 1;
        if(count > n / 2)
            return 1;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    int x[n];
    for(int i =0; i < n; i++)
        cin >> x[i];
    int sorted_arr[n];
    mergesort(x, n, sorted_arr);
    cout << majelements(sorted_arr, n) << endl;
}
