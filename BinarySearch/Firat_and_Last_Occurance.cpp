#include <bits/stdc++.h>
using namespace std;
int first(int a[], int n, int k)
{
    int start = 0, end = n - 1, ans = -1;
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
    int start = 0, end = n - 1, ans = -1;
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

vector<int> find(int arr[], int n, int x)
{
    vector<int> ans;
    ans.push_back(first(arr, n, x));
    ans.push_back(last(arr, n, x));
    return ans;
}