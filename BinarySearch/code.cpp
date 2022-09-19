#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int s = 0;
        sort(a, a + n);

        for (int i = 0; i < n; i++)
        {
            int m1 = abs(a[i] - m);
            int m2 = abs(a[i] - 1);
            if (m1 > m2)
                s = s + m1;
            else
                s = s + m2;
        }

        cout << s<< endl;
    }
    return 0;
}
