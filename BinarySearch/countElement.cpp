#include <bits/stdc++.h>
using namespace std;
int first(int a[], int n, int k)
{
    int start = 0, end = n - 1, ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == k)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (a[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}
int last(int a[], int n, int k)
{
    int start = 0, end = n - 1, ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == k)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (a[mid] > k)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}

int count(int arr[], int n, int x)
{
    int a = first(arr, n, x);
    int b = last(arr, n, x);
    if (a == 0 && b == 0)
        return 0;
    return (b - a) + 1;
}
int main()
{
    int N = 4, X = 3;
    int arr[] = {1, 2, 4, 4};
    cout << count(arr, N, X);
}