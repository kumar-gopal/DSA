#include <bits/stdc++.h>
using namespace std;
int lb1(int a[], int n, int x)
{
    int ans = lower_bound(a + 0, a + n, x) - a;
    return ans;
}
int lb2(int a[], int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    int a[] = {1, 3, 5, 7, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int x;
    cin >> x;
    cout << a[lb1(a, n, x)] << " " << lb1(a, n, x) << endl;
    cout << lb2(a, n, x);
}