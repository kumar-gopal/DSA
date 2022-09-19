#include <bits/stdc++.h>
using namespace std;
int up1(int a[], int n, int x)
{
    int ans = upper_bound(a + 0, a + n, x) - a;
    return ans;
}
int up2(int a[], int n, int x)
{
    int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x)
            low = mid + 1;
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int x;
    cin >> x;
    cout << a[up1(a, n, x)] << " " << up1(a, n, x) << endl;
    cout << a[up2(a, n, x)] << " " << up2(a, n, x);
}