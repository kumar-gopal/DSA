#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int check1 = 0;
        int check2 = 0;
        vector<int> p;
        vector<int> n1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] >= 0)
            {
                p.push_back(a[i]);
                check1 = 1;
            }
            else
            {
                n1.push_back(a[i]);
                check2 = 1;
            }
        }
        sort(p.begin(), p.end());
        sort(n1.begin(), n1.end());

        int min1, min2, max1, max2;
        if (check1 == 1 && check2 == 1)
        {
            min1 = min((n1[n1.size() - 1] * n1[n1.size() - 1]), p[0] * p[0]);
            max1 = max((n1[0] * n1[0]), p[p.size() - 1] * p[p.size() - 1]);
            cout << min1 << " " << max1 << endl;
        }
        else if (check1 == 1 && check2 == 0)
        {
            cout << p[0] * p[0] << " " << p[p.size() - 1] * p[p.size() - 1] << endl;
        }
        else
        {
            cout << n1[n1.size() - 1] * n1[n1.size() - 1] << " " << n1[0] * n1[0] << endl;
        }
    }
    return 0;
}
